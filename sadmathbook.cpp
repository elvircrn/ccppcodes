#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define malo 1e-5

float fast_pow (float base, int power)
{
    if (power == 0)
        return float (1);
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        float t = fast_pow (base, power / 2);
        return t * t;
    }
    else
        return fast_pow (base, power - 1) * base;
}

float myAbs (float x)
{
    if (x < 0)
        return x * float (-1);
    else
        return x;
}

int compare (float x, float y)
{
    if (myAbs (x - y) < malo)
        return 0;
    else if (x < y)
        return -1;
    else
        return 1;
}

float A, B, C, D;

int find (float y)
{
    float left_side = y + fast_pow ((sqrt (D + y) + y), B);
    return compare (left_side, C);
}


void solve ()
{
    int pivot, left = 1, right = 10000, X, Y, Z;
    float y;
    while (left <= right)
    {
        pivot = (left + right) / 2;
        y = pivot;

        int sol = find (y);

        if (sol == 0)
            break;
        else if (sol == -1)
            left = pivot + 1;
        else
            right = pivot - 1;
    }

    Y = y;
    X = sqrt (D + y);
    Z = A - X * X - Y * Y;

    printf ("%d %d %d\n", X, Y, Z);
}

int main ()
{
    while (scanf ("%f %f %f %f", &A, &B, &C, &D) == 4)
        solve();

    return 0;
}
