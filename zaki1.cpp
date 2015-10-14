#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dimensions, cost, matrix [320] [320], sum[320] [320], n, m, k;

inline int get_range(int x1, int y1, int x2, int y2)
{
    return sum [x2] [y2] - sum [x2] [y1 - 1] - sum [x1 - 1] [y2] + sum [x1 - 1] [y1 - 1];
}

inline int find (int x1, int y1, int x2, int y2)
{
    int left = x1, right = n, pivot, max_r(0);

    while (left < right)
    {
        pivot = (left + right) / 2;

        int range = get_range (x1, y1, pivot, y2);

        if (range > k)
        {
            right = pivot - 1;
        }
        else
        {
            max_r = max (max_r, pivot);
            left = pivot + 1;
        }
    }

    int dim = (y2 - y1 + 1) * (max_r - x1 + 1), gr = get_range (x1, y1, max_r, y2);

    if (dim > dimensions)
    {
        dimensions = dim;
        cost = gr;
    }
    else if (dim == dimensions && cost > get_range (x1, y1, max_r, y2))
        cost = gr;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    scanf ("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf ("%d", &matrix [i] [j]);
            sum [i] [j] = sum [i - 1] [j] + sum [i] [j - 1] - sum [i - 1] [j - 1] + matrix [i] [j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = j; k <= m; k++)
            {
                find(i, j, i, k);
            }
        }
    }

    printf ("%d %d\n", dimensions, cost);

    return 0;
}
/*
5 6 15
10 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10
*/
