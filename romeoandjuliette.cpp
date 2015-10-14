#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
    int n, w;

    edge () { }
    edge (int _n, int _w) { n = _n; w = _w; }

    bool operator < (const edge &B) const
    {
        return w > B.w;
    }
};

int n, m, romeo_short, juliet_short, romeo_start, romeo_end, juliet_start, juliet_end, d [20010];
bool visited [20010];
vector <edge> graph [20010];
priority_queue <edge> Q;

int find_path (int start, int finish)
{
    while (!Q.empty()) Q.pop();
    memset (visited, false, sizeof visited);
    memset (d, 0, sizeof d);

    Q.push (edge (start, 0));
    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        if (!d [help.n])
        {
            visited [help.n] = true;
            d [help.n] = help.w;

            if (help.n == finish)
                return d [finish];

            for (int i = 0; i < graph [help.n].size(); i++)
                if (!d [graph [help.n] [i].n])
                    Q.push (edge (graph [help.n] [i].n, d [help.n] + graph [help.n] [i].w));
        }
    }
}

int main ()
{
    int A, B, C;

    scanf ("%d %d %d %d %d %d", &n, &m, &romeo_start, &romeo_end, &juliet_start, &juliet_end);

    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d %d", &A, &B, &C);
        graph [A].push_back (edge (B, C));
        graph [B].push_back (edge (A, C));
    }

    romeo_short = find_path (romeo_start, romeo_end);
    juliet_short = find_path (juliet_start, juliet_end);

    printf ("%d %d\n", romeo_short, juliet_short);

    return 0;
}
