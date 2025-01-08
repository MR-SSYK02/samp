#include<iostream>
using namespace std;
int main()
{
    string a;
    cout<<"enter the string:";
    cin>>a;
    cout<<"string:"<<a;
    cout<<"enter the string:"<<endl;
    getline(cin,a);
    cout<<"string:"<<a;
    return 0;
}


