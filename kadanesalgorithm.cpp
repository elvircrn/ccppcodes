#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 1<<28

int dimensions, cost = INF, matrix [320] [320], sum[320] [320], n, m, k;

int get_range(int x1, int y1, int x2, int y2)
{
    return sum [x2] [y2] - sum [x2] [y1 - 1] - sum [x1 - 1] [y2] + sum [x1 - 1] [y1 - 1];
}


int main()
{
    while (scanf ("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf ("%d", &matrix [i] [j]);
                sum [i] [j] = sum [i - 1] [j] + sum [i] [j - 1] - sum [i - 1] [j - 1] + matrix [i] [j];
            }


        int solution = -INF;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int current = 0;
                for (int k = 1; k <= n; k++)
                {
                    current += get_range (k, i, k, j);
                    solution = max (solution, current);
                    if (current < 0)
                        current = 0;
                }
            }
        }

        printf ("%d\n", solution);
    }

    return 0;
}
