#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


int merge (int x, int y)
{
    return (x * 10000 + y);
}

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    point operator + (const point B) const
    {
        return point (x + B.x, y + B.y);
    }

    point operator - (const point &B) const
    {
        return point (x - B.x, y - B.y);
    }

    bool operator < (const point &B) const
    {
        if (x != B.x)
            return x < B.x;
        else
            return y < B.y;
    }

    bool operator == (const point &B) const
    {
        return (x == B.x && y == B.y);
    }

    void get() const
    {
        scanf ("%d %d", &x, &y);
    }

    void print() const
    {
        printf ("x: %d y: %d\n", x, y);
    }

    void rotate90c ()
    {
        int X = x;
        int Y = y;

        x = -Y;
        y = X;
    }

    void rotate90 ()
    {
        int X = x;
        int Y = y;

        x = Y;
        y = -X;
    }
};

int solution, n;
point points [1010];

bool find (const point &B)
{
    int left = 0, right = n, pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (points [pivot] == B)
            return true;
        else if (points [pivot] < B)
            left = pivot + 1;
        else
            right = pivot - 1;
    }

    return false;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        points [i].get();

    sort (points, points + n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            point A = points [i];
            point B = points [j];

            //gore
            point C = A - B;
            C.rotate90c();
            bool index1 = find (C + B);
            C = B - A;
            C.rotate90();
            bool index2 = find (C + A);

            if (index1 && index2)
                solution++;

            //dole
            C = A - B;
            C.rotate90();
            index1 = find (C + B);
            C = B - A;
            C.rotate90c();
            index2 = find (C + A);

            if (index1 && index2)
                solution++;
        }
    }

    printf ("%d\n", solution / 4);

    return 0;
}
/*
4
0 0
1 0
0 1
1 1
*/


