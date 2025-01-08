#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

// Constants
const float INF = numeric_limits<float>::infinity();
const float EPSILON = 1e-4; // Small offset to prevent self-intersection

// Vector Class for 3D math
struct Vec3 {
    float x, y, z;

    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float scalar) const { return Vec3(x * scalar, y * scalar, z * scalar); }
    Vec3 operator/(float scalar) const { return Vec3(x / scalar, y / scalar, z / scalar); }

    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    Vec3 normalize() const {
        float length = sqrt(x * x + y * y + z * z);
        return *this / length;
    }
};

// Ray Class
struct Ray {
    Vec3 origin, direction;

    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction.normalize()) {}
};

// Material
struct Material {
    Vec3 color;
    float reflection; // Reflection coefficient (0 = no reflection, 1 = mirror)

    Material(const Vec3& color, float reflection = 0) : color(color), reflection(reflection) {}
};

// Sphere Class
struct Sphere {
    Vec3 center;
    float radius;
    Material material;

    Sphere(const Vec3& center, float radius, const Material& material)
        : center(center), radius(radius), material(material) {}

    // Ray-sphere intersection
    bool intersect(const Ray& ray, float& t) const {
        Vec3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0f * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant < 0) return false;

        // Find the nearest intersection
        float t1 = (-b - sqrt(discriminant)) / (2.0f * a);
        float t2 = (-b + sqrt(discriminant)) / (2.0f * a);
        t = (t1 > EPSILON) ? t1 : t2;

        return t > EPSILON;
    }
};

// Light
struct Light {
    Vec3 position;
    Vec3 color;

    Light(const Vec3& position, const Vec3& color) : position(position), color(color) {}
};

// Scene Class
struct Scene {
    vector<Sphere> spheres;
    vector<Light> lights;

    void addSphere(const Sphere& sphere) { spheres.push_back(sphere); }
    void addLight(const Light& light) { lights.push_back(light); }

    // Trace a ray and compute its color
    Vec3 trace(const Ray& ray, int depth = 0) const {
        if (depth > 3) return Vec3(); // Limit recursion for reflections

        float tClosest = INF;
        const Sphere* hitSphere = nullptr;

        // Find the nearest sphere intersected by the ray
        for (const auto& sphere : spheres) {
            float t;
            if (sphere.intersect(ray, t) && t < tClosest) {
                tClosest = t;
                hitSphere = &sphere;
            }
        }

        if (!hitSphere) return Vec3(0.2, 0.2, 0.2); // Background color (dark gray)

        // Compute intersection point and normal
        Vec3 hitPoint = ray.origin + ray.direction * tClosest;
        Vec3 normal = (hitPoint - hitSphere->center).normalize();

        // Compute lighting
        Vec3 color = hitSphere->material.color * 0.1f; // Ambient lighting
        for (const auto& light : lights) {
            Vec3 lightDir = (light.position - hitPoint).normalize();
            float diffuse = max(0.0f, normal.dot(lightDir));
            color = color + hitSphere->material.color * diffuse * light.color;

            // Shadow check
            Ray shadowRay(hitPoint + normal * EPSILON, lightDir);
            for (const auto& sphere : spheres) {
                float t;
                if (sphere.intersect(shadowRay, t)) {
                    color = color * 0.5f; // Dim the color if in shadow
                    break;
                }
            }
        }

        // Reflection
        if (hitSphere->material.reflection > 0) {
            Vec3 reflectDir = ray.direction - normal * 2.0f * ray.direction.dot(normal);
            Ray reflectRay(hitPoint + normal * EPSILON, reflectDir);
            Vec3 reflectColor = trace(reflectRay, depth + 1);
            color = color * (1 - hitSphere->material.reflection) + reflectColor * hitSphere->material.reflection;
        }

        return color;
    }
};

// Save image as PPM
void savePPM(const string& filename, const vector<Vec3>& pixels, int width, int height) {
    ofstream file(filename);
    file << "P3\n" << width << " " << height << "\n255\n";
    for (const auto& pixel : pixels) {
        file << static_cast<int>(min(1.0f, pixel.x) * 255) << " "
             << static_cast<int>(min(1.0f, pixel.y) * 255) << " "
             << static_cast<int>(min(1.0f, pixel.z) * 255) << "\n";
    }
    file.close();
}

int main() {
    const int width = 800;
    const int height = 600;

    Scene scene;
    scene.addSphere(Sphere(Vec3(0, 0, -5), 1, Material(Vec3(0.7, 0.2, 0.2), 0.5))); // Red sphere
    scene.addSphere(Sphere(Vec3(2, 0, -6), 1, Material(Vec3(0.2, 0.7, 0.2), 0.5))); // Green sphere
    scene.addLight(Light(Vec3(-5, 5, -3), Vec3(1, 1, 1))); // White light

    vector<Vec3> pixels(width * height);

    // Render loop
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float u = (x + 0.5f) / width * 2 - 1;
            float v = (y + 0.5f) / height * 2 - 1;
            Ray ray(Vec3(0, 0, 0), Vec3(u, v, -1));
            pixels[y * width + x] = scene.trace(ray);
        }
    }

    savePPM("output.ppm", pixels, width, height);
    cout << "Rendered image saved as output.ppm" << endl;

    return 0;
}
