#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int dX [3] = { -1, 0, 1 };
int dY [3] = { 1, 1, 1 };

int solution, n, m;
char line [510];
bool matrix [10010] [510];

bool check (int pX, int pY)
{
    if (!pX || !pY || pX > n || pY > m)
        return false;
    return !matrix [pX] [pY];
}

bool found;

void solve (int pX, int pY)
{
    matrix [pX] [pY] = 1;
    if (found)
        return;

    if (pY == m)
    {
        matrix [pX] [pY] = 1;
        found = true;
        solution++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        int X = pX + dX [i], Y = pY + dY [i];
        if (check (X, Y))
            solve (X, Y);
        if (found)
            return;
    }
}

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &line);
        for (int j = 0; j < m; j++)
            if (line [j] == 'x')
                matrix [i + 1] [j + 1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        found = false;
        solve (i, 1);
    }

    printf ("%d\n", solution);

    return 0;
}

