#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

typedef long long int ll;

ll d [1000] [1000];

struct edge {
    ll x, y, w;
    edge () {}
    edge (ll _x, ll _y, ll _w) {x = _x; y = _y; w = _w;}
    bool operator < (const edge & xx) const {
        return w > xx.w;
    }
};

char matrix [1000] [1000];
ll n, m, h, v;
bool visited [1000] [1000];

ll dirx [10] = {-1, 0, 1, 0};
ll diry [10] = {0, 1, 0, -1};

edge start, end, help;

priority_queue <edge> Q;

int main () {

    scanf ("%lld %lld %lld %lld", &n, &m, &h, &v);

    for (ll i = 0; i < n; i++) {
        scanf ("%s", &matrix [i]);
        for (ll j = 0; j < m; j++) {
            if (matrix [i] [j] == 'S') start = edge (i, j, 0);
            else if (matrix [i] [j] == 'E') end = edge (i, j, 0);
        }
    }

    Q.push (start);

    while (!Q.empty()) {

        help = Q.top();
        Q.pop();

        if (!visited [help.x] [help.y]) {

            visited [help.x] [help.y] = true;
            d [help.x] [help.y] = help.w;

            if (end.x == help.x && end.y == help.y) break;

            for (int i = 0; i < 4; i++) {

                int X = dirx [i] + help.x;
                int Y = diry [i] + help.y;

                if (X < 0 || Y < 0 || X >= n || Y >= m || char (matrix [X] [Y]) == '#' || visited [X] [Y]) continue;

                if (matrix [X] [Y] == 'E') Q.push (edge (X, Y, help.w + h));
                else if (i % 2 == 0) Q.push (edge (X, Y, help.w + v + (matrix [X] [Y] - '0')));
                else Q.push (edge (X, Y, help.w + h + (matrix [X] [Y] - '0')));

            }
        }
    }

    if (d [end.x] [end.y]) printf ("%lld\n", d [end.x] [end.y]);
    else puts ("-1");

    return 0;
}
/*
3 7 1 1
S111111
9#####1
99E1111
*/
