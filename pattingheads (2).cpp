#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [100100], maximum, counter [1000100], solution [1000100];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        maximum = max (array [i], maximum);
        solution [array [i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (array [i] == 1)
        {
            counter [1]++;
            continue;
        }

        if (solution [array [i]])
        {
            for (int j = array [i]; j <= maximum; j += array [i])
                counter [j] += solution [array [i]];

            solution [array [i]] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        if (array [i] > 1)
            printf ("%d\n", counter [array [i]] - 1 + counter [1]);
        else
            printf ("%d\n", counter [1] - 1);
    return 0;
}

/**

    A [i] % A [j] == 0

*/
