#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct edge
{
    int n, w;

    edge () { }
    edge (int _n, int _w) { n = _n; w = _w; }
};


vector <edge> graph [1000];
vector <int> edges;
bool visited [1000];
int v, e, A, B, C, tourists;

bool bfs (int start, int end, int bound)
{
    queue <int> Q;
    Q.push (start);
    while (!Q.empty())
    {
        int help = Q.front();
        Q.pop();

        if (!visited [help])
        {
            if (help == end)
            {
                return true;
            }

            visited [help] = true;

            for (int i = 0; i < graph [help].size(); i++)
            {
                if (!visited [graph [help] [i].n] && bound <= graph [help] [i].w)
                {
                    Q.push (graph [help] [i].n);
                }
            }
        }
    }

    return false;
}

void clear_case()
{
    edges.clear();
    for (int i = 0; i <= v; i++) graph [i].clear();
    memset (visited, false, sizeof visited);
}

int main ()
{
    //freopen ("unos.txt", "r", stdin);
    int start, end, t = 0;
    scanf ("%d %d", &v, &e);
    while (v || e)
    {
        clear_case();
        for (int i = 0; i < e; i++)
        {
            scanf ("%d %d %d", &A, &B, &C); C--;
            graph [A].push_back (edge (B, C));
            graph [B].push_back (edge (A, C));
            edges.push_back (C);
        }

        scanf ("%d %d %d", &start, &end, &tourists);

        sort (edges.begin(), edges.end());

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            if (i == edges.size() - 1 || edges [i] != edges [i - 1])
            {
                memset (visited, false, sizeof visited);
                if (bfs (start, end, edges [i]) == true)
                {
                    printf ("Scenario #%d\n", ++t);
                    if (tourists % edges [i] == 0)
                        printf ("Minimum Number of Trips = %d\n", tourists / edges [i]);
                    else
                        printf ("Minimum Number of Trips = %d\n", tourists / edges [i] + 1);
                    printf ("\n");
                    break;
                }
            }
        }

        scanf ("%d %d", &v, &e);
    }
    return 0;
}
