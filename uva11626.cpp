#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define C (*this)

int t, n;

class vector2
{
public:
    static const int clockwise         = 123;
    static const int counter_clockwise = 124;
    static const int colinear          = 125;

    int x, y;

    vector2() { }
    vector2(int _x, int _y) { x = _x; y = _y; }

    int cross(const vector2 &B) const
    {
        return x * B.y - B.x * y;
    }

    int orientation(const vector2 &A, const vector2 &B) const
    {
        vector2 v1 = vector2 (A.x - C.x, A.y - C.y);
        vector2 v2 = vector2 (B.x - C.x, B.y - C.y);

        int xcross = v1.cross(v2);

        if (xcross < 0)
            return clockwise;
        else if (xcross > 0)
            return counter_clockwise;
        else
            return colinear;
    }

    int d(const vector2 &B) const
    {
        return (x - B.x) * (x - B.x) + (y - B.y) * (y - B.y);
    }

    float dist(const vector2 &B) const
    {
        return sqrt ((float)d(B));
    }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }

    void print() const
    {
        printf ("%d %d\n", x, y);
    }

    bool operator== (const vector2 &B) const
    {
        return ((x == B.x) && (y == B.y));
    }
};

char c;
vector <vector2> points;
vector <vector2> points2;
vector2 mminimum, minimum;

bool cmp(const vector2 &A, const vector2 &B)
{
    int orient = minimum.orientation(A, B);

    if (minimum == A)
        return true;
    else if (minimum == B)
        return false;

    if (orient == vector2::clockwise)
        return false;
    else if (orient == vector2::counter_clockwise)
        return true;
    else if (orient == vector2::colinear)
    {
        int dA = minimum.d(A);
        int dB = minimum.d(B);

        return dA < dB;
    }
}

int main()
{

    freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);

    int a, b;

    scanf ("%d", &t);
    while (t--)
    {
        minimum  = vector2(1000000010, 1000000010);
        mminimum = vector2(1000000010, 1000000010);

        points.clear();
        points2.clear();

        scanf ("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d %d %s", &a, &b, &c);
            if (c == 'Y')
            {
                if (mminimum.x > a || (mminimum.x == a && mminimum.y > b))
                    mminimum = vector2(a, b);

                if (minimum.y > b || (minimum.y == b && minimum.x > a))
                    minimum = vector2(a, b);

                points2.push_back(vector2 (a, b));
            }
        }

        int starting_point(0);

        for (int i = 0; i < points2.size(); i++)
            //if (points2 [i].x != minimum.x || points2 [i].y != minimum.y)
                points.push_back (points2 [i]);

        //for (int i = 0; i < points.size(); i++)
        //    points [i].print();

        //printf ("<---------------------------------->\n");

        sort (points.begin(), points.end(), cmp);

        /*for (int i = 0; i < points.size(); i++)
        {
            if (mminimum == points [i])
            {
                starting_point = i;
                break;
            }
        }*/

        printf ("%d\n", points.size());

        for (int i = starting_point; i < points.size(); i++)
            points [i].print();
        for (int i = 0; i < starting_point; i++)
            points [i].print();

    }

    return 0;
}
/*
3
12
0 0 Y
2 0 Y
1 0 Y
3 0 Y
3 3 Y
1 3 Y
2 3 Y
3 1 Y
3 2 Y
0 1 Y
0 2 Y
0 3 Y
3
0 0 Y
1000000000 1000000000 Y
1000000000 0 Y
8
0 -2 Y
1 -1 Y
2 0 Y
1 1 Y
0 2 Y
-1 1 Y
-2 0 Y
-1 -1 Y



12
0 0
1 0
2 0
3 0
3 1
3 2
3 3
2 3
1 3
0 3
0 2
0 1
3
0 0
1000000000 0
1000000000 1000000000
8
-2 0
-1 -1
0 -2
1 -1
2 0
1 1
0 2
-1 1
*/















