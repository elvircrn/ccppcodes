#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [110000], array2 [110000];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    memcpy (array2, array, n);

    sort (array2, array2 + n);

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (array [i] == array2 [i])
                continue;
            if (array [i] < array2 [j])
                break;

            if (array [i] % array [j] == 0)
                cnt++;
        }

        printf ("%d\n", cnt - 1);
    }

    return 0;
}
