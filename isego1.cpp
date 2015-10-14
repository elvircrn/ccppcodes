#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m;

const int MOD = 8192;

const int N = 10010;

int DP[ N ], A[ 101 ];

int main( void ) {
    scanf( "%d %d", &n, &m );
    for( int i = 0; i < m; i++ ) scanf( "%d", &A[ i ] );
    DP[ 0 ] = 1;
    int sol = 0;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            if( i - A[ j ] >= 0 ) DP[ i ] += DP[ i - A[ j ] ];
            DP[ i ] %= MOD;
        }
        sol += DP[ i ];
        sol %= MOD;
    }
    printf( "%d\n", sol );
    system( "pause" );
    return 0;
}
