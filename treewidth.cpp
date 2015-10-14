#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//#define DEBUG

struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w) { n = _n; w = _w; }
};

vector <edge> graph [100100];
int e, v, parent_width [100100], parent [100100], mark [100100], maximum, vertex, what = 1, l;

stack <edge> S;

void dfs2 (int current_index)
{
    S.push (edge (current_index, 0));

    while (!S.empty())
    {
        edge help = S.top();
        S.pop();

        int progress      = help.w;
        int current_index = help.n;

        if (mark [current_index] != what)
        {
            mark [current_index] = what;
            if (progress >= maximum)
            {
                maximum = progress;
                vertex = current_index;
            }

            for (int i = 0; i < graph [current_index].size(); i++)
            {
                if (mark [graph [current_index] [i].n] != what)
                {
                    parent [graph [current_index] [i].n] = current_index;
                    parent_width [graph [current_index] [i].n] = graph [current_index] [i].w;
                    S.push (edge (graph [current_index][i].n, progress + graph [current_index] [i].w));
                }
            }
        }
    }
}

vector <int> vertex_set;

void analyze(int current_index)
{
    if (mark [current_index])
        return;

#ifdef DEBUG
    printf ("call: %d\n", current_index);
#endif

    maximum = 0;
    vertex = 0;
    dfs2 (current_index);

    if (graph [current_index].size() == 0)
    {
        vertex = current_index;
        vertex_set.push_back (current_index);
        return;
    }


#ifdef DEBUG
    printf ("vertex: %d maximum: %d\n", vertex, maximum);
#endif

    what++;
    maximum = 0;

    int start = vertex;

    dfs2 (vertex);

    int total = maximum, end = vertex, current_width = 0;

    while (start != end)
    {
        if (current_width + parent_width [end] >= total - parent_width [end])
            break;

        current_width += parent_width [end];
        total -= parent_width [end];

        end = parent [end];
    }

    //printf ("vertex: %d\n", end);

#ifdef DEBUG
    printf ("center: %d\n", end);
#endif

    vertex_set.push_back (end);
}

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d %d %d", &v, &e, &l);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }

    for (int i = 0; i < v; i++)
        analyze (i);

#ifdef DEBUG
    printf ("<- vertex set ->\n");
    for (int i = 0; i < vertex_set.size(); i++)
        printf ("%d\n", vertex_set [i]);
#endif // DEBUG

    for (int i = 1; i < vertex_set.size(); i++)
    {
        graph [vertex_set [0]].push_back (edge (vertex_set [i], l));
        graph [vertex_set [i]].push_back (edge (vertex_set [0], l));
    }

    memset (mark, 0, sizeof mark);

    maximum = 0;

    analyze (0);

    printf ("%d\n", maximum);

    return 0;
}

//31910 4


/*
5 2 2
1 2 1
3 4 1
*/





