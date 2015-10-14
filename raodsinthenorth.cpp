#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w)
    {
        n = _n;
        w = _w;
    }
};

vector <edge> graph [10100];

int max_node, max_depth;

void dfs(int current_node, int prev_node, int current_depth)
{
    for (int i = 0; i < (int)graph [current_node].size(); i++)
        if (graph [current_node] [i].n != prev_node)
            dfs(graph [current_node] [i].n, current_node, current_depth + graph [current_node] [i].w);

    if (max_depth < current_depth)
    {
        max_depth = current_depth;
        max_node = current_node;
    }
}

int main()
{
    string line;
    int start, a, b, c;

    while(getline(cin, line))
    {
        if(line == "")
        {
            max_depth = 0;
            dfs(start, start, 0);
            max_depth = 0;
            dfs(max_node, max_node, 0);

            printf ("%d\n", max_depth);

            for (int i = 0; i < 10001; i++)
                graph [i].clear();
        }
        else
        {
            sscanf(line.c_str(), "%d %d %d", &a, &b, &c);
            start = a;
            graph [a].push_back (edge (b, c));
            graph [b].push_back (edge (a, c));
        }
    }

    max_depth = 0;
    dfs(start, start, 0);
    max_depth = 0;
    dfs(max_node, max_node, 0);staneka o

    printf ("%d\n", max_depth);

    return 0;
}


































