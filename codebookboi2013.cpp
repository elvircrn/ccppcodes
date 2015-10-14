#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int array [100], n, k, counter;
bool found;
vector <int> graph [100];

void dfs (int depth, int current_node, bool visited[])
{
    if (depth == n)
        found = true;

    if (found)
    {
        printf ("solution: %d\n", current_node);
        return;
    }

    visited [current_node] = true;
    for (int i = 0; i < graph [current_node].size(); i++)
    {
        if (!visited [graph [current_node] [i]])
            dfs (depth + 1, graph [current_node] [i], visited);
        if (found)
        {
            printf ("solution: %d\n", current_node);
            return;
        }
    }
}

int main ()
{
    bool visited[100];
    memset (visited, false, sizeof visited);

    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    sort (array, array + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            int gcd = __gcd (array [i], array [j]);

            if (gcd >= k)
                graph [array [i]].push_back (array [j]);
        }
    }

    for (int i = 1; i < 10; i++)
    {
        printf ("%d: ", i);
        for (int j = 0; j < graph [i].size(); j++)
        {
            printf ("%d ", graph [i] [j]);
        } printf ("\n");
    }

    dfs (1, array [2], visited);

    return 0;
}
