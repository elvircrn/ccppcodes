#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

float myAbs (float X)
{
    if (X < 0)
        return (float)X * (float)(-1);
    else
        return X;
}

float X0, Y0, solution;
int n, k;

struct point
{
    float x, y, distance;

    point () { }

    void create()
    {
        distance = sqrt ((myAbs (x - X0) * myAbs (x - X0) + myAbs (y - Y0) * myAbs (y - Y0)));
    }

    bool operator < (const point &B) const
    {
        return distance > B.distance;
    }
};

point points [5001];

int main ()
{

    scanf ("%d %d %f %f", &n, &k, &X0, &Y0);
    for (int i = 0; i < n; i++)
    {
        scanf ("%f %f", &points [i].x, &points [i].y);
        points [i].create();
    }

    sort (points, points + n);

    for (int i = 0; i < k; i++)
    {
        solution = max (solution, points [i].distance);
    }

    printf ("%f\n", solution);

    return 0;
}
