#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct segment
{
    int x, y;

    segment() { }
    segment(int _x, int _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }
};

bool cmpV(const segment &A, const segment &B)
{
    return A.x < B.x;
}

bool cmpH(const segment &A, const segment &B)
{
    return A.y < B.y;
}

int n, solV, solH;
segment segments[100100];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        segments [i].get();

    sort (segments, segments + n, cmpV);
    for (int i = 1; i < n; i++)
    {
        if (segments [i].x != segments [i - 1].x)
            solV++;
    }
    sort (segments, segments + n, cmpH);
    for (int i = 1; i < n; i++)
    {
        if (segments [i].y != segments [i - 1].y)
            solH++;
    }

    printf ("%d\n", min (solH, solV) + 1);

    return 0;
}
