#include<iostream>
using namespace std;
namespace name1
{
    string name="senthil";
    int age=20;
}
namespace name2
{
    string name="kishore";
    int age=21;
}
using namespace name1;
int main()
{
    cout<<name<<endl;
    cout<<age<<endl;

    return 0;
}


