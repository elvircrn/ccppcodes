#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define malo 0.00001

double myAbs (double x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

bool compare (double x, double y)
{
    return myAbs (x - y) < malo;
}

struct point
{
    double x, y;
    bool color;

    point () { }
    point (double _x, double _y) { x = _x; y = _y; }
    point (double _x, double _y, bool _color) { x = _x; y = _y; color = _color; }

    point operator + (const point &B) const
    {
        return point (x + B.x, y + B.y);
    }

    point operator - (const point &B) const
    {
        return point (x - B.x, y - B.y);
    }

    bool positive (const point &B) const
    {
        return (x * B.y - y * B.x > 0);
    }

    void get ()
    {
        scanf ("%f %f", &x, &y);
    }

    void get (bool _color)
    {
        scanf ("%lf %lf", &x, &y);
        color = _color;
    }

    void print() const
    {
        printf ("x: %lf y: %lf\n", x, y);
    }

    double get_distance (const point &B) const
    {
        return (sqrt ((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y)));
    }
};

int direction (const point &middle, const point &A, const point &B)
{
    point a1 = middle - A;
    point b1 = middle - B;

    if (compare ((a1.x * b1.y), (a1.y * b1.x)))
        return 0;
    else if ((a1.x * b1.y) - (a1.y * b1.x) > 0)
        return 1;
    else
        return -1;
}

int n, M, m, N, current_point, start_point;
double minY = 3100000;
point points [201000];
bool visited [201000];

vector <point> convex_hull;

int main ()
{
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
    {
        points [i].get (false);
        if (points [i].y < minY)
        {
            minY = points [i].y;
            start_point = i;
        }
    }

    scanf ("%d", &M);

    for (int i = N; i < N + M; i++)
    {
        points [i].get (true);
        if (points [i].y < minY)
        {
            minY = points [i].y;
            start_point = i;
        }
    }

    n = N + M;

    convex_hull.push_back (points [start_point]);
    visited [start_point] = true;
    int current_point = start_point, previous_point = start_point;

    while (convex_hull.size() < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (found == false && visited [i] == false)
            {
                found = true;
                current_point = i;
            }
            else if (visited [i] == false && direction (points [previous_point], points [current_point], points [i]) == 0)
            {
                if (points [previous_point].get_distance (points [current_point]) > points [previous_point].get_distance (points [i]))
                    current_point = i;
            }
            else if (visited [i] == false && direction (points [previous_point], points [current_point], points [i]) == 1)
                current_point = i;
        }

        if (direction (points [previous_point], points [current_point], points [start_point]) == 1)
            break;

        visited [current_point] = true;
        convex_hull.push_back (points [current_point]);
        previous_point = current_point;
    }

    double solution = 0;

    for (int i = 0; i < convex_hull.size() - 1; i++)
        for (int j = i + 1; j < convex_hull.size(); j++)
        {
            if (convex_hull [i].color == convex_hull [j].color)
                continue;

            double asd = convex_hull [i].get_distance (convex_hull [j]);

            if (solution < asd)
                solution = asd;
        }

    printf ("%.3lf\n", solution);

    return 0;
}
