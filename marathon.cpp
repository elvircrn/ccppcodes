#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }

    int distance(const point &B) const
    {
        return abs(x - B.x) + abs(y - B.y);
    }
};

vector <point> points;
int n;

int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    int total = 0, maximum = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        points.push_back(point(a, b));

        if (i)
            total += points[i - 1].distance(points[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && i != n - 1)
        {
            maximum = max (maximum, -(points[i - 1].distance(points[i + 1])) + (points[i - 1].distance(points[i]) + points[i].distance(points [i + 1])));
        }
    }

    printf("%d\n", total - maximum);



    return 0;
}
