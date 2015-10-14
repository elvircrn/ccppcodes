#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int a, size [101010], parent [101010], n;


int Find (int x)
{
    if (parent [x] == x)
        return x;
    else
        return parent [x] = Find (parent [x]);
}
void Union (int x, int y)
{
    int fX = Find (x);
    int fY = Find (y);

    if (size [fX] < size [fY])
    {
        size [fY] += size [fX];
        parent [fX] = fY;
    }
    else
    {
        size [fX] += size [fY];
        parent [fY] = fX;
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i <= n; i++)
        size [i] = 1;
    for (int i = 0; i <= n; i++)
        parent [i] = i;

    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &a);
        Union (i, a);
    }

    for (int i = 1; i <= n; i++)
        printf ("%d\n", size [i]);


    return 0;
}
