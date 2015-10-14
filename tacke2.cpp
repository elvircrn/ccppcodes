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
        scanf ("%lf %lf", &x, &y);
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

bool direction (const point &middle, const point &A, const point &B)
{
    point a1 = middle - A;
    point b1 = middle - B;

    return ((a1.x * b1.y) - (a1.y * b1.x) > 0);
}

int n, M, m, N, current_point, start_point;
double minY = 3100000;
point points [201000];
bool visited [201000];

vector <point> convex_hull;
vector <point> convex_hull1;

int main ()
{
    double minY = 3100000;
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

    float minY1 = 2000000.0;

    int start_point1;

    for (int i = N; i < N + M; i++)
    {
        points [i].get (true);
        if (points [i].y < minY1)
        {
            minY1 = points [i].y;
            start_point1 = i;
        }
    }


    n = N + M;

    convex_hull.push_back (points [start_point]);
    visited [start_point] = true;
    int current_point = start_point, previous_point = start_point;

    while (convex_hull.size() < N)
    {
        bool found = false;
        for (int i = 0; i < N; i++)
        {
            if (found == false && visited [i] == false)
            {
                found = true;
                current_point = i;
            }
            else if (visited [i] == false && direction (points [previous_point], points [current_point], points [i]))
                current_point = i;
        }

        if (direction (points [previous_point], points [current_point], points [start_point]))
            break;

        visited [current_point] = true;
        convex_hull.push_back (points [current_point]);
        previous_point = current_point;
    }

    convex_hull1.push_back (points [start_point1]);
    visited [start_point1] = true;
    int current_point1 = start_point1;
    int previous_point1 = start_point1;

    while (convex_hull1.size() < M)
    {
        bool found = false;
        for (int i = N; i < N + M; i++)
        {
            if (found == false && visited [i] == false)
            {
                found = true;
                current_point1 = i;
            }
            else if (visited [i] == false && direction (points [previous_point1], points [current_point1], points [i]))
                current_point1 = i;
        }

        if (direction (points [previous_point1], points [current_point1], points [start_point1]))
            break;

        visited [current_point1] = true;
        convex_hull1.push_back (points [current_point1]);
        previous_point1 = current_point1;
    }

    double solution = 0.000f;
    bool nasao = false;

    for (int i = 0; i < convex_hull.size(); i++)
        for (int j = 0; j < convex_hull1.size(); j++)
        {
            if (solution < convex_hull [i].get_distance (convex_hull1 [j]))
                solution = convex_hull [i].get_distance (convex_hull1 [j]);
            nasao = true;
        }

    printf ("%.3lf\n", solution);

    return 0;
}
