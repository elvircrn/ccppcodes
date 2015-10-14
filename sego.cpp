#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

int how, n, m;

int M[ 20 ][ 20 ];
bool bio[ 20 ][ 20 ][ ( 1 << 11 ) ];

queue< int > Q;

int px, py;
int dx[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[ 8 ] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int bfs( ) {
    Q.push( px );
    Q.push( py );
    Q.push( 0 );
    Q.push( 0 );
    while( !Q.empty( ) ) {
        int x = Q.front( ); Q.pop( );
        int y = Q.front( ); Q.pop( );
        int koraka = Q.front( ); Q.pop( );
        int mask = Q.front( ); Q.pop( );
        for( int i = 0; i < 8; i++ ) {
            int X = x + dx[ i ];
            int Y = y + dy[ i ];
            if( X < 0 || X >= 8 || Y < 0 || Y >= 8 || bio[ X ][ Y ][ mask ] ) continue;
            int f = mask;
            if( M[ X ][ Y ] ) f |= 1 << ( M[ X ][ Y ] - 1 );
            bio[ X ][ Y ][ f ] = 1;
            if( f == ( ( 1 << how ) - 1 ) ) return koraka + 1;
            Q.push( X ); Q.push( Y ); Q.push( koraka + 1 ); Q.push( f );
        }
    }
    return 0;
}



int main( void ) {
    scanf( "%d %d %d", &how, &px, &py );
    px--;
    py--;
    int cnt = 0, x, y;
    for( int i = 0; i < how; i++ ) {
        scanf( "%d %d", &x, &y );
        --x;
        --y;
        M[ x ][ y ] = ++cnt;
    }
    printf( "%d\n", bfs( ) );
   // system( "pause" );
    return 0;
}
