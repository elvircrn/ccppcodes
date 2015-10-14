#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long int dp [5000000], numbers_found, two [5000000], index1 = 1, A, B, pA, pB;

long long int find (long long int n)
{
    long long int cpy = n, depth = 1;

    if (cpy < 1000000 && dp [cpy] != 0)
        return dp [n];

    while (true)
    {
        if (cpy % 2 == 1)
            cpy = 3 * cpy + 1;
        else
            cpy /= 2;
        if (cpy == 1)
            break;
        if (cpy < 1000000)
        {
            if (dp [cpy] != 0)
            {
                break;
            }
        }
        depth++;
    }

    dp [n] = dp [cpy] + depth;
    return dp [n];
}

int main ()
{
    for (long long int i = 0; i <= 20; i++, index1 *= 2)
        dp [index1] = i + 1, two [index1] = i + 1;

    while (scanf ("%lld %lld", &A, &B) == 2)
    {
        pA = A;
        pB = B;
        if (A > B)
            swap (A, B);
        long long int cnt = 0, solution = 0;
        for (int i = 1; i < A; i++) find (i);
        for (int i = A; i <= B; i++)
        {
            solution = max (find (i), solution);
        }
        printf ("%lld %lld %lld\n", pA, pB, solution);
    }

    return 0;
}
