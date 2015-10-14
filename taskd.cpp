#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) {x = _x; y = _y; }

    int dist() const
    {
        return (x - 1) + (y - 1);
    }

    bool operator< (const point &B) const
    {
        return dist() < B.dist();
    }
};

vector <point> points;

map<int, int> distances;

int main()
{
    freopen ("in.txt", "r", stdin);
    int x, y;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &x, &y);
        if (x == n && y == n)
        {
            printf ("-1\n");
            return 0;
        }

        distances [points [i].dist()] += 2;

        points.push_back (point (x, y));
    }

    sort (points.begin(), points.end());

    int count = 1;

    for (int i = 1; i < m; i++)
    {
        if (points [i - 1].dist() != points [i].dist())
        {
            count = 0;
        }
        count++;

        if (points [i].dist() > n - 1)
        {
            int new_dist = ((n - points [i].x) + (n - points [i].y));
            if (new_dist == count - 1)
            {
                printf ("#1: -1\n");
                return 0;
            }
        }
        else
        {
            if (count - 1 == points [i].dist())
            {
                printf ("#2: -1\n");
                return 0;
            }
        }
    }

    cout<<(n - 1) + (n - 1)<<endl;

    return 0;
}
/*
xxxx
xxxx
xxxx
xxxx
*/
