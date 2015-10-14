#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


int counter, n, m, rev_deg [1000], deg [1000];
vector <int> graph [1000];
vector <int> rev   [1000];

void dfs (int current_index)
{
    for (int i = 0; i < graph [current_index].size(); i++)
    {
        deg [graph [current_index] [i]]++;
        dfs (graph [current_index] [i]);
    }
}

void rev_dfs (int current_index)
{
    for (int i = 0; i < rev [current_index].size(); i++)
    {
        rev_deg [rev [current_index] [i]]++;
        rev_dfs (rev [current_index] [i]);
    }
}

int main()
{
    freopen ("in.txt", "r", stdin);

    int a, b;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &a, &b);
        graph [b].push_back (a);
        rev [a].push_back (b);
    }

    for (int i = 1; i <= n; i++)
        dfs (i);
    for (int i = 1; i <= n; i++)
        rev_dfs(i);

    for (int i = 1; i <= n; i++)
        if (deg [i] > (n / 2) || rev_deg [i] > (n / 2))
            counter++;

    printf ("%d\n", counter);

    return 0;
}







