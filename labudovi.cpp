#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define INF 3267;
class point {
    public:
    short x, y;
    point () {}
    point (short _x, short _y) {x = _x; y = _y;}
};
short maxn, dp [1510] [1510];
int n, m;
int dirx [10] = {-1, 0, 1, 0, -1, 1, 1, -1};
int diry [10] = {0, 1, 0, -1, -1, -1, 1, 1};
point start, end, help;
bool prvi;
char c, a [1510] [1510];
queue <point> Q;
bool bfs (int allow) {
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {if (!Q.empty()) Q.pop(); a [i] [j] = 0;}
    Q.push (point (start.x, start.y));
    while (!Q.empty()) {
        help = Q.front();
        Q.pop();
        if (a [help.x] [help.y] == 0 && dp [help.x] [help.y] < allow) {
            a [help.x] [help.y] = 1;
            for (int i = 0; i < 4; i++) {
                short X = help.x + dirx [i];
                short Y = help.y + diry [i];
                if (!X || !Y || X > n || Y > m || dp [X] [Y] >= allow || a [X] [Y]) continue;
                if (end.x == X && end.y == Y) {return true;}
                Q.push (point (X, Y));
            }
        }
    }
    return false;
}
int BFS (int x, int y) {
    queue <point> bfs;
    bfs.push (point (x, y));
    while (!bfs.empty()) {

    }
}
int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf ("%s", &a [i]);
        for (int j = 0; j < m; j++) {
            if (a [i] [j] == 'L') {
                if (prvi) end = point (i, j + 1);
                else {
                    start = point (i, j + 1);
                    prvi = true;
                }
            }
            else if (a [i] [j] == 'X') dp [i] [j + 1] = INF;
        }
    }
    int cnt = 0;
    bool promjena = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a [i] [j] == 'X') dp [i] [j] = BFS (i);
        }
    }
    /*
    maxn += 2;
    for (int i = 1; i <= maxn; i++) {
        if (bfs (i)) {
            printf ("%d\n", i - 1);
            break;
        }
    }*/
    return 0;
}
/*
5 8
XXXX.L.X
XXXXXXXX
XXXXXXXX
XXXXXXXX
LXXXXXXX
*/
