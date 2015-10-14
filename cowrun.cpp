#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define INF 1<<30

bool zero;
long long int n, dp [1010] [1010] [2];
vector <long long int> locations;

long long int solution(long long int l, long long int r, bool p)
{
    if (l == 0 && r == locations.size() - 1)
        return 0;

    if (dp [l] [r] [p] != -1)
        return dp [l] [r] [p];

    long long int combo = (locations.size() - (r - l + 1));

    if (p == 0)
    {
        long long int p1 = INF, p2 = INF;

        if (r < locations.size() - 1)
            p1 = solution (l, r + 1, 1) + combo * abs (locations [l] - locations [r + 1]);
        if (l > 0)
            p2 = solution (l - 1, r, 0) + combo * abs (locations [l] - locations [l - 1]);

        dp [l] [r] [p] = min (p1, p2);
    }
    else
    {
        long long int p1 = INF, p2 = INF;

        if (r < locations.size() - 1)
            p1 = solution (l, r + 1, 1) + combo * abs (locations [r] - locations [r + 1]);
        if (l > 0)
            p2 = solution (l - 1, r, 0) + combo * abs (locations [r] - locations [l - 1]);

        dp [l] [r] [p] = min (p1, p2);
    }

    return dp [l] [r] [p];
}

int main()
{
    freopen ("14.in", "r", stdin);

    locations.push_back(0);

    scanf ("%lld", &n);

    for (long long int i = 0; i < n; i++)
    {
        long long int x;
        scanf ("%lld", &x);
        zero |= (x == 0);
        locations.push_back(x);
    }

    memset (dp, -1, sizeof dp);

    if (!zero)
        locations.push_back(0);

    sort(locations.begin(), locations.end());

    for (long long int i = 0; i < locations.size(); i++)
    {
        if (locations [i] == 0)
        {
            printf ("%lld\n", solution (i, i, 0));
            return 0;
        }
    }

    return 0;
}
/*
4
-2
-12
3
7
*/









































