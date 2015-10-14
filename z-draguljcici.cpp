#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1<<29

long long int n, m, slovo [101], dp [100001], solution, number_of_ways;

int main ()
{
    scanf ("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++)
        scanf ("%lld", &slovo [i]);

    sort (slovo, slovo + m);

    for (int i = 1; i < slovo [0]; i++)
        dp [i] = INF;

    if (slovo [0] <= n) dp [slovo [0]] = 1;
    dp [0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < slovo [j])
            {
                break;
            }

            if (dp [i - slovo [j]] != INF)
            {
                if (dp [i] == INF)
                {
                    dp [i] = 0;
                }

                dp [i] += (dp [i - slovo [j]]) % 8192;
                dp [i] %= 8192;
            }
        }

        if (dp [i] != INF)
            number_of_ways += dp [i];

        number_of_ways %= 8192;
    }

    printf ("%lld\n", (number_of_ways + dp [slovo [0]]) % 8192);

    return 0;
}
