#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    bool operator < (const point &B) const
    {
        return x < B.x;
    }
};

int n, m, dist_from_tree [600] [600];
char field [600] [600];

queue <pair <point, int> > Q;
priority_queue <pair <int, pair <int, int> > > pQ;

bool visited [600] [600];

point start, finish;

int main ()
{
    for (int i = 0; i <= 510; i++)
        for (int j = 0; j <= 510; j++)
            dist_from_tree [i] [j] = -1;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &field [i]);
        for (int j = 0; j < m; j++)
        {
            if (field [i] [j] == '+')
            {
                dist_from_tree [i] [j] = 0;
                Q.push (make_pair (point (i, j), 0));
            }
            else if (field [i] [j] == 'V')
                start = point (i, j);
            else if (field [i] [j] == 'J')
                finish = point (i, j);
        }
    }

    while (!Q.empty())
    {
        point help = Q.front().first;
        int dist = Q.front().second;

        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = help.x + dirX [i];
            int Y = help.y + dirY [i];

            if (X < 0 || Y < 0 || X >= n || Y >= m || dist_from_tree [X] [Y] > -1)
                continue;

            dist_from_tree [X] [Y] = dist + 1;

            Q.push (make_pair (point (X, Y), dist + 1));
        }
    }

    pQ.push (make_pair (dist_from_tree [start.x] [start.y], make_pair (start.x, start.y)));

    visited [start.x] [start.y] = true;

    while (!pQ.empty())
    {
        int dist = pQ.top().first;
        point help = point (pQ.top().second.first, pQ.top().second.second);

        pQ.pop();

        if (help.x == finish.x && help.y == finish.y)
        {
            printf ("%d\n", dist);
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int X = help.x + dirX [i];
            int Y = help.y + dirY [i];

            if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y])
                continue;

            visited [X] [Y] = true;

            pQ.push (make_pair ( min (dist, dist_from_tree [X] [Y]), make_pair (X, Y)));
        }
    }

    return 0;
}

/*
4 4
+...
....
....
V..+
*/



