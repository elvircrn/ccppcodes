#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 22;

long long int n, x, sum, pos [30];

int main ()
{
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &x);
        for (int j = 0; j < SIZE; j++)
            if (x & (1<<j)) pos [j]++;
    }

    for (int i = 0; i < SIZE; i++)
        sum += (pos [i] * (n - pos [i])) * (1<<i);

    printf ("%lld\n", sum);

    return 0;
}
