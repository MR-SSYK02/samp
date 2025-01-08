#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the values"<<endl;
    cin>>a>>b;
    try
    {
        if(b==0)
            throw b=10;
        c=a/b;
        cout<<"result : "<<c<<endl;
    }
    catch(int e)
    {
        cout<<"ITS NOT DIVIDED BY 0";
    }
    return 0;
}
