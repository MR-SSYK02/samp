#include <iostream>
using namespace std;
class student
{
private:
    string name;
    int age;

public:
    void getdata()
    {
    cout<<"name"<<name<<endl;
    cout<<"age"<<age<<endl;
    name="abcd";
    age=30;
    }
    void display()
    {
    cout<<"name"<<name<<endl;
    cout<<"age"<<age<<endl;

    }
};
int main()
{
    student o;

    o.getdata();
    o.display();
    return 0;
}
