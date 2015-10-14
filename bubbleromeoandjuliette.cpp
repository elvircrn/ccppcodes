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

    bool operator<(const edge& B) const
    {
        return w > B.w;
    }
};

vector <edge> graph [20100];
vector <int>  parent_juliet [20100];
vector <int>  parent_romeo [20100];

int romeo_start, juliet_start, romeo_end, juliet_end, d_juliet [20100], d_romeo [20100], e, v;
bool visited [20100], j_mark [20100], r_mark [20100];

bool juliet_mark(int current_node)
{
    if (current_node == juliet_start)
        return true;
    bool result = false;

    for (int i = 0; i < parent_juliet [current_node].size(); i++)
    {
        int next = parent_juliet [current_node] [i];
        if (!visited [next])
        {
            if (next != juliet_start)
                visited [next] = true;
            bool asd = juliet_mark(next);
            if (!result)
                result = asd;
        }
    }

    return j_mark [current_node] = result;
}

bool romeo_mark(int current_node)
{
    if (current_node == romeo_start)
        return true;
    bool result = false;
    for (int i = 0; i < parent_romeo [current_node].size(); i++)
    {
        int next = parent_romeo [current_node] [i];
        if (!visited [next])
        {
            if (next != romeo_start)
                visited [next] = true;
            bool asd = romeo_mark(next);
            if (!result)
                result = asd;
        }
    }

    return r_mark [current_node] = result;
}

void Dijkstra()
{
    priority_queue<edge> Q;
    for (int i = 0; i <= v; i++)
        d_juliet [i] = INF;

    d_juliet [juliet_start] = 0;
    Q.push (edge (juliet_start, 0));
    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        if (help.n == juliet_end)
            continue;

        for (int i = 0; i < graph [help.n].size(); i++)
        {
            if (d_juliet [graph [help.n] [i].n] > d_juliet [help.n] + graph [help.n] [i].w)
            {
                parent_juliet [graph [help.n] [i].n].clear();
                parent_juliet [graph [help.n] [i].n].push_back (help.n);
                d_juliet [graph [help.n] [i].n] = d_juliet [help.n] + graph [help.n] [i].w;
                Q.push (graph [help.n] [i]);
            }
            else if (d_juliet [graph [help.n] [i].n] == d_juliet [help.n] + graph [help.n] [i].w)
                parent_juliet [graph [help.n] [i].n].push_back (help.n);
        }

        help = Q.top();
    }

    memset (j_mark, false, sizeof j_mark);
    juliet_mark(juliet_end);

    for (int i = 0; i <= v; i++)
        d_romeo [i] = INF;

    d_romeo [romeo_start] = 0;
    Q.push (edge (romeo_start, 0));
    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        for (int i = 0; i < graph [help.n].size(); i++)
        {
            if (d_romeo [graph [help.n] [i].n] > d_romeo [help.n] + graph [help.n] [i].w)
            {
                parent_romeo [graph [help.n] [i].n].clear();
                parent_romeo [graph [help.n] [i].n].push_back (help.n);
                d_romeo [graph [help.n] [i].n] = d_romeo [help.n] + graph [help.n] [i].w;
                Q.push (graph [help.n] [i]);
            }
            else if (d_romeo [graph [help.n] [i].n] == d_romeo [help.n] + graph [help.n] [i].w)
                parent_romeo [graph [help.n] [i].n].push_back (help.n);
        }
    }

    memset (visited, false, sizeof visited);
    romeo_mark(romeo_end);

    int min_sol = INF;

    j_mark [juliet_start] = true;
    r_mark [romeo_start]   = true;

    for (int i = 1; i <= v; i++)
        if (r_mark [i] && j_mark [i] && d_romeo [i] == d_juliet [i])
            min_sol = min (min_sol, d_romeo [i]);

    printf ("%d\n", (min_sol != INF) ? min_sol : -1);
}

int main()
{
    int start, end;
    scanf ("%d %d %d %d %d %d", &v, &e, &juliet_start, &juliet_end, &romeo_start, &romeo_end);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
    }

    Dijkstra ();

    return 0;
}








