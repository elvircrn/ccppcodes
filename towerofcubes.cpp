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

struct Cube
{
    int colors [6];

    Cube () { };
};

Cube cubes [1000];
int n, solution;

void dfs (int current_index, int previous_color, int depth)
{
    solution = max (solution, depth);
    for (int i = current_index + 1; i < n; i++)
    {
        for (int j = 0; j < 6; j += 2)
        {
            if (previous_color == cubes [i].colors [j])
            {
                dfs (i, cubes [i].colors [j + 1], depth + 1);
            }
        }

        for (int j = 1; j < 6; j += 2)
        {
            if (previous_color == cubes [i].colors [j])
            {
                dfs (i, cubes [i].colors [j - 1], depth + 1);
            }
        }
    }
}

void clear_case()
{
    solution = 0;
}

int main ()
{
    scanf ("%d", &n);
    while (n)
    {
        clear_case();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                scanf ("%d", &cubes [i].colors [j]);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                dfs (i, cubes [i].colors [j], 1);
            }
        }

        printf ("%d\n", solution);

        scanf ("%d", &n);
    }
    return 0;
}




