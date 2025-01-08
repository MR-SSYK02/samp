#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the value "<<endl;
    cin>>a>>b;
    try

    {
        if(b==0)
            throw b=10;
        c=a/b;
        cout<<"return:"<<endl;
    }
    catch(int e)
    {
        cout<<"Its not divide"<<endl;
    }
return 0;
}
