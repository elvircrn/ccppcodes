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
#include <map>

using namespace std;

typedef long long int LL;

struct edge
{
    LL m, n, w;

    edge() {}
    edge(LL _m, LL _n, LL _w) {m = _m; n = _n; w = _w;}

    bool operator < (const edge & x) const
    {
        if (x.w != w)
            return w > x.w;
        else
            return m > x.m;
    }
};

vector <edge> graph [100000];
LL parent [100000];
priority_queue <edge> Q;
edge help;

bool visited [100000];
LL d [100000];

void Dijkstra (LL start, LL finish)
{
    Q.push (edge (start, start, 0));

    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        if (!visited [help.n])
        {
            d [help.n] = help.w;
            visited [help.n] = true;

            parent [help.n] = help.m;

            if (help.n == finish)
                break;

            for (int i = 0; i < graph [help.n].size(); i++)
                if (!visited [graph [help.n] [i].n])
                    Q.push (edge (help.n, graph [help.n] [i].n, d [help.n] + graph [help.n] [i].w));
        }
    }

    parent [start] = -1;

    if (parent [finish] == 0)
    {
        printf ("No path\n");
        return;
    }

    int current = finish;

    while (parent [current] > 0)
    {
        printf ("%lld ", current);
        current = parent [current];
    } printf ("1\n");

}

LL e, v;

int main ()
{
    LL a, b, c, start = 1, finish = 0;

    scanf ("%lld", &e);

    for (int i = 0; i < e; i++)
    {
        scanf ("%lld %lld %lld", &a, &b, &c);
        graph [b].push_back (edge (b, a, c));
    }

    Dijkstra (start, finish);

    return 0;
}
