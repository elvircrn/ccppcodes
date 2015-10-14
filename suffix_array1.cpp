#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
//GATAGACA
char word [150000];
int power, n, SA [150000], RA [150000];

bool cmp(int A, int B)
{
    if (RA [A] != RA [B])
        return RA [A] < RA [B];

    if (A + power >= n || B + power >= n)
    {
        return A > B;
    }
    else
        return RA [A + power] < RA [B + power];
}

int main()
{
    scanf ("%s", &word);
    n = strlen (word);

    for (int i = 0; i < n; i++)
    {
        SA [i] = i;
        RA [i] = word [i] - '.';
    }

    for (power = 1; power <= n; power *= 2)
    {
        sort (SA, SA + n, cmp);

        int inc(0);

        RA [SA [0]] = inc;

        for (int i = 1; i < n; i++)
        {
            if (cmp (SA [i - 1], SA [i]))
                inc++;
            RA [SA [i]] = inc;
        }

        for (int i = 0; i < n; i++)
            printf ("SA [i]: %d %s\n", SA [i], word + SA [i]);
        printf ("\n");
        system ("pause");
        printf ("\n");
    }

    for (int i = 0; i < n; i++)
        printf ("%d %s\n", SA [i], word + SA [i]);


    return 0;
}
//GATAGACA
















