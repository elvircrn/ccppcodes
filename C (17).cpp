#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

float myAbs(float x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

#define malo 1e-5

bool cmp(float x, float y)
{
    return fabs(x - y) < malo;
}

float SIN [400], COS [400];

struct vector2
{
    float x, y;

    vector2() { }
    vector2(float _x, float _y) { x = _x; y = _y; }

    void counter_clockwise(int number)
    {
        float X = x;
        float Y = y;
        for (int i = 0; i < number; i++)
        {
            float XX = -Y;
            float YY = X;

            X = XX;
            Y = YY;
        }

        x = X;
        y = Y;
    }

    void clockwise(int number)
    {
        if (number == 0)
            return;
        if (number == 1)
            counter_clockwise(3);
        else if (number == 3)
            counter_clockwise(1);
    }

    void get()
    {
        scanf ("%f %f", &x, &y);
    }

    void print()
    {
        printf ("%.0f %.0f\n", x, y);
    }

    void print_debug()
    {
        printf ("%f %f\n", x, y);
    }
};

vector2 input, center;

int main()
{
    freopen ("in.txt", "r", stdin);

    int n, m, x, y, z, p;

    scanf ("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);

    x %= 4;
    y %= 2;
    z %= 4;

    center = vector2((float)(n) / 2.0f, (float) (m) / 2.0f);

    vector2 v;
    vector2 location;

    printf ("center: "); center.print_debug();

    for (int i = 0; i < p; i++)
    {
        input.get();

        if (input.x < center.x)
            input.x += 0.5f;
        else if (input.x > center.x)
            input.x -= 0.5f;

        if (input.y < center.y)
            input.y += 0.5f;
        else if (input.y > center.y)
            input.y -= 0.5f;

        printf ("input: "); input.print_debug();

        v.x = input.x - center.x;
        v.y = input.y - center.y;

        printf ("v: "); v.print_debug();

        v.clockwise(x);

        v.print_debug();

        input.x = v.x + center.x;
        input.y = v.y + center.y;

        if (y > 0 && !cmp (input.y, center.y))
            input.y = center.y - input.y + center.y;

        v.x = input.x - center.x;
        v.y = input.y - center.y;

        v.counter_clockwise(z);

        location.x = center.x + v.x;
        location.y = center.y + v.y;

        location.print_debug();
    }

    return 0;
}
//38 42



