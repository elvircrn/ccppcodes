#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

typedef long long int ll;

int n;

struct point
{
    int x, y;
    char type;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }
    point(int _x, int _y, char _type) { x = _x; y = _y; type = _type; }

    bool operator < (const point &B) const
    {
        return x < B.x;
    }

    bool valid()
    {
        return type == 'H';
    }
};

struct compX
{
    bool operator() (const point &A, const point &B) const
    {
        return A.x < B.x;
    }
};

struct compY
{
    bool operator() (const point &A, const point &B) const
    {
        return A.y < B.y;
    }
};

set    <point, compX> S;
vector <point> points;

int main()
{
    int x, y;
    char s [2];
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d %s", &x, &y, &s);
        points.push_back(point(x, y, *s));
    }

    sort(points.begin(), points.end(), compY);

    int min_area = 1e9, solution = 0, current = 0;
    point left, right, up, down;

    for (point a : points)
    {
        for (point b : points)
        {
            if (a.x == b.x && a.y == b.y)
                continue;
        }
    }

    return 0;
}

/*
5
1 1 H
2 2 H
3 3 G
4 4 H
6 6 H
*/

