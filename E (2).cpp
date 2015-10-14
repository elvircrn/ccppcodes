#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

vector <int> graph [101000];
vector <int> solution;
int e, v, parity [100100];
bool visited [100100];

int dfs(int current_node, int prev_node)
{
    visited [current_node] = true;
    parity [current_node] ^= 1;

    solution.push_back(current_node);

    int next = -1;

    for (int i = 0; i < graph [current_node].size(); i++)
    {
        next = graph [current_node] [i];

        if (!visited [next])
        {
            dfs(next, current_node);

            parity [current_node] ^= 1;
            solution.push_back(current_node);
        }
    }

    if (parity [current_node])
    {
        if (prev_node == 0)
        {
            solution.pop_back();
            parity [current_node] ^= 1;
        }
        else
        {
            parity [prev_node] ^= 1;
            parity [current_node] ^= 1;

            solution.push_back(prev_node);
            solution.push_back(current_node);
        }
    }
}

int main()
{
    scanf ("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        graph [a].push_back(b);
        graph [b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
        scanf ("%d", &parity [i]);

    bool found = false;

    for (int i = 1; i <= v; i++)
    {
        if (parity [i])
        {
            found = true;
            dfs (i, 0);
            break;
        }
    }

    if (!found)
        printf ("0\n");
    else
    {
        for (int i = 1; i <= v; i++)
        {
            if (parity [i])
            {
                printf ("-1\n");
                return 0;
            }
        }

        printf ("%d\n", solution.size());
        for (int i = 0; i < solution.size(); i++)
            printf ("%d%c", solution [i], (i < solution.size() - 1) ? ' ' : '\n');
    }


    return 0;
}















