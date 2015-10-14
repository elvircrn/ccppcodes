#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long int ll;

ll array [10100], n, t, sum_to [10100], solution;

int main()
{
    scanf ("%lld", &t);
    while (t--)
    {
        scanf ("%lld", &n);
        for (int i = 0; i < n; i++)
        {
            scanf ("%lld", &array [i]);
            if (i == 0)
                sum_to [0] = array [0];
            else
                sum_to [i] = array [i] + sum_to [i - 1];
        }

        solution = 0;

        for (int i = 0; i < n - 1; i++)
            solution += (sum_to [n - 1] - sum_to [i]) - (n - 1 - i) * array [i];

        printf ("%lld\n", solution);
    }

    return 0;
}
