#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c1, c2, temp;

int main()
{
    cin>>c1;
    cin>>c2;

    if( c1 == c2){ cout<<c1<<c1<<c1<<c1<<endl; return 0; }

    if( c1 > c2){ temp= c1; c1= c2; c2= temp; }

    cout<<c1<<c1<<c1<<c1<<endl;
    cout<<c1<<c1<<c1<<c2<<endl;
    cout<<c1<<c1<<c2<<c1<<endl;
    cout<<c1<<c1<<c2<<c2<<endl;
    cout<<c1<<c2<<c1<<c1<<endl;
    cout<<c1<<c2<<c1<<c2<<endl;
    cout<<c1<<c2<<c2<<c1<<endl;
    cout<<c1<<c2<<c2<<c2<<endl;
    cout<<c2<<c1<<c1<<c1<<endl;
    cout<<c2<<c1<<c1<<c2<<endl;
    cout<<c2<<c1<<c2<<c1<<endl;
    cout<<c2<<c1<<c2<<c2<<endl;
    cout<<c2<<c2<<c1<<c1<<endl;
    cout<<c2<<c2<<c1<<c2<<endl;
    cout<<c2<<c2<<c2<<c1<<endl;
    cout<<c2<<c2<<c2<<c2<<endl;

    return 0;
}
