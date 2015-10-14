#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int t, q, array [200000], n, total_sum, solution = 0;

int main ()
{
    scanf ("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        total_sum += array [i];
    }

    int progress = 0;

    for (int i = 0; i < n; i++)
    {
        progress += array [i];
        solution = max (solution, min (progress, total_sum - progress));
    }

    while (q--)
    {
        scanf ("%d", &t);
        if (t < solution)
            printf ("d\n");
        else
            printf ("n\n");
    }

    return 0;
}
