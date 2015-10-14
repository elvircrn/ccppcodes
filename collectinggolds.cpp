#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

vector <int> graph [10000];
vector <int> reversed_graph [10000];
vector <int> sorted;
vector <int> component;
bool visited1 [10000], visited2 [10000], r [10000];
int n, m, cost [10000], a, b, cnt, solution;

void dfs1 (int current_index)
{
    visited1 [current_index] = true;

    for (int i = 0; i < graph [current_index].size(); i++)
    {
        if (!visited1 [graph [current_index] [i]])
        {
            dfs1 (graph [current_index] [i]);
        }
    }

    sorted.push_back (current_index);

    return;
}

void dfs2 (int current_index)
{
    visited2 [current_index] = true;
    component.push_back (current_index);
    for (int i = 0; i < reversed_graph [current_index].size(); i++)
    {
        if (!visited2 [reversed_graph [current_index] [i]])
        {
            dfs2 (reversed_graph [current_index] [i]);
        }
    }
    return;
}

int main ()
{

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &cost [i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &a, &b);
        graph [a].push_back (b);
        reversed_graph [b].push_back (a);
    }

    for (int i = n; i >= 1; i--)
    {
        if (visited1 [i] == false)
        {
            dfs1 (i);
        }
    }

    for (int i = sorted.size() - 1; i > -1; i--)
    {
        if (!visited2 [sorted [i]])
        {
            dfs2 (sorted [i]);
            cnt = 0;
            for (int j = 0; j < component.size(); j++)
            {
                cnt += cost [component [j]];
            }
            solution = max (cnt, solution);
            component.clear();
        }
    }

    printf ("%d\n", solution);

    return 0;
}
/*
9
0
0
0
0
0
0
0
0
0
11
7 4
4 1
1 7
7 9
3 9
9 6
6 3
6 8
5 8
8 2
2 5

4
5
4
1
7
6
1 2
2 3
3 1
2 4
4 2
4 4

*/
