#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [1000];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
    }

    sort (array, array + n);

    bool found = true;
    while (found)
    {
        found = false;
        for (int i = n - 1; i >= 1; i--)
        {
            if (array [i] > array [i - 1] && array [i - 1])
            {
                array [i] -= array [i - 1];
                found = true;
            }
        }
        sort (array, array + n);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += array [i];

    printf ("%d\n", sum);

    return 0;
}










