#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ll;

#define INF  100000000LL
#define MALO -1000

//#define DEBUG

ll solution, range_min, range_max, array [40], n, global;

vector <ll> first_set;
vector <ll> second_set;

vector <ll> fs;
vector <ll> ss;

ll left_bound(ll index)
{
    ll found(INF), left(0), right(second_set.size() - 1), pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (second_set [pivot] + first_set [index] < range_min)
            left = pivot + 1;
        else if (second_set [pivot] + first_set [index] >= range_min && second_set [pivot] + first_set [index] <= range_max)
        {
            found = pivot;
            right = pivot - 1;
        }
        else if (second_set [pivot] + first_set [index] > range_max)
            right = pivot - 1;
    }

    return found;
}

ll right_bound(ll index)
{
    ll found(INF), left(0), right(second_set.size() - 1), pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (second_set [pivot] + first_set [index] < range_min)
            left = pivot + 1;
        else if (second_set [pivot] + first_set [index] >= range_min && second_set [pivot] + first_set [index] <= range_max)
        {
            found = pivot;
            left = pivot + 1;
        }
        else
            right = pivot - 1;
    }

    return found;
}

int main()
{
    scanf ("%lld %lld %lld", &n, &range_min, &range_max);

    if (n == 1)
    {
        printf ("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        scanf ("%lld", &array [i]);

    sort (array, array + n);

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            fs.push_back (array [i]);
        else
            ss.push_back (array [i]);
    }

    for (int i = 0; i < (1<<fs.size()); i++)
    {
        ll cnt = 0;
        for (int j = 0; j < 32; j++)
        {
            if (i & (1<<j))
                cnt += fs [j];
        }
        first_set.push_back (cnt);
    }

    for (int i = 1; i < (1<<ss.size()); i++)
    {
        ll cnt = 0;
        for (int j = 0; j < 32; j++)
        {
            if (i & (1<<j))
                cnt += ss [j];
        }
        second_set.push_back (cnt);
    }

    sort (first_set.begin(), first_set.end());
    sort (second_set.begin(), second_set.end());

    ll l_bound, r_bound;

    solution = 0LL;

    for (int i = 0; i < first_set.size(); i++)
    {
        l_bound = left_bound(i);
        r_bound = right_bound(i);

        if (l_bound == INF || r_bound == INF)
            continue;

        solution += (r_bound - l_bound + 1);
    }

    for (int i = 0; i < first_set.size(); i++)
        if (range_min <= first_set [i] && first_set [i] <= range_max)
            solution++;

    printf ("%lld\n", solution);

    return 0;
}

