#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long int ll;

const ll start = 1;
const ll end   = 0;
const ll INF   = 1<<29;

struct edge
{
    ll m, n, w;

    edge() { }
    edge(ll _m, ll _n, ll _w) { m = _m; n = _n; w = _w; }

    bool operator< (const edge &B) const
    {
        if (w == B.w)
            return m > B.m;
        else
            return w > B.w;
    }
};

vector <edge> graph [16000];
ll d [160000], e, parent [16000];
queue <edge> Q;

void Dijkstra ()
{
    memset (parent, -1, sizeof parent);

    for (int i = 0; i < 15500; i++)
        d [i] = INF;

    d [start] = 0;

    Q.push (edge (start, start, 0));
    while (!Q.empty())
    {
        edge help = Q.front();
        Q.pop();


        for (int i = 0; i < graph [help.n].size(); i++)
        {
            ll from   = help.n;
            ll where  = graph [help.n] [i].n;
            ll weight = graph [help.n] [i].w;
            if (d [where] > d [from] + weight)
            {
                parent [where] = from;
                d [where] = d [from] + weight;
                Q.push (graph [help.n] [i]);
            }
            else if (d [where] == (d [from] + weight) && parent [where] > from)
                parent [where] = from;
        }
    }

    ll current_node = end;

    if (d [end] == INF)
    {
        printf ("No path");
        return;
    }

    while (current_node != start)
    {
        printf ("%lld ", current_node);
        current_node = parent [current_node];
    }

    printf ("%lld\n", start);
}

int main()
{
    scanf ("%lld", &e);
    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        scanf ("%lld %lld %lld", &a, &b, &c);
        graph [b].push_back (edge (b, a, c));
    }

    Dijkstra();

    return 0;
}






