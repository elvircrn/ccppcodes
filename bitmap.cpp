#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1<<26

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void print()
    {
        printf ("x: %d y: %d\n", x, y);
    }
};

queue <point> Q;
int t, n, m, matrix [200] [200], dist [200] [200];;
bool visited [200] [200];
char line[200];
point help;

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d", &t);

    while (t--)
    {
        memset (visited, false, sizeof visited);
        memset (dist, 0, sizeof dist);

        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf ("%s", &line);
            for (int j = 0; j < m; j++)
            {
                dist [i] [j] = INF;
                matrix [i] [j] = line [j] - '0';

                if (matrix [i] [j])
                {
                    Q.push (point (i, j));
                    dist [i] [j] = 0;
                }
                visited [i] [j] = matrix [i] [j];
            }
        }

        while (!Q.empty())
        {
            help = Q.front();
            Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int X = help.x + dirX [i];
                int Y = help.y + dirY [i];

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y])
                    continue;

                visited [X] [Y] = true;
                dist [X] [Y] = min (dist [X] [Y], dist [help.x] [help.y] + 1);

                Q.push (point (X, Y));
            }
        }

        for (int i = 0; i < n; i++, putchar ('\n'))
            for (int j = 0; j < m; j++)
            {
                if (j < m - 1)
                    printf ("%d ", dist [i] [j]);
                else
                    printf ("%d", dist [i] [j]);
            }
    }

    return 0;
}
/*
3
3 4
0000
0100
0000
3 4
0001
0011
0110
1 1
1
*/










