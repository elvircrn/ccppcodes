#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define INF 1<<28

int n, b1, b2;

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }

    void print() const
    {
        printf ("x: %d y: %d\n", x, y);
    }

    int d(const point &B) const
    {
        return (x - B.x) * (x - B.x) + (y - B.y) * (y - B.y);
    }

    double dist(const point &B) const
    {
        return (double)sqrt((double)d(B));
    }
};


point points [200];
int child [200] [200];
double dp [200] [200];

double solve(int i, int j)
{
    int next = max (i, j) + 1;

    //base cases:

    if (dp [i] [j] != -1)
        return dp [i] [j];

    if (next == n - 1)
    {
        child [i] [j] = -1;
        return dp [i] [j] = points [i].dist(points [n - 1]) + points [j].dist(points [n - 1]);
    }

    if (next == b1)
    {
        child [i] [j] = -1;
        return dp [i] [j] = solve (next, j) + points [i].dist(points [next]);
    }
    else if (next == b2)
    {
        child [i] [j] = 1;
        return dp [i] [j] = solve (i, next) + points [j].dist(points [next]);
    }
    else
    {
        double d1 = points [i].dist(points [next]) + solve(next, j); // advance 1
        double d2 = points [j].dist(points [next]) + solve(i, next); //advance 2

        if (d1 < d2)
        {
            child [i] [j] = -1;
            return dp [i] [j] = d1;
        }
        else
        {
            child [i] [j] = 1;
            return dp [i] [j] = d2;
        }
    }
}

vector <int> solution1;
vector <int> solution2;
vector <int> SOL;

int main()
{
    //freopen ("in.txt", "r", stdin);

    int test_id = 1;

    while (scanf ("%d %d %d", &n, &b1, &b2) == 3 && (n || b1 || b2))
    {
        SOL.clear();
        double solution = 0.0f;

        solution1.clear();
        solution2.clear();

        for (int i = 0; i < n; i++)
            points [i].get();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp [i] [j] = -1;

        solve(0, 0);

        int lA = 0, lB = 0;

        while (max (lA, lB) + 1 != n)
        {
            if (child [lA] [lB] == -1)
            {
                solution1.push_back (max (lA, lB) + 1);
                lA = max(lA, lB) + 1;
            }
            else if (child [lA] [lB] == 1)
            {
                lB = max(lA, lB) + 1;
            }
        }

        lA = 0;
        lB = 0;

        while (lA != n - 1 && lB != n - 1)
        {
            if (child [lA] [lB] == -1)
            {
                lA = max(lA, lB) + 1;
            }
            else if (child [lA] [lB] == 1)
            {
                solution2.push_back (max (lA, lB) + 1);
                lB = max(lA, lB) + 1;
            }
        }

        if (solution1 [0] != 1)
        {
            swap (solution1, solution2);

            for (int i = solution2.size() - 1; i > -1; i--)
                solution1.push_back (solution2 [i]);

            SOL.push_back(0);

            for (int i = 0; i < solution1.size(); i++)
                SOL.push_back (solution1 [i]);

            SOL.push_back(0);

            for (int i = 1; i < SOL.size(); i++)
                solution += points [SOL [i - 1]].dist(points [SOL [i]]);

            printf ("Case %d: %.2lf\n", test_id++, solution);

            printf ("0");

            for (int i = 1; i < SOL.size(); i++)
                printf (" %d", SOL [i]); printf ("\n");
        }
        else
        {
            for (int i = solution2.size() - 1; i > -1; i--)
                solution1.push_back (solution2 [i]);

            SOL.push_back(0);

            for (int i = 0; i < solution1.size(); i++)
                SOL.push_back (solution1 [i]);

            SOL.push_back(0);

            for (int i = 1; i < SOL.size(); i++)
                solution += points [SOL [i - 1]].dist(points [SOL [i]]);

            printf ("Case %d: %.2lf\n", test_id++, solution);

            printf ("0");

            for (int i = 1; i < SOL.size(); i++)
                printf (" %d", SOL [i]); printf ("\n");
        }
    }

    return 0;
}


















