#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool cmp (long long int A, long long int B)
{
    long long int AB = A, BA = B, tA = A, tB = B;

    while (tB)
    {
        AB *= 10;
        tB /= 10;
    }

    AB += B;

    while (tA)
    {
        BA *= 10;
        tA /= 10;
    }

    BA += A;

    return AB < BA;
}

long long int array [5001], n;

int main ()
{
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lld", &array [i]);

    sort (array, array + n, cmp);

    for (int i = 0; i < n; i++)
        printf ("%lld", array [i]); printf ("\n");

    return 0;
}
