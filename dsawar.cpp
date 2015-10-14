#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

vector <point> items;
char field [200] [200];
bool visited [200] [200];
int n, m, c, matrix [200] [200], dist [200] [200], dist_fromt_start [200];
point starting_point;

int find (int index1, int index2)
{
    memset (visited, false, sizeof visited);
    memset (dist, 0, sizeof dist);

    point start = items [index1];
    point end = items [index2];

    queue <point> Q;
    Q.push (start);

    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        if (help.x == end.x && help.y == end.y)
            return dist [help.x] [help.y];

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;

            for (int i = 0; i < 4; i++)
            {
                int X = help.x + dirX [i];
                int Y = help.y + dirY [i];

                if (X < 0 || Y < 0 || X >= n || Y >= m || field [X] [Y] == 'V' || visited [X] [Y])
                    continue;

                dist [X] [Y] = dist [help.x] [help.y] + 1;

                Q.push (point (X, Y));
            }
        }
    }

    return -1;
}

void dfs (int index, bool vis [200], int depth)
{
    for (int i = 0; i < c; i++)
        if (!vis [i])
            dfs (i, vis, depth + matrix [index] [i])
}

int main ()
{
    bool vis[200];

    scanf ("%d %d %d", &n, &m, &c);

    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &field [i]);
        for (int j = 0; j < m; j++)
            if (field [i] [j] == 'D')
                items.push_back (point (i, j));
            else if (field [i] [j] == 'P')
                starting_point = point (i, j);
    }

    items.push_back (starting_point);

    for (int i = 0; i < items.size() - 1; i++)
    {
        for (int j = i + 1; j < items.size(); j++)
        {
            matrix [i] [j] = find (i, j);
            matrix [j] [i] = matrix [i] [j];
        }
    }

    /*for (int i = 0; i < items.size(); i++)
        dist_fromt_start [i] = find (c, i);*/

    dfs (c, vis, 0);

    return 0;
}
/*
3 3 1
P.D
...
V.D
*/





