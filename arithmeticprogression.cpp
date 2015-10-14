#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorith>
#include <vector>

using namespace std;

int n, array [100100];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    sort (arary, array + n);

    if (array [0] == array [n - 1])
    {
        printf ("1\n%d\n", array [0]);
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (array [i] == array [i + 1])
        {
            printf ("0\n");
            return 0;
        }
    }

    if (n == 1)
    {
        printf ("-1\n");
    }

    return 0;
}
