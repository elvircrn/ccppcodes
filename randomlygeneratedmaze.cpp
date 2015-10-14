#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int dirx [4] = {-1, 0, 1, 0};
int diry [4] = {0, 1, 0, -1};
int doubledirx [4] = {-2, 0, 2, 0};
int doublediry [4] = {0, 2, 0, -2};

struct node
{
    int x, y, pq, X, Y;
    node () {}
    node (int _x, int _y, int PQ, int _xx, int _yy) {x = _x; y = _y; pq = PQ; X = _xx; Y = _yy;}
    bool operator < (const node & xx) const
    {
        return pq > xx.pq;
    }
};

bool visited [1000] [1000];
char maze [1000] [1000];
node pq, help;
priority_queue <node> Q;
vector <node> graph [1000];
int XX, YY, n, m, table [1000] [1000];

int main ()
{
    freopen ("unos.txt", "r", stdin);
    freopen ("izlaz.txt", "w", stdout);
    srand((unsigned)time(0));
    scanf ("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
    {
        visited [0] [i] = visited [i] [0] = visited [n] [i] = visited [m] [i] = true;
        maze [0] [i] = maze [i] [0] = maze [n] [i] = maze [m] [i] = 178;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maze [i] [j] = 178;
            if (i % 2 == 0 && j % 2 == 0)
            {
                table [i] [j] = (rand () % 10) + 5;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        maze [i] [m] = '\0';
    }

    maze [1] [0] = ' ';

    Q.push (node (1, 1, table [1] [1], 1, 1));

    while (!Q.empty())
    {
        help = Q.top();
        Q.pop();

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;
            maze [help.x] [help.y] = ' ';
            maze [help.X] [help.Y] = ' ';
            for (int i = 0; i < 4; i++)
            {
                int XX = help.x + doubledirx [i], YY = help.y + doublediry [i], X = help.x + dirx [i], Y = help.y + diry [i];
                if (!visited [XX] [YY] && !visited [X] [Y] && X && Y && XX && YY && XX < n && YY < m)
                {
                    visited [X] [Y] = true;
                    Q.push (node (XX, YY, table [XX] [YY], X , Y));
                }
            }
        }
    }

    maze [n - 2] [m - 1] = ' ';

    for (int i = 0; i < n; i++)
    {
        puts (maze [i]);
    }
    return 0;
}
