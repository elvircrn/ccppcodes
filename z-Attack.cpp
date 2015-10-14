#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int s, n, k, d [ 1000 ], pamti [ 100 ] [ 100 ];
bool used_up [ 1000 ];
int solve ( int stamina, int used, int index ) {
    int sol = 0;
    if ( stamina <= 0 && used == k ) {
        return 1;
    }
    if ( stamina > 0 && used == k ) {
        return 0;
    }
    for ( int i = index; i < n; i++ ) {
        sol += solve ( stamina - d [ i ], used + 1, i + 1 );
    }
    return sol;
}

int main () {
    scanf ( "%d %d %d", &s, &n, &k );
    for ( int i = 0; i < n; i++ ) scanf ( "%d", &d [ i ] );
    printf ( "%d \n", solve ( s, 0, 0 ) );
    return 0;
}
