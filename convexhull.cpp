#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

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

int n, m, N, current_point, start_point;
double minY = 1000000;
point points [200010];
bool visited [200010];

vector <point> convex_hull;

int main ()
{
    double minY = 100000;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        points [i].get (false);
        if (points [i].y < minY)
        {
            minY = points [i].y;
            start_point = i;
        }
    }

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
            else if (visited [i] == false && direction (points [previous_point], points [current_point], points [i]))
                current_point = i;
        }

        if (direction (points [previous_point], points [current_point], points [start_point]))
            break;

        visited [current_point] = true;
        convex_hull.push_back (points [current_point]);
        previous_point = current_point;
    }

    double solution = convex_hull [0].get_distance (convex_hull [convex_hull.size() - 1]);

    for (int i = 1; i < convex_hull.size(); i++)
        solution += convex_hull [i].get_distance (convex_hull [i - 1]);

    printf ("%.2lf\n", solution);

    return 0;
}
