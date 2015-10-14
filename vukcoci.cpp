#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define INF 1<<29

const int dirX [4] = { -1, 0, 1, 0 };
const int dirY [4] = { 0, 1, 0, -1 };

class Point
{
public:
    int x, y;

    Point () { }
    Point (int _x, int _y) { x = _x; y = _y; }

    bool operator == (const Point &B) const
    {
        return (x == B.x && y == B.y);
    }
};

class ForQueue
{
public:
    Point point;
    int cost;

    ForQueue () { }
    ForQueue (const Point &A, int B) { point = A; cost = B; }

    bool operator < (const ForQueue &B) const
    {
        return cost < B.cost;
    }

    bool operator == (const ForQueue &B) const
    {
        return (point == B.point);
    }
};

int n, m, solution, menhetn [501] [501];
char c;

priority_queue <ForQueue> Q;

vector <Point> Trees;

bool passable [501] [501];

Point start, end;

int myAbs (int x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

int Manhattan (const Point &A, const Point &B)
{
    return (myAbs (A.x - B.x) + myAbs (A.y - B.y));
}

int FindTree(Point position)
{
    int minimum = INF;
    for (int i = 0; i < Trees.size(); i++)
    {
        minimum = min (minimum, Manhattan (Trees [i], position));
    }

    return minimum;
}

int main ()
{
    freopen ("unos.txt", "r", stdin);

    memset (passable, true, sizeof passable);

    scanf ("%d %d", &n, &m); getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c = getchar();
            if (c == 'V')
            {
                start = Point (i, j);
            }
            else if (c == 'J')
            {
                end = Point (i, j);
            }
            else if (c == '+')
            {
                passable [i] [j] = false;
                Trees.push_back (Point (i, j));
            }
            else
            {
                menhetn [i] [j] = FindTree (Point (i, j));
            }
        }
        getchar();
    }

    //solution = 0;

    Q.push (ForQueue (start, FindTree (start)));
    while (!Q.empty())
    {
        ForQueue help = Q.top();
        Q.pop();

        if (passable [help.point.x] [help.point.y])
        {
            passable [help.point.x] [help.point.y] = false;

            solution = max (solution, help.cost);

            if (help.point == end)
            {
                //solution = help.cost;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int X = help.point.x + dirX [i];
                int Y = help.point.y + dirY [i];

                if (X < 0 || Y < 0 || X >= n || Y >= m || !passable [X] [Y])
                    continue;

                Q.push (ForQueue (Point (X, Y), /*FindTree (Point (X, Y))*/min (help.cost, FindTree (Point (X, Y)))));
            }
        }
    }

    printf ("%d", solution);

    return 0;
}
/*
15 15
..+...+++.+....
.+.+++.+++.+...
.++++++..++..J.
.....++.+..+...
.+.+.+..+......
.+.+.+.....++..
++..+.+.++++.+.
.++...........+
....+++++....++
+.+......+...+.
..+++..........
++.+++..+++.+++
++.+++.+++.+.+.
.+.....+V.+.+..
.+..++...++.+..

4 4
+...
....
....
V..J

35 50
....J.............................................
..................................................
..................................................
..........................+.......................
..................................................
..................................................
....................................+.............
..................................................
..................................................
..................................................
..................................................
..............................+...................
..................................................
..................................................
..................................................
..................................................
..................................................
....+.........................+...................
..........................+.......................
..+.....................+.........................
..................................................
..................................................
..................................................
..........................V.......................
..................................................
..................................................
..................................................
..................................................
..................................................
..................................................
.....................+............................
..................................................
..................................................
..................................................
................+.................................
*/



