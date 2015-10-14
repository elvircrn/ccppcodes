#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c;

int main()
{
    scanf ("%d %d %d", &a, &b, &c);

    while (a || b || c)
    {
        if (2 * b == a + c)
            printf ("AP %d\n", c + (b - a));
        else
            printf ("GP %d\n", c * (b / a));

        scanf ("%d %d %d", &a, &b, &c);
    }

    return 0;
}
