#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m, hash1 [1000100], hash2 [1000100], array1 [3100], array2 [3200];

int main()
{
    int max_prob(0);
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array1 [i]);
        hash1 [array1 [i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        scanf ("%d", &array2 [i]);
        hash2 [array2 [i]]++;
        max_prob = max (max_prob, array2 [i]);
    }

    int cnt = n;

    for (int i = 0; i < n; i++)
    {
        if (hash2 [array1 [i]])
            cnt--;
    }

    if (cnt == 0)
    {
        printf ("0\n");
        return 0;
    }

    cnt = 0;

    sort (array1, array1 + n);
    sort (array2, array2 + m);

    int nn = n - 1, mm = m - 1;

    while (mm >= 0 && nn >= 0)
    {
        if (array1 [nn] <= array2 [mm])
        {
            cnt++;
            mm--;
        }
        nn--;
    }

    printf ("%d\n", n - cnt);

    return 0;
}
