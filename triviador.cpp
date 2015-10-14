#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int dirX [8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dirY [8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }
};

int t, n, m, numberX, numberO;
char matrix [200] [200];

void bfs (const point &start, bool moveX)
{
    queue <point> Q;

    Q.push (start);
    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        if (moveX)
            matrix [help.x] [help.y] = 'X';
        else
            matrix [help.x] [help.y] = 'O';

        for (int i = 0; i < 8; i++)
        {
            int X = help.x + dirX [i];
            int Y = help.y + dirY [i];

            if (X < 0 || Y < 0 || X >= n || Y >= m || (moveX && matrix [X] [Y] == 'X') || (!moveX && matrix [X] [Y] == 'O'))
                continue;

            Q.push(point (X, Y));
        }
    }
}

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        numberX = 0;
        numberO = 0;

        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf ("%s", &matrix [i]);
            for (int j = 0; j < m; j++)
            {
                if (matrix [i] [j] == 'X')
                    numberX++;
                else
                    numberO++;
            }
        }

        bool moveX(true);

        while (numberX && numberO)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (moveX && matrix [i] [j] == 'O')
                    {
                        bfs (point(i, j), moveX);
                        goto l1;
                    }
                    else if (!moveX && matrix [i] [j] == 'X')
                    {
                        bfs (point(i, j), moveX);
                        goto l1;
                    }
                }
            }

            l1:;

            /*for (int i = 0; i < n; i++, printf ("\n"))
                for (int j = 0; j < m; j++)
                    printf ("%c", matrix [i] [j]);*/

            moveX = !moveX;

            numberX = 0;
            numberO = 0;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (matrix [i] [j] == 'X')
                        numberX++;
                    else
                        numberO++;
        }

        if (numberX)
            printf ("X\n");
        else
            printf ("O\n");
    }

    return 0;
}
/*
1
4 4
XXXX
OOOO
XXXX
OOOO

2
3 3
XOX
XXX
XOX
3 5
XXXXX
XXXOO
XXXOO
*/
