#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

char s1[400000], s2 [2000];
int power, RA [400000], SA [400000], pos [400000], len1, len2, n, m;

bool cmp (int A, int B)
{
    if (pos [A] != pos [B])
        return pos [A] < pos [B];

    if (A + power >= n || B + power >= n)
        return A > B;
    else
        return pos [A + power] < pos [B + power];
}

int main()
{
    scanf ("%s %s", &s1, &s2);

    n = strlen (s1);
    m = strlen (s2);

    for (int i = 0; i < n; i++)
    {
        SA [i] = i;
        pos [i] = s1 [i];
    }

    for (power = 1; power < n; power++)
    {
        sort (SA, SA + n, cmp);

        for (int i = 0; i < n - 1; i++)
            RA [i + 1] = RA [i] + cmp (SA [i], SA [i + 1]);
        for (int i = 0; i < n; i++)
            pos [SA [i]] = RA [i];
    }

    for (int i = 0; i < n; i++)
        printf ("%s\n", s1 + SA [i]);

    int left(0), right (n - 1), pivot, min_index(n), max_index(0);

    while (left <= right)
    {
        pivot = (left + right) / 2;

        int res = strncmp (s1 + SA [pivot], s2, m);

        if (res == 0)
        {
            min_index = min (min_index, pivot);
            right = pivot - 1;
        }
        else if (res > 0)
            left = pivot + 1;
        else
            right = pivot - 1;
    }

    left = 0;
    right = n - 1;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        int res = strncmp (s1 + SA [pivot], s2, m);

        if (res == 0)
        {
            max_index = max (max_index, pivot);
            left = pivot + 1;
        }
        else if (res > 0)
            left = pivot + 1;
        else
            right = pivot - 1;
    }



    return 0;
}






