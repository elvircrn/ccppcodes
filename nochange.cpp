#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int solution, n, k, coins[20], purchases [100100], sum_to [100100], rest, dp [1<<17];

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
        scanf ("%d", &coins [i]);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &purchases [i]);
        if (i == 0)
            sum_to [i] = purchases [i];
        else
            sum_to [i] = sum_to [i - 1] + purchases [i];
    }

    sort (coins, coins + k);

    dp [0] = -1;

    for (int mask = 0; mask < (1<<k); mask++)
    {
        for (int i = 0; i < k; i++)
        {
            if (!((1<<i) & mask))
            {
                int rest, left = dp [mask] + 1, right = n - 1, pivot, index = dp [mask], sol_index = -1;
                //printf ("\ni: %d mask: %d coins [i]: %d\n", i, mask, coins [i]);
                while (left <= right)
                {
                    pivot = (left + right) / 2;
                    //printf ("   left: %d right: %d sum_to: %d\n", left, right, sum_to [pivot] - ((mask == 0) ? 0 : sum_to [index]));

                    if (coins [i] >= sum_to [pivot] - ((mask == 0) ? 0 : sum_to [index]))
                    {
                        sol_index = max (sol_index, pivot);
                        //printf ("   found it\n");
                        left = pivot + 1;
                    }
                    else
                        right = pivot;

                    if (left == right)
                        break;
                }

                //printf ("   sol_index: %d\n", sol_index);

                dp [mask + (1<<i)] = sol_index;

                if (sol_index == n - 1)
                {
                    rest = 0;

                    for (int i = 0; i < k; i++)
                        if (!(mask & (1<<i)))
                            rest += coins [i];

                    solution = max (solution, rest);
                }
            }
        }

        //printf ("finished\n");
    }

    printf ("%d\n", solution);

    return 0;
}
/*
3 6
12
15
10
6
3
3
2
3
7
*/







































