#include <iostream
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int inf = 1<<30;
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
int update [10000], e, v, start, end;
int main () {
    int a, b, c;
    scanf ("%d %d %d %d", &v, &e, &start, &end);
    for (int i = 0; i <= v + 40; i++) update [i] = inf;
    for (int i = 0; i < e; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < graph [i].size(); j++) {
            update [graph [i] [j].n] = min (update [graph [i] [j].n], update [i] + graph [i] [j].w);
        }
    }

    return 0;
}
