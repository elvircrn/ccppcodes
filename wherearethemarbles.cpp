#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, q, array [20000];

int binary_search(int value)
{
    int left = 0, right = n - 1, location = -1, pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (value < array [pivot])
        {
            right = pivot - 1;
        }
        else if (value > array [pivot])
        {
            left = pivot + 1;
        }
        else
        {
            location = pivot;
            right = pivot - 1;
        }
    }

    return location;
}

int main ()
{
    int x;

    scanf ("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    sort (array, array + n);

    while (q--)
    {
        scanf ("%d", &x);
        printf ("%d\n",     )
    }

    return 0;
}
