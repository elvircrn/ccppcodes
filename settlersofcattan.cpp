#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

vector <int> graph [100];

int n, m, t, a, b, solution;
bool visited1 [26] [26], input [26];

void clear_case()
{
    memset (visited1, false, sizeof visited1);
    memset (input, false, sizeof input);
    solution = 0;
    for (int i = 0; i < 50; i++)
        graph [i].clear();
}

void dfs (int current, int depth, bool visited [26] [26])
{
    //printf ("ulaz: %d %d\n", current, depth);
    solution = max (solution, depth);
    for (int i = 0; i < graph [current].size(); i++)
    {
        if (!visited [current] [graph [current] [i]])
        {
            visited [current] [graph [current] [i]] = true;
            visited [graph [current] [i]] [current] = true;
            dfs (graph [current] [i], depth + 1, visited);
            visited [current] [graph [current] [i]] = false;
            visited [graph [current] [i]] [current] = false;
        }
    }
}

int main ()
{
    while (true)
    {
        scanf ("%d %d", &n, &m);

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < m; i++)
        {
            scanf ("%d %d", &a, &b);
            graph [a].push_back (b);
            graph [b].push_back (a);
        }

        for (int i = 0; i < n; i++)
        {
            //printf ("<- START ->\n");
            memset (visited1, false, sizeof visited1);
            dfs (i, 0, visited1);
        }

        printf ("%d\n", solution);

        clear_case();
    }

    return 0;
}
