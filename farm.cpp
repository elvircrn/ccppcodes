#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
int dx[8] = {-1, 1, -1, 1, 1, 0, -1, 0 };
int dy[8] = {-1, 1, 1, -1, 0, -1, 0, 1 };
int ovce, vukovi, o, v, a, b, m, n, cnt, sol, maxn;
int matrica [ 700 ] [ 700 ];
bool array [ 1000000 ];
queue <int> x;
queue <int> y;
int main () {
    //freopen ( "farm.txt", "r", stdin );
    cin>>m>>n;
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < n; j++ )
            cin>>matrica [ i ] [ j ];
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( matrica [ i ] [ j ] != 0 ) {
                sol++;
                x.push ( i );
                y.push ( j );
                //bfs
                while ( !x.empty() ) {
                    a = x.front();
                    b = y.front();
                    x.pop();
                    y.pop();
                    if ( matrica [ a ] [ b ] == 0 ) continue;
                    maxn = max ( matrica [ a ] [ b ], maxn );
                    matrica [ a ] [ b ] = 0;
                    for ( int i1 = 0; i1 < 8; i1++ ) {
                        int X = a + dx [ i1 ], Y = b + dy [ i1 ];
                        if ( X < 0 || Y < 0 || X >= m || Y >= n || matrica [ X ] [ Y ] == 0 ) continue;
                        x.push ( X );
                        y.push ( Y );
                    }
                }
                //if ( array [ maxn ] == 0 ) sol++;
                array [ maxn ] = true;
                cnt = 0;
                maxn = 0;
            }
        }
    }
    cout<<sol<<endl;
    return 0;
}
