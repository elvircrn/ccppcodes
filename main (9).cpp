#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <cstring>

using namespace std;

vector <int> graph [100100];
vector <int> graph_transpose [100100];
int n, m, group [100100], group_size [100100], group_number;

vector <pair <int, int> > mega_edges;
vector <pair <int, int> > edges;
vector <int> S;
vector <int> mega_graph [100100];
map <int, map <int, bool> > M;

int visited [100100];

void dfs_normal (int current_node)
{
    visited [current_node] = true;

    for (int i = 0; i < graph [current_node].size(); i++)
        if (!visited [graph [current_node] [i]])
            dfs_normal (graph [current_node] [i]);

    S.push_back (current_node);
}

int start_node;
int current_group = 1;
int dp [2] [100100];

void dfs_transpose (int current_node, int current_group)
{
    if (current_node == 1)
        start_node = current_group;

    visited [current_node] = true;

    group [current_node] = current_group;
    group_size [current_group]++;

    for (int i = 0; i < graph_transpose [current_node].size(); i++)
        if (!visited [graph_transpose [current_node] [i]])
            dfs_transpose (graph_transpose [current_node] [i], current_group);
}


/*
mode:
    0 - from 1 to rest
    1 - from rest to 1
*/

int solve (bool mode, int current_node, int where)
{
    //  printf ("mode: %d current_node: %d where: %d\n", mode, current_node, where);
    int &ref = dp [mode] [current_node];

    if (current_node == where)
        return 0;

    if (ref != -1)
        return ref;

    ref = -2;

    for (int i = 0; i < mega_graph [current_node].size(); i++)
    {
        int s = solve (mode, mega_graph [current_node] [i], where);
        if (s >= 0)
            ref = max (ref, group_size [current_node] + s);
    }

    return ref;
}

int main()
{
    freopen ("1.in", "r", stdin);

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        graph [a].push_back (b);
        graph_transpose [b].push_back (a);
        edges.push_back (make_pair (a, b));
    }

    for (int i = 1; i <= n; i++)
        if (!visited [i])
            dfs_normal (i);

    memset (visited, false, sizeof visited);

    for (int i = S.size() - 1; i > -1; i--)
    {
        if (!visited [S [i]])
        {
            group_number++;
            dfs_transpose (S [i], current_group);
            current_group++;
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        if (group [edges [i].first] == group [edges [i].second])
            continue;

        if (!M [group [edges [i].first]] [group [edges [i].second]])
        {
            M [group [edges [i].first]] [group [edges [i].second]] = true;
            mega_graph [group [edges [i].first]].push_back (group [edges [i].second]);
            mega_edges.push_back (make_pair (group [edges [i].first], group [edges [i].second]));
        }
    }

    int solution = group_size [start_node];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 100000; j++)
            dp [i] [j] = -1;

    /*printf ("edges: \n");
    for (int i = 0; i < mega_edges.size(); i++)
        printf ("%d %d\n", mega_edges [i].first, mega_edges [i].second);*/

    for (int i = 0; i < mega_edges.size(); i++)
    {
        //printf ("at i: %d\n", i);

        //solution = max (solution, group_size [mega_edges [i].first] + group_size [mega_edges [i].second]);

        //u -> v
        int u = mega_edges [i].first;
        int v = mega_edges [i].second;

        int r1, r2;

        r1 = solve (0, start_node, group [u]);
        r2 = solve (1, group [v], start_node);

        //from 1 to u; from u to v; from v to 1;
        if (r1 >= 0 && r2 >= 0)
            solution = max (solution, r1 + group_size [u] + r2);
    }

    printf ("%d\n", solution);


    return 0;
}
/*
7 10
1 2
3 1
2 5
2 4
3 7
3 5
3 6
6 5
7 2
4 7
*/











