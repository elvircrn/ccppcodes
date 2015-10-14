#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int e, v, taken = 0, parent [200000], size [200000];

struct edge
{
    int n, m, w;

    edge () { }
    edge (int _n, int _m, int _w) { n = _n; m = _m; w = _w; }

    bool operator < (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> edges;

void Union (int A, int B)
{
    int fA = Find (A);
    int fB = Find (B);

    if (fA == fB)
        return;
    else
        if (size [fA] < size [fB])
            parent [fA] = fB;
        else
            parent [fB] = fA;
}

int Find (int index)
{
    if (parent [index] == index)
        return index;
    else
        parent [index] = Find (parent [index]);
}

int main ()
{
    int a, b, c;

    scanf ("%d %d", &e, &v);

    memset (parent, 1, sizeof parent);
    memset (size, 1, sizeof size);

    for (int i = 0; i < e; i++)
    {
        scanf ("%d %d %d", &a, &b, &c);
        edges.push_back (edge (a, b, c));
    }

    sort (edges.begin(), edges.end());

    for (int i = 0; i < e && taken < e; i++)
    {

    }

    return 0;
}
/*
11 7
1 4 5
1 2 7
2 4 9
2 5 7
2 3 8
3 5 5
4 5 15
4 6 6
5 6 8
7 8 11
5 8 9
*/



