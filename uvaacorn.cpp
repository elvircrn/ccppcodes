#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, h, f, test, tree [2011] [2011], dp [2011];

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d", &test);
    while (test--)
    {
        scanf ("%d %d %d", &t, &h, &f);

        memset (dp, 0, sizeof dp);
        memset (tree, 0, sizeof tree);

        for (int i = 0; i <= h + 5; i++)
            dp [i] = 0;

        for (int i = 1; i <= t; i++)
        {
            int a, x;
            scanf ("%d", &a);
            for (int j = 0; j < a; j++)
            {
                scanf ("%d", &x);
                tree [x] [i]++;
            }
        }

        //dp [height] [width]

        for (int i = h; i > -1; i--)
        {
            for (int j = 1; j <= t; j++)
            {
                int best = max (dp [i + f], tree [i + 1] [j]);
                dp [i] = max (best + tree [i] [j], dp [i]);
                tree [i] [j] += best;
            }
        }

        printf ("%d\n", dp [1]);
    }

    return 0;
}











