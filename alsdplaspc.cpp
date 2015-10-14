#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
bool bio[ 105 ];

int M[ 105 ][ 2 ];

int maks;

int f( int x, int cnt ) {
    bio[ x ] = true;
    if( cnt > maks) maks = cnt;
    for( int i = 0; i < n; i++ ) {
        if( ( M[ i ][ 1 ] == M[ x ][ 0 ] || M[ i ][ 0 ] == M[ x ][ 0 ] || M[ i ][ 1 ] == M[ x ][ 1 ] || M[ i ][ 0 ] == M[ x ][ 1 ] ) && !bio[ i ] && i != x ) {
            f( i, cnt + 1 );
        }
    }
    bio[ x ] = false;
}


int main( void ) {
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ) scanf( "%d %d", &M[ 0 ], &M[ 1 ] );
    int sol = 0;
    f( 0, 0 );
    printf( "%d\n", maks + 1 );
    system( "Pause" );
    return 0;
}
