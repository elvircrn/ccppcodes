#include <iostream>
#include <cstdio>

#define MaxN 100005
#define MOD 1000000007
using namespace std;


long long power( long long a, int b)
{
    if( !b) return 1;
    if( b &1) return ((a%MOD)*power(a,b-1))%MOD;
    else return power( (a*a)%MOD, b/2);
}

long long n, q, a[MaxN], product=1, ind, x, mod_inverse;

int main()
{
    scanf("%lld %lld", &n, &q);

    for( int i=1; i<=n; ++i)
    {
        scanf("%lld", &a[i]);
        product= (product*a[i])%MOD;
    }
    for( int i=0; i<q; ++i)
    {

        scanf("%lld %lld", &ind, &x);

        mod_inverse= power( a[ind], MOD-2);
        product= (x*(product%MOD*mod_inverse%MOD)%MOD)%MOD;
        a[ind]= x;
        printf("%lld\n", product);
    }
    return 0;
}
