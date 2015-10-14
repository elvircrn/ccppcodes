#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

/*
1
20 3
3 4 6 8
2 5 10
4 1 3 5 5
*/

using namespace std;

vector <int> prices [100];
int m, c, t, dummy, in, dp [500] [500];

int solve(int money_used, int current_index)
{
    if (money_used < 0)
        return -10000;

    if (current_index == c)
        return m - money_used;

    if (dp [money_used] [current_index] != -1)
        return dp [money_used] [current_index];

    int maximum = -10000;

    for (int i = 0; i < prices [current_index].size(); i++)
        maximum = max (maximum, solve (money_used - prices [current_index] [i], current_index + 1));

    return dp [money_used] [current_index] = maximum;
}

void clear_case()
{
    memset (dp, -1, sizeof dp);
    for (int i = 0; i < 100; i++)
        prices [i].clear();
}

int main ()
{
    memset (dp, -1, sizeof dp);
    scanf ("%d", &t);

    while (t--)
    {
        scanf ("%d %d", &m, &c);
        for (int i = 0; i < c; i++)
        {
            scanf ("%d", &dummy);
            while (dummy--)
            {
                scanf ("%d", &in);
                prices [i].push_back (in);
            }
        }

        dp [m] [0] = solve (m, 0);

        if (dp [m] [0] > 0)
            printf ("%d\n", dp [m] [0]);
        else
            printf ("no solution\n");

        clear_case();
    }

    return 0;
}
/*
1
200 20
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 181 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 180
*/
