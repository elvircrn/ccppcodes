#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m, Size [50100], parent [50100], solution, solution_index;
bool visited [50100];

int Find (int x)
{
    if (parent [x] == x)
        return x;
    else
        return parent [x] = Find (parent [x]);
}

void Union (int x, int y)
{
    int fX = Find (x), fY = Find (y);

    if (fX == fY)
        return;

    if (Size [fX] > Size [fY])
    {
        parent [fY] = fX;
        Size [fX] += Size [fY];
        Size [fY] = 0;
    }
    else
    {
        parent [fX] = fY;
        Size [fY] += Size [fX];
        Size [fX] = 0;
    }
}

int main ()
{
    int x, y;

    for (int i = 0; i <= 50010; i++)
    {
        Size [i] = 1;
        parent [i] = i;
    }

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &x, &y);
        visited [x] = true;
        visited [y] = true;
        Union (x, y);
    }

    for (int i = n; i >= 1; i--)
    {
        if (visited [i] && solution < Size [Find (i)])
        {
            solution = Size [Find (i)];
            solution_index = i;
        }
    }

    printf ("%d\n", solution);

    return 0;
}
