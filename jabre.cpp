#include <cstdio>
#include <cmath>

typedef unsigned long long ll;

int main()
{
    ll a, b;
    //freopen("in.txt", "r", stdin);
    scanf("%llu %llu", &a, &b);

    ll asd, x=-1, k=-1;

    asd = sqrt(b) + 10;

    for( int i = 63; i > 0; i-- )
    {
        ll min = 2, max = 1000000000;
        while( min < max )
        {
            ll mid = ( min + max ) / 2;
            ll p = pow( mid, i );
            if( a <= p && p <= b )
            {
                //printf("%llu %d\n", mid, i);
                if( k == -1 && x == -1 )
                    x = mid, k = i;
                //if( k < i && mid != x )
                    //x = mid, k = i;
                if( k == i && x > mid )
                    x = mid;
                //x = mid, k = i;

                min = mid + 1;
            }
            else if( p >= b )
                max = mid - 1;
            else if( p <= a )
                min = mid + 1;
        }
        if( x != -1 && k != -1 )
            goto kraj;
    }
    kraj:;
    printf("%llu %llu", x, k);

    return 0;
}
