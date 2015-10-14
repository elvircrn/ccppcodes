#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MOD 1000000007
#define TYPE long long int

TYPE fast_pow (TYPE base, TYPE power, TYPE mod)
{
    if (base == 0)
        return 1;
    else if (power == 1)
        return base % mod;
    if (power % 2 == 0)
    {
        TYPE t = fast_pow (base, power / 2, mod) % mod;
        return ((t * t) % mod);
    }
    else
    {
        return ((fast_pow (base, power - 1, mod) % mod) * (base % mod)) % mod;
    }
}

TYPE n, q, index, element, array [100005], product = 1;

int main ()
{
    scanf ("%lld %lld", &n, &q);
    for (TYPE i = 1; i <= n; i++)
    {
        scanf ("%lld", &array [i]);
        product *= (array [i] % MOD);
        product %= MOD;

    }

    while (q--)
    {
        scanf ("%lld %lld", &index, &element);
        product = ((product % MOD) * (fast_pow (array [index], MOD - 2, MOD) % MOD)) % MOD;
        product = (product % MOD) * (element % MOD);
        product %= MOD;
        array [index] = element;
        printf ("%lld\n", product);
    }

    return 0;
}








