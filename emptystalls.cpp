#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ll;

ll cows[3000100];
ll n, k, d[3000100];
bool visited[3000100];
int main()
{
    scanf ("%lld %lld", &n, &k);
    for (int i = 0; i < k; i++)
    {
        ll a, b, x, y;
        scanf ("%lld %lld %lld %lld", &x, &y, &a, &b);

        for (int j = 1; j <= y; j++)
            cows [(a * j + b) % n] += x;
    }

    ll current_sum = 0LL;

    for (int current_index = 0; current_index < 2 * n; current_index++)
    {
        int i = current_index % n;
        if (cows [i])
        {
            current_sum += cows [i] - 1;
            cows [i] = 1;
        }
        else if (!cows [i] && current_sum > 0)
        {
            cows [i] = 1;
            current_sum--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!cows [i])
        {
            printf ("%d", i);
            return 0;
        }
    }

    return 0;
}

/*
5
1 1 H
2 2 H
3 3 G
4 4 H
6 6 H
*/





















