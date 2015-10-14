#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
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
vector <edge> graph [1000];
priority_queue <edge> Q;
bool visited [10000];
int edges, vertices, parents [10000], start, end, a, b, c;
int main () {
    freopen ("input.txt", "r", stdin);
    scanf ("%d %d %d %d", &edges, &vertices, &start, &end);
    for (int i = 0; i < edges; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }
    Q.push (edge (start, 0));
    while (!Q.empty()) {
        help = Q.top();
        Q.pop ();
        if (!visited [help.n]) {
            parents [help.n] = help.w;
            visited [help.n] = 1;
            if (help.n == end) break;
            for (int i = 0; i < graph [help.n].size(); i++)
                if (!visited [graph [help.n] [i].n])
                    Q.push (edge (graph [help.n] [i].n, graph [help.n] [i].w + parents [help.n]));
            }
    }
    printf ("Solution by Dijkstra: %d \n", parents [end]);
    for (int i = 0; i < 1000; i++) parents [i] = 0;

    return 0;
}
