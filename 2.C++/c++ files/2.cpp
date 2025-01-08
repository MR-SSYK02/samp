#include<iostream>
using namespace std;
class student
{
private:
    string name;
    int age;
public:
    student(string n,int a)
    {
        name=n;
        age=a;
    }
    string getname()
    {
        return name;

    }
 void setname(string n)
    {
        name=n;
    }
    void print()
    {
        cout<<name<<endl;
        cout<<age<<endl;
    }

};
int main()
    {
        student o("senthil",20);
        o.print();
        o.setname("kishore");
        o.print();
        return 0;
    }
