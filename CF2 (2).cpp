#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long int total, a [100100], b [100100], n;
int main()
{
    scanf ("%I64d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%I64d", &a [i]);
    for (int i = 0; i < n; i++)
        scanf ("%I64d", &b [i]);
    for (int i = 0; i < n; i++)
    {
        long long int asd = total;
        if (a [i] == 1 && b [i] == 2)
            total++;
        else if (a [i] != 1)
        {
            if (b [i] % 2 == 0)
            {
                if (b [i] / 2 <= a [i])
                    total += (b [i] * b [i]) / 4;
            }
            else
            {
                long long int rA = b [i] / 2, rB = b [i] / 2 + 1;
                if (rA <= a [i] && rB <= a [i])
                    total += rA * rB;
            }

        }

        if (asd == total)
            total--;
    }

    printf ("%I64d\n", total);

    return 0;
}
