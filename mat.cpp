#include <iostream>
#include <cstdio>
#define MOD 10000

typedef long long ll;
using namespace std;


void one( ll a[3][3]){

    for( int i=0; i<3; ++i)
        for( int j=0; j<3; ++j)
            a[i][j]= ( i == j);
}


int main()
{
    ll T[3][3]= { 1, 1, 1, 1, 0, 0, 0, 1, 0};

    T[0][0]= 5; T[1][1]= 8;

    for( int i=0; i<3; ++i){
        for( int j=0; j<3; ++j)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }

    one( T);

    for( int i=0; i<3; ++i){
        for( int j=0; j<3; ++j)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
