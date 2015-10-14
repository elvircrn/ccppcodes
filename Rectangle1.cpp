#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Point
{
    public:
    int x, y;

    Point () { }
    Point (int _x, int _y) { x = _x; y = _y; }
};

class Rectangle
{
    public:
    int x1, y1, x2, y2;

    Rectangle () { }
    Rectangle (int _x1, int _y1, int _x2, int _y2) { x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2; }

    void Get()
    {
        scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
    }

    int Left()
    {
        return min (x1, x2);
    }

    int Right()
    {
        return max  (x1, x2);
    }

    int Top()
    {
        return max (y1, y2);
    }

    int Bottom()
    {
        return min (y1, y2);
    }

    bool Contains (Point &B)
    {
        return (Left() <= B.x && B.x <= Right() && Bottom() <= B.y && B.y <= Top());
    }

    bool Contains (const Point &B)
    {
        return (Left() <= B.x && B.x <= Right() && Bottom() <= B.y && B.y <= Top());
    }

    bool Intersects (Rectangle &B)
    {
        return ((Contains (Point (B.Left(), B.Top())) || Contains (Point (B.Left(), B.Bottom())) || Contains (Point (B.Right(), B.Top())) || Contains (Point (B.Right(), B.Bottom())))  &&
            (!Contains (Point (B.Left(), B.Top())) || !Contains (Point (B.Left(), B.Bottom())) || !Contains (Point (B.Right(), B.Top())) || !Contains (Point (B.Right(), B.Bottom()))));
    }
};

int n, counter;
Rectangle rectangles [50000];
bool visited [50000];

void dfs (int current_index)
{
    visited [current_index] = true;

    for (int i = 0; i < n; i++)
        if (!visited [i] && (rectangles [i].Intersects (rectangles [current_index]) || rectangles [current_index].Intersects (rectangles [i])))
            dfs (i);
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        rectangles [i] = Rectangle();
        rectangles [i].Get();

        if (rectangles [i].Bottom() == 0 && rectangles [i].Left() == 0)
        {
            counter = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited [i])
        {
            counter++;
            dfs (i);
        }
    }

    printf ("%d\n", counter);

    return 0;
}

/*
2
5 3 10 7
2 5 7 10
*/
