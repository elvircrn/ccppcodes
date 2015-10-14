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
int myabs (int x)
{
    if (x < 0) return x * (-1);
    else return x;

}
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
int m_w;
int m_z;

int get_random()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}

int main ()
{
    srand((unsigned)time(0));
    srand((unsigned)time(0));
    m_w = rand();
    m_z = rand();
    freopen ("C:\\Users\\Inspiron\\Desktop\\MazeBETA\\cpppart\\unos.txt", "r", stdin);
    freopen ("C:\\Users\\Inspiron\\Desktop\\MazeBETA\\cpppart\\izlaz.txt", "w", stdout);
    srand((unsigned)time(0));
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
            if (i % 2 == 1 && j % 2 == 1)
            {
                table [i] [j] =
                 ((get_random ()) % 500000);
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
            if (maze [help.x] [help.y] != ' ') printf ("%d\n%d\n", help.x * 30 + 30, help.y * 30 + 30);
            if (maze [help.X] [help.Y] != ' ') printf ("%d\n%d\n", help.X * 30 + 30, help.Y * 30 + 30);
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
    printf ("%d\n%d\n", (n - 2) * 30 + 30, (m - 1) * 30 + 30);
    printf ("0\n");
    maze [n - 2] [m - 1] = ' ';
    return 0;
}
