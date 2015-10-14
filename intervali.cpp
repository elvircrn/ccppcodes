#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct interval
{
    int x, y;

    bool operator < (const interval & xx) const
    {
        return y < xx.y;
    }
};

int n, skroz_desno, solution = 1;
interval intervali [5001];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &intervali [i].x, &intervali [i].y);

    sort (intervali, intervali + n);

    skroz_desno = intervali [0].y;

    for (int i = 1; i < n; i++)
    {
        if (skroz_desno <= intervali [i].x)
        {
            skroz_desno = intervali [i].y;
            solution++;
        }
    }

    printf ("%d\n", solution);

    return 0;
}
