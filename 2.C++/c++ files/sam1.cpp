#include<iostream>
using namespace std;
int main()
{
    string firstname="yuva";
    string lastname="raj";
    //cout<<firstname+""+lastname<<endl;
    string fullname=firstname.append(lastname);
    cout<<fullname<<endl;
    return 0;
}

