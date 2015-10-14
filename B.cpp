#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ll;

ll A, B, C;

ll fast_pow(ll base, ll power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        ll t = fast_pow(base, power / 2);
        return t * t;
    }
    else
        return base * fast_pow(base, power - 1);
}

ll get_sum(ll number)
{
    ll ret = 0;

    while (number)
    {
        ret += number % 10;
        number /= 10;
    }

    return ret;
}

vector <ll> solution;

int main()
{
    cin>>A>>B>>C;

    for (int i = 1; i <= 81; i++)
    {
        ll right_side = B * fast_pow(i, A) + C;

        if (right_side < 0 || right_side > 1e9)
            continue;

        if (i == get_sum(right_side))
        {
            solution.push_back(right_side);
        }
    }

    sort (solution.begin(), solution.end());

    printf ("%d\n", (ll)solution.size());

    if (solution.size() > 0)
        for (int i = 0; i < solution.size() - 1; i++)
            printf ("%d ", solution [i]);

    if (solution.size() > 0)
    {
        printf ("%d\n", solution [solution.size() - 1]);
    }
    return 0;
}










