#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int prvidio, drugidio, maxn, maxsol;
int dirx [4] = { 1, 0, -1, 0 };
int diry [4] = { 0, -1, 0, 1 };
struct par {
    int x, y;
    par () {}
    par (int _x, int _y) {x = _x; y = _y;}
} help;
queue <par> Q;
stack <par> S;
int n, m, matrix [1000] [1000];
int bfs (int xx, int yy) {
    int cnt = 0;
    Q.push (par (xx, yy));
    if (matrix [xx] [yy] == 2) cnt++;
    matrix [xx] [yy] = 1;
    while (!Q.empty()) {
        help = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = help.x + dirx [i], Y = help.y + diry [i];
            if (X < 1 || Y < 1 || X > n || Y > m || matrix [X] [Y] == 1) continue;
            if (matrix [X] [Y] == 2) cnt++;
            matrix [X] [Y] = 1;
            Q.push (par (X, Y));
        }
    }
    return cnt;
}
int main () {
    scanf ("%d %d", &n, &m);
    char a [1000];
    for (int i = 1; i <= n; i++) {
        scanf ("%s", &a);
        for (int j = 1; j <= m; j++) {
            if (a [j - 1] == 'G') matrix [i] [j] = 2;
            else if (a [j - 1] == '#') matrix [i] [j] = 1;
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout<<matrix [i] [j]<<" ";
        }
        cout<<endl;
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix [i] [j] != 1) {
                prvidio++;
                maxn = max (maxn, bfs (i, j));
            }
        }
    }
    cout<<maxn<<endl<<prvidio<<endl;
    return 0;
}
/*
4 5
..G..
.....
.....
.....
*/
