#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define INF 1<<29

int n, m, LEFT, RIGHT, raisins [100] [100], dp [52] [52] [52] [52], sum [100] [100];

int SUM (int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return raisins [x1] [y1];
    else
        return (sum [x2] [y2] + sum [x1 - 1] [y1 - 1] - (sum [x1 -  1] [y2] + sum [x2] [y1 - 1]));
}

int solve (int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
    {
        return 0;
    }
    else if (dp [x1] [y1] [x2] [y2])
    {
        return dp [x1] [y1] [x2] [y2];
    }
    else
    {
        int min_cost = INF;

        //vertical
        for (int i = y1 + 1; i <= y2; i++)
        {//1 1 2 2
            LEFT = solve (x1, y1, x2, i - 1); //1 1 2 1
            cout<<"<<->>"<<endl;
            RIGHT = solve (x1, i, x2, y2);    //1 2 2 2

            min_cost = min (min_cost, LEFT + RIGHT);
        }

        //horizontal
        for (int i = x1 + 1; i <= x2; i++)
        {
            LEFT = solve (x1, y1, i - 1, y2);
            RIGHT = solve (i, y1, x2, y2);

            min_cost = min (min_cost, LEFT + RIGHT);
        }


        dp [x1] [y1] [x2] [y2] = SUM (x1, y1, x2, y2) + min_cost;
        dp [x2] [y2] [x1] [y1] = dp [x1] [y1] [x2] [y2];
        printf ("LEFT: %d RIGHT: %d\n", LEFT, RIGHT);
        printf ("x1: %d y1: %d x2: %d y2: %d\n", x1, y1, x2, y2);
        printf ("dp: %d\n", dp [x1] [y1] [x2] [y2]);
    }

    return dp [x1] [y1] [x2] [y2];
}

int main ()
{
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf ("%d", &raisins [i] [j]);
            sum [i] [j] = raisins [i] [j] + (sum [i - 1] [j] + sum [i] [j - 1]) - sum [i - 1] [j - 1];
        }
    }

    printf ("%d\n", solve (1, 1, n, m));

    return 0;
}
/*
2 2
2 1
1 2

1 1 2 1
1 2 2 2
*/













