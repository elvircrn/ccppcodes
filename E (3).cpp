#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const long long int MOD = 1000000007;

typedef long long int ll;

ll s, n, f [21];

bool check (int bitmask, int index)
{
    return bitmask & (1<<index);
}

ll fast_pow (ll base, ll power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return base % MOD;

    if (power % 2 == 0)
    {
        ll t = fast_pow (base, power / 2) % MOD;
        return (t * t) % MOD;
    }
    else
        return ((fast_pow (base, power - 1) % MOD) * (base % MOD)) % MOD;
}

ll solve(ll mask)
{
    int counter = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (check (mask, i))
        {
            printf ("%d ", f [i]);
            sum += f [i];
        }
    }


    printf ("\n");

    if (sum < s)
        return 0;
    if (sum == s)
        return 1;

    int excess = sum - s;

    ll ret = 1;

    for (int i = 0; i < excess; i++)
        ret *= (sum - excess);

    return ret;

    return fast_pow (2LL, sum - s);
}

int main()
{
    ll solution = 0;
    cin>>n>>s;
    for (int i = 0; i < n; i++)
        cin>>f [i];

    int mask = (1<<n);

    for (int i = 0; i < mask; i++)
    {
        ll res = solve (i);
        printf ("res: %lld\n", res);
        solution += res;
    }

    printf ("%lld\n", solution);

    return 0;
}
