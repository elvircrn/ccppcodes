#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 100000.00
#define MALO 0.000001

float myabs (float x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

bool equal (float a, float b)
{
    return (myabs (a - b) < MALO);
}

struct point
{
    float x, y;

    point () { }
    point (float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    void get()
    {
        scanf ("%f %f", &x, &y);
    }

    void print()
    {
        printf ("%f %f\n", x, y);
    }
};

struct line
{
    float n, k;

    line () { }
    line (float _n, float _k)
    {
        n = _n;
        k = _k;
    }

    void get()
    {
        scanf ("%f %f", &n, &k);
    }

    void print()
    {
        printf ("%f %f\n", n, k);
    }

    bool operator < (const line &B) const
    {
        if (!equal (k, B.k))
            return k < B.k;
        else
            return n < B.n;
    }

    bool operator != (const line &B) const
    {
        return (!equal (k, B.k) || !equal (n, B.n));
    }
};

float getK (const point &A, const point &B)
{
    if (equal (A.x, B.x))
        return INF;
    if (equal (A.y, B.y))
        return INF + 5;

    return float (float (B.y - A.y) / float (B.x - A.x));
}

float getN (const point &A, const point &B)
{
    return float (A.y - (getK (A, B) * A.x));
}

line get_line (const point &A, const point &B)
{
    return line (getN (A, B), getK (A, B));
}

int n, solution;
bool visited [200];
point points [200];
vector <line> lines;

int main ()
{
    get_line (point (1, 1), point (1, 2)).print();
    get_line (point (1, 2), point (1, 3)).print();
    /*
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        points [i].get();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            lines.push_back (get_line (points [i], points [j]));

    sort (lines.begin(), lines.end());

    solution = 1;

    for (int i = 1; i < lines.size(); i++)
        if (lines [i - 1] != lines [i])
            solution++;

    printf ("%d\n", solution);
    */

    return 0;
}

