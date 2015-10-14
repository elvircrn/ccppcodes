#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long int n, m, array [1000100], LEFT, RIGHT, pivot, counter, solution;

int main ()
{
    scanf ("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &array [i]);
        RIGHT = max (array [i], RIGHT);
    }

    while (LEFT <= RIGHT)
    {
        pivot = (LEFT + RIGHT) / 2;

        counter = 0;

        for (int i = 0; i < n; i++)
            if (array [i] - pivot > 0)
                counter += array [i] - pivot;

        if (counter < m)
            RIGHT = pivot - 1;
        else
        {
            solution = pivot;
            LEFT = pivot + 1;
        }
    }

    printf ("%lld\n", solution);

    return 0;
}
