#include<iostream>
using namespace std;
template <class T>
void swaping(T &a,T &b)

{
    T t=a;
    a=b;
    b=t;
}
int main()
{
    int a=10,b=20;
    cout<<"before swap A: "<<a<<" | B :"<<b<<endl;
    swaping(a,b);
    cout<<"after swap A: "<<a<<" | B :"<<b<<endl;
    return 0;
}


