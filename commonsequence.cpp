#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
int size_x, dp [ 1001 ] [ 1001 ], size_y;
char x [2000], y [2000];
int solve ( int m, int n ) {
    size_x = m;
    size_y = n;
    for ( int i = 1; i <= size_x; i++ ) {
        for ( int j = 1; j <= size_y; j++ ) {
            if ( x [ i - 1 ] == y [ j - 1 ] ) dp [ i ] [ j ] = dp [ i - 1 ] [ j - 1 ] + 1;
            else dp [ i ] [ j ] = max ( dp [ i - 1 ] [ j ], dp [ i ] [ j - 1 ] );
        }
    }
    return dp [ m ] [ n ];
}
int main () {
    gets (x);
    gets (y);
    printf ( "%d \n", solve ( strlen (x), strlen (y) ) );
    return 0;
}
