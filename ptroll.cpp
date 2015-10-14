#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define INF 1<<29
#define LL long long int

vector <LL> graph [20000];
vector <LL> reversed_graph [20000];
vector <LL> sorted;
vector <LL> component;
bool visited1 [20000], visited2 [20000], r [20000];
LL n, m, cost [20000], a, b, cnt, solution = INF;

void dfs1 (LL current_index)
{
    visited1 [current_index] = true;

    for (LL i = 0; i < graph [current_index].size(); i++)
        if (!visited1 [graph [current_index] [i]])
            dfs1 (graph [current_index] [i]);

    sorted.push_back (current_index);

    return;
}

void dfs2 (LL current_index)
{
    visited2 [current_index] = true;

    component.push_back (current_index);

    for (LL i = 0; i < graph [current_index].size(); i++)
        if (!visited2 [graph [current_index] [i]])
            dfs2 (graph [current_index] [i]);

    return;
}

int main ()
{

    scanf ("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &cost [i]);
    for (int i = 0; i < m; i++)
    {
        scanf ("%lld %lld", &a, &b);
        graph [a].push_back (b);
    }

    for (int i = n; i >= 1; i--)
        if (visited1 [i] == false)
            dfs1 (i);

    for (int i = sorted.size() - 1; i > -1; i--)
    {
        if (!visited2 [sorted [i]])
        {
            dfs2 (sorted [i]);
            cnt = 0;

            for (int j = 0; j < component.size(); j++)
                cnt += cost [component [j]];

            solution = min (cnt, solution);
            component.clear();
        }
    }

    printf ("%lld\n", solution);

    return 0;
}
/*
4 2
15
17
21
19
1 2
2 3
*/
