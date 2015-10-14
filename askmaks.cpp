# include <iostream>
#include <cstdio>
    using namespace std;

    long long n;
    long long m;
    long long p = 0;
    long long a = 0;
    long long b = 0;

    long long gcd( long long a, long long b ){ return b == 0 ? a : gcd( b, a%b ); }

    int main()
    {
        scanf( "%lld%lld", &n, &m );

        p = ( long long )( n * m ) / 2LL;

        b += ( long long )n;
        b += ( long long )m;
        b += ( long long )gcd( n, m );

        a = p - b/2LL + 1LL;

        printf( "%lld\n", ( long long )a+b );
        return 0;
    }
