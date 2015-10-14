#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1<<27

struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w) { n = _n; w = _w; }

    bool operator < (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> graph [20100];
int parent [20100], start, end, e, v, a, b, c, d [20100];
queue <edge> Q;
vector <int> parent [20100];
bool visited [20100];

int main()
{
    scanf ("%d %d %d %d", &v, &e, &start, &end);
    for (int i = 0; i < e; i++)
    {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }

    for (int i = 0; i <= v; i++)
        d [i] = INF;

    d [start] = 0;
    Q.push (edge (start, 0));
    while (!Q.empty())
    {
        edge help = Q.front();
        Q.pop();

        for (int i = 0; i < graph [help.n].size(); i++)
        {
            int from   = help.n;
            int where  = graph [help.n] [i].n;
            int weight = graph [help.n] [i].w;
            if (d [where] > d [from] + weight)
            {
                parent [where].clear();
                parent [where] = from;
                d [where] = d [from] + weight;
                Q.push (graph [help.n] [i]);
            }
            else if (d [where] == d [from] + weight)
                parent [where].push_back (from);
        }
    }



    return 0;
}






