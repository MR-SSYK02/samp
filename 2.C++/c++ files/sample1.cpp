#include<iostream>
using namespace std;
int main()
{
    string a;
    cout<<"enter the string : ";
    cin>>a;
    string::reverse_iterator el;
    for(el=a.rbegin();el!=a.rend();el++)
        cout<<*el<<endl;
    return 0;
}
