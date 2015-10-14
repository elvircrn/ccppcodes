#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct edge {
    int n, w;
    edge () {}
    edge (int _n, int _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;
vector <edge> graph [100000];
priority_queue <edge> Q;
int d [100000], e, v, start, end;
bool visited [100000];
int main () {
    //freopen ("dijkstra.txt", "r", stdin);
    int a, b, c;
    scanf ("%d %d %d %d", &v, &e, &start, &end);
    for (int i = 0; i < e; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }
    Q.push (edge (start, 0));
    while (!Q.empty()) {
        help = Q.top();
        Q.pop();
        if (!visited [help.n]) {
            d [help.n] = help.w;
            visited [help.n] = 1;
            if (help.n == end) break;
            for (int i = 0; i < graph [help.n].size(); i++)
                if (!visited [graph [help.n] [i].n])
                    Q.push (edge (graph [help.n] [i].n, d [help.n] + graph [help.n] [i].w));
        }
    }
    printf ("%d\n", d [end]);
    return 0;
}
