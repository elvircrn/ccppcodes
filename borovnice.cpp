#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int t, q, array [200020], n, total_sum, solution = 0;

int main ()
{
    scanf ("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        total_sum += array [i];
    }

    int progress = 0;

    int i;

    for (i = 0; i < n; i++)
    {
        progress += array [i];

        if (progress >= total_sum - progress)
            break;
    }

    solution = min (total_sum - progress, progress);

    progress = 0;
    for (i = n - 1; i >= 0; i--)
    {
        progress += array [i];
        if (progress >= total_sum - progress)
            break;
    }

    solution = max (solution, min (total_sum - progress, progress));

    //printf ("%d\n", solution);

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
