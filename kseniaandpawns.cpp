#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dx [4] = { -1, 0, 1, 0 };
int dy [4] = { 0, 1, 0, -1 };

int n, m;

struct vector2
{
    int x, y;

    vector2() { }
    vector2(int _x, int _y) { x = _x; y = _y; }
};

vector2 get_point(int index)
{
    return vector2 (index / 10000, index % 1000);
}

int get_index(int x, int y)
{
    return x * 10000 + y;
}

vector2 next[300];
int p_sol1, p_sol2, sol1, sol2, dp [2010] [2010], parent [2010] [2010], global;
char matrix [2010] [2010];
bool found;

vector <vector2> start;

int dfs (int x, int y)
{
    global++;
    if (global == n * m)
    {
        printf ("-1\n");
        exit (0);
    }
    int nextX = next [matrix [x] [y]].x + x;
    int nextY = next [matrix [x] [y]].y + y;

    if (matrix [nextX] [nextY] == '#')
    {
        parent [x] [y] = get_index (x, y);
        dp [x] [y] = 1;
        return dp [x] [y];
    }
    else if (dp [nextX] [nextY] != -1)
    {
        parent [x] [y] = parent [nextX] [nextY];
        dp [x] [y] = dp [nextX] [nextY] + 1;
        return dp [x] [y];
    }

    dp [x] [y] = dfs (nextX, nextY) + 1;
    parent [x] [y] = parent [nextX] [nextY];

    return dp [x] [y];
}

int main()
{
    next ['<'] = vector2 (0, -1);
    next ['>'] = vector2 (0, 1);
    next ['^'] = vector2 (-1, 0);
    next ['v'] = vector2 (1, 0);

    vector2 prev, next;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &matrix [i]);
        for (int j = 0; j < m; j++)
        {
            parent [i] [j] = -1;
            dp [i] [j] = -1;
            if (matrix [i] [j] == '#')
            {
                dp [i] [j] = 0;
                parent [i] [j] = get_index (i, j);
            }
            else
                found = true;
        }
    }

    if (!found)
    {
        printf ("0");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            global = 0;
            if (matrix [i] [j] != '#')
                dfs (i, j);
            if (dp [i] [j] > sol1)
            {
                sol1 = dp [i] [j];
                p_sol1 = parent [i] [j];
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sol1 == dp [i] [j] && p_sol1 != parent [i] [j])
            {
                printf ("%d\n", 2 * sol1);
                exit (0);
            }
        }
    }

    printf ("%d\n", 2 * sol1 - 1);

    return 0;
}








