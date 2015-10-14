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

    /*bool check (Rectangle &A, Rectangle &B)
    {
        return
            max(A.x1, B.x2) <= min(A.x2, B.x2) &&
            max(A.y1, B.y1) <= min(A.y2, B.y2);
    }

    bool Inside (Rectangle &A, Rectangle &B)
    {
        return
            A.x1 > B.x1 && A.x2 < B.x2 &&
            A.y1 > B.y1 && A.y2 < B.y2;
    }

    bool Intersects (Rectangle &A, Rectangle &B)
    {
        return check (A, B) && !check (A, B) && !Inside (B, A);
    }*/
};

int n, counter;
Rectangle rectangles [50000];
bool visited [50000];

void dfs (int current_index)
{
    visited [current_index] = true;

    for (int i = 0; i < n; i++)
        //if (!visited [i] && (rectangles [i].check (rectangles [i], rectangles [current_index])
        //                  || rectangles [current_index].check (rectangles [current_index], rectangles [i])))
        if (!visited [i] && (rectangles [i].Intersects (rectangles [current_index])
                          || rectangles [current_index].Intersects (rectangles [i])))
            dfs (i);
}

int main ()
{
    /*scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        rectangles [i] = Rectangle();
        rectangles [i].Get();

        if (rectangles [i].Bottom() == 0 && rectangles [i].Left() == 0)
        {
            counter = -1;
        }
    }

    rectangles [n] = Rectangle (0, 0, 0, 0);
    n++;

    for (int i = 0; i < n; i++)
    {
        if (!visited [i])
        {
            counter++;
            dfs (i);
        }
    }

    printf ("%d\n", counter - 1);

    freopen ("izlaz1.txt", "w", stdout);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rectangles [i].Intersects (rectangles [j]) || rectangles [j].Intersects (rectangles [i]))
            {
                printf ("%d %d\n", i, j);
            }
        }
    }*/

    Rectangle r1 = Rectangle (), r2 = Rectangle();

    r1.Get();
    r2.Get();

    printf ("%d\n", r1.Intersects (r2));

    return 0;
}

/*

-195 -357 101 -23
-422 -328 487 -289


8
-495 -193 38 -126
-195 -357 101 -23
-159 92 319 435
-466 -74 -138 82
-159 337 319 350
-438 -328 -343 -294
-422 -328 487 -289
-348 424 282 454

2
5 3 10 7
2 5 7 10

1 6
6 1
*/
