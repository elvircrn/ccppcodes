#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

float a, b;

#define EPS 10e-7

float cmp (float x, float y)
{
    return fabs (x - y) < EPS;
}

struct point
{
    float x, y;

    point() { }
    point(float _x, float _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%f %f", &x, &y);
    }

    float get_dist(const point &B) const
    {
        return sqrt ((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
    }
};


point points [4], sol [4];
vector <point> sol_p;

int main()
{
    scanf ("%f %f", &a, &b);

    points [0] = point (0, 0);
    points [1] = point (a, b);

    if (int (a) == 0 || int (b) == 0)
    {
        if (a == 0)
        {
            printf ("0 1\n");
            printf ("0 %.0f\n", b);
            printf ("0 0\n");
            printf ("0 %.0f\n", b - 1);
        }
        else
        {
            printf ("1 0\n");
            printf ("%.0f 0\n", a);
            printf ("0 0\n");
            printf ("%.0f 0\n", a - 1);
        }
        return 0;
    }

    float sum1 = 0;

    if (a > b)
    {
        points [2] = point (0, b);
        points [3] = point (a, 0);
    }
    else
    {
        points [2] = point (a, 0);
        points [3] = point (0, b);
    }

    for (int i = 1; i < 4; i++)
        sum1 += points [i - 1].get_dist (points [i]);

    float k = (b / a);

    //sum2
    for (int i = 0; i <= int (a); i++)
    {
        bool found = false;
        for (int j = 0; j <= int (b); j++)
        {
            if (i == 0 && j == 0 || i == a && j == b) continue;
            float X = i;
            float Y = j;

            if (cmp (Y, k * X))
            {
                sol_p.push_back (point (X, Y));
                sol_p.push_back (point (a, b));
                sol_p.push_back (point (0, 0));
                if (a > b)
                    sol_p.push_back (point (a - 1, b));
                else
                    sol_p.push_back (point (a, b - 1));
                found = true;
            }
        }
        if (found)
            break;
    }

    float sum2 = 0;

    for (int i = 1; i < sol_p.size(); i++)
    {
        sum2 += sol_p [i - 1].get_dist (sol_p [i]);
    }

    //sum3
    float sum3 = 0;
    if (a > 1 && b > 1)
    {
        if (a > b)
            sol [0] = point (1, 0);
        else
            sol [0] = point (0, 1);

        sol [1] = point (a, b);
        sol [2] = point (0, 0);

        if (a > b)
            sol [3] = point (a, b - 1);
        else
            sol [3] = point (a - 1, b);

        for (int i = 0; i < 3; i++)
            sum3 += sol [i].get_dist (sol [i + 1]);
    }

    //sum4

    float maximum = 0, sum4 = 0;

    int x, y;
    vector <point> another;

    point AB = point (a, b);

    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < a; j++)
        {

            float c = AB.get_dist (point (i, 0)) + point (i, 0).get_dist (point (j, b));
            if (maximum < c)
            {
                x = i;
                y = j;
                maximum = c;
            }
        }
    }


    another.push_back (point (0, 0));
    another.push_back (point (a, b));
    another.push_back (point (x, 0));
    another.push_back (point (y, b));

    for (int i = 1; i < 4; i++)
        sum4 += another [i - 1].get_dist (another [i]);


    if (sum4 > sum3 && sum4 > sum2 && sum4 > sum1)
    {
        for (int i = 0; i < 4; i++)
            cout<<another [i].x<<' '<<another [i].y<<endl;
    }

    else if (sum3 > sum1 && sum3 > sum2)
    {
        for (int i = 0; i < 4; i++)
            printf ("%.0f %.0f\n", sol [i].x, sol [i].y);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (sum1 > sum2)
            {
                printf ("%.0f %.0f\n", points [i].x, points [i].y);
            }
            else
            {
                printf ("%.0f %.0f\n", sol_p [i].x, sol_p [i].y);
            }
        }
    }

    return 0;
}











