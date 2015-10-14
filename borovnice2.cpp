#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

long long int cnt, n, q, A, borovnice [100001], sum, Q, maximum;

int main ()
{
    scanf ("%lld %lld", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &borovnice [i]);
        sum += borovnice [i];
    }

    for (int i = 0; i < n; i++)
    {
        A += borovnice [i];
        maximum = max (maximum, min (A, sum - A));
    }

    for (int i = 0; i < q; i++)
    {
        scanf ("%lld", &Q);
        if (Q >= maximum)
            printf ("n\n");
        else
            printf ("d\n");
    }

    return 0;
}
//1a019e3d3bed8b9
