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

int get_index(const vector2 &point)
{
    return (point.x * 10000 + point.y);
}

vector2 next[99];
int dp [2010] [2010], parent [2010] [2010];
char matrix [2010] [2010];

vector <vector2> start;

int dfs (int x, int y)
{
    if (matrix [x] [y] == '#')
        return 0;

    if (dp [x] [y])
        return dp [x] [y];

    int nextX = next [matrix [x] [y]].x + x;
    int nextY = next [matrix [x] [y]].y + y;

    int res = dfs (nextX, nextY);

    if (dp [nextX] [nextY])
    {
        parent [x] [y] = get_index(nextX, nextY);
        dp [x] [y] = dp [nextX] [nextY] + 1;
        return dp [x] [y];
    }


    return dp [x] [y] = dfs (next [matrix [x] [y]].x, next [matrix [x] [y].y) + 1;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    memset (parent, -1, sizeof parent);
    memset (dp,     -1, sizeof dp);

    next ['<'] = new vector2 (0, -1);
    next ['>'] = new vector2 (0, 1);
    next ['^'] = new vector2 (-1, 0);
    next ['v'] = new vector2 (1, 0);

    vector2 prev, next;

    scanf ("%d %d", &n, &m); getchar();
    for (int i = 0; i < n; i++, getchar())
        for (int j = 0; j < m; j++)
        {
            matrix [i] [j] = getchar();
            if (matrix [i] [j] == '#')
                dp [i] [j] = 0;
        }

    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= m - 1; j++)
        {
            if (matrix [i] [j] != '#')
            {
                relax (i, j);
            }
        }
    }

    for (int i = 0; i < n; i++, putchar ('\n'))
        for (int j = 0; j < m; j++)
            putchar (matrix [i] [j]);

    return 0;
}








