#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int n, l, r;

struct vector2
{
    float x, y;

    vector2() {}
    vector2(float _x, float _y) { x = _x; y = _y; }

    void rotate(float angle)
    {
        float ang = 180;
        angle *= (M_PI / ang);

        float X = x * cos (angle) + y * sin (angle);
        float Y = x * -sin (angle) + y * cos (angle);

        x = X;
        y = Y;
    }

    void print()
    {
        printf ("x: %f y: %f\n", x, y);
    }
};

int main()
{
    scanf ("%d %d %d", &n, &l, &r);

    vector2 asd(1, 0);

    asd.rotate(90);

    asd.print();

    return 0;
}








