#include <iostream>
#include <cstdio>
#define MOD 10000

typedef long long ll;
using namespace std;


long long a, b, c, f[3],  n, Sol;


void one( ll a[3][3]){

    for( int i=0; i<3; ++i)
        for( int j=0; j<3; ++j)
            a[i][j]= ( i == j);
}

void mul( ll a[3][3], ll b[3][3]){

    ll r[3][3]= {{0}};

    for( int i=0; i<3; ++i)
        for( int j=0; j<3; ++j)
            for( int k=0; k<3; ++k)
                r[i][j]= ( r[i][j] + a[i][k]*b[k][j])%MOD;

    for( int i=0; i<3; ++i)
        for( int j=0; j<3; ++j)
            a[i][j]= r[i][j];
}

void pow( ll a[3][3], int s){

    ll r[3][3]; one( r);

    while( s)
        if( s&1){
            mul( r, a);
            s--;
        }
        else{
            mul( a, a);
            s/=2;
        }
    one( a);
    mul( a, r);
}


int main()
{

    scanf("%d%d%d", &f[0], &f[1], &f[2]);
    scanf("%d%d%d", &c, &b, &a);
    scanf("%d", &n);

    if( n <= 3){
        printf("%d\n", f[n-1]);
        return 0;
    }

    ll T[3][3]={ a, b, c, 1, 0, 0, 0, 1, 0};

    pow( T, n-3);

    /*for (int i = 0; i < 3; i++, cout<<endl)
        for (int j = 0; j < 3; j++)
            cout<<T [i] [j]<<" ";*/

    for( int i=0; i<3; ++i)
        Sol= (Sol+T[0][i]*f[2-i])%MOD;

    printf("%d\n", Sol);

    return 0;
}
/*
1 2 3
1 2 3
17
*/
