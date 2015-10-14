#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int n, between, Left, Right;
float A, B, C;

struct point
{
    float x, y;

    point () { }
    point (float _x, float _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%f %f", &x, &y);
    }
};

point points [2000];

void solve (int Left, int Right)
{

}

int main ()
{

    scanf ("%d %f %f %f", &n, &A, &B, &C);
    for (int i = 0; i < n; i++)
        points [i].get();

    for (int i = 0; i < n; i++)
    {
        printf ("i: %d x: %.0f y: %.0f\n", i + 1, points [i].x, points [i].y);

        between = 0;
        Left = 0;
        Right = 0;

        for (int j = 0; j < n; j++)
            if (i == j)
                continue;
            else if (A * points [i].x + B * points [i].y + C > 0)
                Left++;
            else if (A * points [i].x + B * points [i].y + C < 0)
                Right++;
            else
                between++;

        printf ("Left: %d between: %d Right: %d\n", Left, between, Right);
    }

    return 0;
}
/*
5 -1 1 0
1 1
1 2
1 3
1 4
1 5
*/
