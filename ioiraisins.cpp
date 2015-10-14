#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, sum_to [51] [51], raisins [51] [51], dp [51] [51] [51] [51];

int get_region (int a, int b, int c, int d)
{
    return sum_to [c] [d] - (sum_to [a - 1] [d] + sum_to [c] [b - 1]) + sum_to [a - 1] [b - 1];
}

int solve (int x1, int y1, int x2, int y2)
{
    if (dp [x1] [y1] [x2] [y2] == -1)
    {
        int best = INT_MAX;

        //colums
        for (int y = y1; y < y2; y++)
            best = min (best, solve (x1, y1, x2, y) + solve (x1, y + 1, x2, y2));

        //rows
        for (int x = x1; x < x2; x++)
            best = min (best, solve (x1, y1, x, y2) + solve (x + 1, y1, x2, y2));

        dp [x1] [y1] [x2] [y2] = best + get_region (x1, y1, x2, y2);
    }

    return dp [
    x1] [y1] [x2] [y2];
}

int main ()
{
    memset (dp, -1, sizeof dp);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf ("%d", &raisins [i] [j]);
            dp [i] [j] [i] [j] = 0;
            sum_to [i] [j] = (sum_to [i - 1] [j] + sum_to [i] [j - 1]) - sum_to [i - 1] [j - 1] + raisins [i] [j];
        }
    }

    printf ("%d\n", solve (1, 1, n, m));

    return 0;
}





