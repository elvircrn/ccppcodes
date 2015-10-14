#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;

    Rectangle () { }
    Rectangle (int _x1, int _y1, int _x2, int _y2) { x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2; }

    int Left()
    {
        return min (x1, x2);
    }

    int Right()
    {
        return max (x1, x2);
    }

    int Up()
    {
        return min (y1, y2);
    }

    int Down()
    {
        return max (y1, y2);
    }

    bool Intersects (const Rectangle &B) const
    {

    }
}

int main ()
{

    return 0;
}
