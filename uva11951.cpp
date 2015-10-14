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

void find (int x1, int y1, int x2, int y2)
{
    int left = x1, right = n, pivot, max_r(-1);

    while (left <= right)
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

    if (max_r == -1)
        return;

    int dim = (y2 - y1 + 1) * (max_r - x1 + 1), cst = get_range (x1, y1, max_r, y2);

    if (dim > dimensions)
    {
        dimensions = dim;
        cost = cst;
    }
    else if (dim == dimensions && cost > cst)
        cost = cst;

    return;
}

int main()
{
    //freopen ("in.txt", "r", stdin);

    int case_id = 1, t;

    scanf ("%d", &t);
    while (t--)
    {
        cost = INF;
        dimensions = -1;

        scanf ("%d %d %d", &n, &m, &k);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                scanf ("%d", &matrix [i] [j]);
                sum [i] [j] = sum [i - 1] [j] + sum [i] [j - 1] - sum [i - 1] [j - 1] + matrix [i] [j];
                //printf ("%8d ", matrix [i] [j]);
            }
            //printf ("\n");
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


        if (dimensions != -1 && cost != INF)
            printf ("Case #%d: %d %d\n", case_id++, dimensions, cost);
        else
            printf ("Case #%d: 0 0\n", case_id++);
    }

    return 0;
}
/*
1
5 6 1000000
1000000 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10
*/

