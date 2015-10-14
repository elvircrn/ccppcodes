#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

long long int TIME [1000100], tmin = 3000000, tmax, n, a, b, sol1, sol2, cnt1, cnt2;

int main ()
{

    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld %lld", &a, &b);
        tmin = min (tmin, min (a, b));
        tmax = max (tmax, max (a, b));
        TIME [a]++;
        TIME [b + 1]--;
    }

    int counter = 0;

    for (int i = tmin; i <= tmax; i++)
    {
        counter += TIME [i];

        if (counter != 0)
        {
            cnt2 = 0;
            cnt1++;
            sol1 = max (cnt1, sol1);
        }
        else
        {
            cnt2++;
            cnt1 = 0;
            sol2 = max (sol2, cnt2);
        }
    }

    printf ("%d %d\n", sol1, sol2);

    return 0;
}
