#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

ll heights [1001000], helper [1001000], n, m, w;

bool check(ll proposed_height)
{
    for (ll i = 0; i < n; i++)

    ll total = proposed_height, current = 0;
    ll _fill = 0, credit = 0;

    for (ll i = 0; i < n; i++)
    {
        _fill -= (i - w >= 0) ? helper [i - w] : 0;
        if (heights [i] + _fill < proposed_height)
        {
            helper [i] = proposed_height - heights [i] - _fill;
            _fill  += helper [i];
            credit += helper [i];
        }

        if (credit > m)
            return false;
    }


    return true;
}

int main()
{
    scanf ("%I64d %I64d %I64d", &n, &m, &w);
    for (ll i = 0; i < n; i++)
        scanf ("%I64d", &heights [i]);

    ll solution = 0, left = 0, right = 1000000000100LL, pivot;

    while (left <= right)
    {
        memset (helper, 0, sizeof helper);
        pivot = (left + right) / 2;

        if (check (pivot))
        {
            solution = max (solution, pivot);
            left = pivot + 1;
        }
        else
            right = pivot - 1;
    }

    printf ("%I64d\n", solution);


    return 0;
}
