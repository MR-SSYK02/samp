#include<iostream>
using namespace std;
class stds
{
public:
    string name;
    int age;
    void display()
    {
        cout<<"name"<<name<<endl;
        cout<<"age"<<age<<endl;
    }
};
int main()
{
    stds a;
    a.name="senthil";
    a.age =20;
    a.display();
    return 0;
}
