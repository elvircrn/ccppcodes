#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define malo 1e-7
#define PUNO 300000

int n;
float l, r, dp [2197152];

float MAX (const float &a, const float &b)
{
    return (a > b) ? a : b;
}

float MIN (const float &a, const float &b)
{
    return (a < b) ? a : b;
}

float myAbs (const float &a)
{
    return MAX (a, -a);
}

bool cmp (const float &a, const float &b)
{
    return (myAbs (a - b) < malo);
}

struct vector2
{
    float x, y;

    vector2() {}
    vector2(const float &_x, const float &_y) { x = _x; y = _y; }

    void rotate(const float &angle)
    {
        float ang = 180;
        float Angle = angle * (M_PI / ang);

        float xcos = cos (Angle);
        float xsin = sin (Angle);

        float X = (float)(x * xcos + y * xsin);
        float Y = (float)(x * -xsin + y * xcos);

        x = X;
        y = Y;
    }

    int cross_product(const vector2 &B) const
    {
        return x * B.y - y * B.x;
    }
};

struct floodlight
{
    vector2 loc;
    float angle;

    floodlight() { }
};

floodlight floodlights [30];
int mask_limit;

float calculate(const float &dist, int index)
{
    vector2 new_vector = vector2 (dist - floodlights [index].loc.x,
                                  -floodlights [index].loc.y);


    if (new_vector.y < 0)
    {
        new_vector.rotate(-floodlights [index].angle);
        vector2 START = floodlights [index].loc, END (START.x + new_vector.x,  START.y + new_vector.y);

        if (END.y > START.y)
            return r;
    }
    else
    {
        new_vector.rotate(floodlights [index].angle);

        vector2 START = floodlights [index].loc, END (START.x + new_vector.x,  START.y + new_vector.y);

        if (START.y > END.y)
            return r;
    }

    vector2 start = floodlights [index].loc;
    vector2 end   = vector2 (start.x + new_vector.x, start.y + new_vector.y);

    if (start.x == end.x)
        return start.x;

    float k = ((start.y - end.y) / (start.x - end.x));
    float n = (start.y - start.x * k);

    return -(n / k);
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d %f %f", &n, &l, &r);
    for (int i = 0; i < n; i++)
        scanf ("%f %f %f", &floodlights [i].loc.x, &floodlights [i].loc.y, &floodlights [i].angle);

    mask_limit = 1<<n;

    float sol = 0;

    for (int i = 0; i <= mask_limit; i++)
        dp [i] = l;

    for (int i = 0; i < mask_limit; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1<<j)) == 0)
            {
                int element = (1<<j);
                dp [i + element] = MAX (dp [i + element], calculate (dp [i], j));
                //sol =  MAX (sol, dp [i + element]);
            }
        }
    }

    for (int i = 0; i < mask_limit; i++)
        sol = MAX (sol, dp [i] - l);

    printf ("%.7f\n", MIN (r - l, sol));
    return 0;
}















