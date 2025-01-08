#include<iostream>
using namespace std;
class car
{
   public:
       void start()
    {
        cout<<"car start"<<endl;
    }
};
class bmw:public car
{
public:
    void start()
    {
        cout<<"advance gear"<<endl;
    }
};
int main()
{
    bmw o;
    car *p=&o;
    p->start();
    return 0;
}
