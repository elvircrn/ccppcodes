#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<int, bool> exists;
int n, l, x, y, a [120000];
bool foundx, foundy;

int main()
{
    scanf ("%d %d %d %d", &n, &l, &x, &y);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a [i]);
        exists[a [i]] = true;

        if (a [i] == x)
            foundx = true;
        if (a [i] == y)
            foundy = true;

        if (a [i] - x >= 0 && exists [a [i] - x])
            foundx = true;

        if (a [i] - y >= 0 && exists [a [i] - y])
            foundy = true;
    }

    if (foundx && foundy)
        printf ("0\n");
    else if (foundx != foundy)
    {
        if (!foundx)
            printf ("1\n%d\n", x);
        else
            printf ("1\n%d\n", y);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a [i] - (x + y) >= 0 && exists [a [i] - (x + y)])
            {
                printf ("1\n%d\n", a [i] - x);
                return 0;
            }
            else if (a [i] - y + x <= l && a [i] - y >= 0 && exists [a [i] + x - y])
            {
                printf ("1\n%d", a [i] - y);
                return 0;
            }
            else if (a [i] - x + y <= l && a [i] - x >= 0 && exists [a [i] + y - x])
            {
                printf ("1\n%d\n", a [i] - x);
                return 0;
            }

            if (exists [a [i] - x] && a [i] + y <= l)
            {
                printf ("1\n%d\n", a [i] + y);
                return 0;
            }
            else if (exists [a [i] - y] && a [i] + x)
            {
                printf ("1\n%d\n", a [i] + x);
                return 0;
            }
        }

        printf ("2\n%d %d", x, y);
    }

    return 0;
}

/*
case 1:
3 250 185 230
0 185 250

case 2:
4 250 185 230
0 20 185 250

case 3:
2 300 185 230
0 300

case 4:
4 10 2 5
0 3 5 10

4 100 3 8
0 1 6 100

3 10 3 4
0 1 10
*/































