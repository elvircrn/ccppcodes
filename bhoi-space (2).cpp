#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG

int solution = 0;

struct point
{
    int x, y;
    bool isPlanet;

    point () { x = 0; y = 0; }
    point (int _x, int _y) { x = _x; y = _y; isPlanet = true; }
    point (int _x, int _y, bool _isP) { x = _x; y = _y; isPlanet = _isP; }

    bool operator < (const point &B) const
    {
        if (x != B.x)
            return x < B.x;
        else
            return y > B.y;
    }

    point operator - (const point &B) const
    {
        return point (x - B.x, y - B.y, isPlanet);
    }

    point operator + (const point &B) const
    {
        return point (x + B.x, y + B.y, isPlanet);
    }

    void print()
    {
        printf ("x: %d y: %d\n", x, y);
    }
};

bool locket;

struct compare
{
    point p;

    compare () { }
    compare (const point &_p) { p = _p; }

    bool operator () (const point &A, const point &B)
    {
        point a1 = A - p;
        point b1 = B - p;

        if (!locket)
            swap (a1, b1);

        return (a1.x * b1.y - a1.y * b1.x > 0);
    }
};

vector <point> t2;
vector <point> points;
int n, m;

int main ()
{
    #undef DEBUG

    //freopen ("in.txt", "r", stdin);

    int A, B;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d", &A, &B);
        points.push_back (point (A, B, true));
    }
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &A, &B);
        points.push_back (point (A, B, false));
    }

    sort (points.begin(), points.end());

    for (int i = 0; i < points.size() - 1; i++)
    {
        if (!points [i].isPlanet)
            continue;

        t2.clear();
        for (int j = i + 1; j < points.size(); j++)
            t2.push_back (points [j]);

        locket = true;
        compare cmp (points [i]); //points [i] -> current planet

        sort (t2.begin(), t2.end(), cmp);

        locket = false;

        #ifdef DEBUG

        printf ("i: %d | ", i); points [i].print();

        printf ("t2:\n");
        for (int i = 0; i < t2.size(); i++)
            t2 [i].print();

        #endif

        int cnt = solution;

        for (int j = 0; j < t2.size() - 1; j++)
        {
            if (t2 [j].isPlanet)
            {
                int cnt1 = solution;
                bool found = false;
                point D, pointB;
                compare p (t2 [j]);

                for (int k = j + 1; k < t2.size(); k++)
                {
                    point A = points [i];
                    point B = t2 [j];
                    point C = t2 [k];
                    if (t2 [k].isPlanet)
                    {
                        if (found)
                            if (p (C, D))
                            {
                                #ifdef DEBUG
                                printf ("| %d\n", k);
                                #endif
                                solution++;
                            }
                        else
                        {
                            #ifdef DEBUG
                            printf ("|| %d\n", k);
                            #endif
                            solution++;
                        }
                    }
                    else
                    {
                        if (!found)
                        {
                            found = true;
                            D = C;
                        }
                        else
                            if (p (D, C))
                                D = C;
                    }

                    #ifdef DEBUG
                    printf ("current black_hole: "); D.print();
                    #endif
                }

                #ifdef DEBUG
                printf ("cnt1: %d\n", solution - cnt1);
                #endif
            }
        }

        #ifdef DEBUG
        printf ("solution: %d\n", solution - cnt);
        #endif
    }

    printf ("%d\n", solution);

    return 0;
}

/*
5 2
1 3
2 1
4 2
5 4
4 6
3 3
2 5
*/






