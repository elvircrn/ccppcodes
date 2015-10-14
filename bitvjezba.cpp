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
}

class Rectangle
{
    public:
    int x1, y1, x2, y2;

    Rectangle () { }
    Rectangle (int _x1, int _y1, int _x2, int _y2) { x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2; }

    int Left()
    {
        return min (x1, x2);
    }

    int Right()
    {
        max  (x1, x2);
    }

    int Top()
    {
        max (y1, y2);
    }

    int Bottom()
    {
        min (y1, y2);
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
        if (Contains (B.Left(), B.Top()) )
    }
}

int main ()
{

    return 0;
}
