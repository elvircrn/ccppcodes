#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int myAbs (int x)
{
    return (x < 0) ? x * (-1) : x;
}

int array [1000], t, n, Left = 1000000, Right = -1;

void clear_case()
{
    Left = 1000000;
    Right = -1;
}

int main ()
{

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
            scanf ("%d", &array [i]);

        int solution = 0;

        sort (array, array + n);

        for (int i = 0; i < n; i++)
            solution += myAbs (array [n / 2] - array [i]);

        printf ("%d\n", solution);
    }

    return 0;
}
