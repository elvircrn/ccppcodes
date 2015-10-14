#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
struct edge {
    int p, n, w;
    edge () {}
    edge (int _p, int _n, int _w) {p = _p; n = _n; w = _w;}
    bool operator < (const edge & xx) const
    {
        return w > xx.w;
    }
} help;
priority_queue <edge> Q;
vector <edge> graph [40001];
bool rvisited [40001];
int rs, re, romeo [40001], rparent [40001], mst;
int e, v, a, b, c, edgecounter = 0;
int main () {
    scanf ("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (a, b, c));
        graph [b].push_back (edge (b, a, c));
    }
    Q.push  (edge (1, 1, 0));
    while (!Q.empty () && edgecounter < v) {
        help = Q.top();
        Q.pop();
        if (!rvisited [help.n]) {
            cout<<help.n<<endl;
            edgecounter++;
            mst += help.w;
            rvisited [help.n] = 1;
            for (int i = 0; i < graph [help.n].size(); i++)
                if (!rvisited [graph [help.n] [i].n])
                    Q.push (edge (help.n, graph [help.n] [i].n, romeo [help.n] + graph [help.n] [i].w));
        }
    }
    printf ("%d\n", mst);
    return 0;
}
