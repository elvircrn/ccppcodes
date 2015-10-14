#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 4611686018427387904

typedef long long int ll;

ll n, m, matrix [200] [200], dp [200] [200], next [200] [200];

ll is  [3] = { 0, 1, -1 };
ll is2 [3] = { 1, -1, 0 };

ll get(ll index)
{
    if (index == 0)
        return n;
    else if (index == n + 1)
        return 1;
    else
        return index;
}

ll solve(ll x, ll y)
{
    x = get(x);

    if (dp [x] [y] != INF)
        return dp [x] [y];

    if (y == m)
    {
        next [x] [y] = x;
        return matrix [x] [y];
    }

    ll minimum = INF;

    if (x == 1)
    {
        for (ll i = 0; i < 3; i++)
        {
            ll s = solve (x + is [i], y + 1) + matrix [x] [y];
            if (minimum > s)
            {
                minimum = s;
                next [x] [y] = get (x + is [i]);
            }
        }
    }
    else if (x == n)
    {
        for (ll i = 0; i < 3; i++)
        {
            ll s = solve (x + is2 [i], y + 1) + matrix [x] [y];
            if (minimum > s)
            {
                minimum = s;
                next [x] [y] = get (x + is2 [i]);
            }
        }
    }
    else
    {
        for (ll i = -1; i < 2; i++)
        {
            ll s = solve (x + i, y + 1) + matrix [x] [y];
            if (minimum > s)
            {
                minimum = s;
                next [x] [y] = get (x + i);
            }
        }
    }

    return (dp [x] [y] = minimum);
}


int main()
{
    freopen ("in.txt", "r", stdin);

    while (scanf ("%lld %lld", &n, &m) == 2)
    {
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                scanf ("%lld", &matrix [i] [j]);


        for (ll i = 0; i < n + 5; i++)
            for (ll j = 0; j < m + 5; j++)
                dp [i] [j] = INF;

        ll minimum = INF, start_index;

        for (ll i = 1; i <= n; i++)
        {
            dp [i] [1] = solve (i, 1);

            //cout<<dp [i] [1]<<endl;

            if (dp [i] [1] < minimum)
            {
                minimum = dp [i] [1];
                start_index = i;
            }
        }

        ll cnt = matrix [start_index] [1];

        printf ("%d", start_index);

        for (ll i = 1; i < m; i++)
        {
            start_index = next [start_index] [i];
            printf (" %lld", start_index);
            cnt += matrix [start_index] [i];
        }

        printf ("\n%lld\n", minimum);
    }

    return 0;
}























