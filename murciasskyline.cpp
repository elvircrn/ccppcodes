#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n, solution1, solution2, width [3100], height [3100], dp1 [3000], dp2 [3000];

int main()
{
    scanf ("%d", &t);
    for (int test_id = 1; test_id <= t; test_id++)
    {
        solution1 = 0;
        solution2 = 0;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
            scanf ("%d", &height [i]);
        for (int i = 0; i < n; i++)
            scanf ("%d", &width [i]);

        for (int i = 0; i < n; i++)
        {
            dp1 [i] = width [i];
            for (int j = 0; j < i; j++)
                if (height [j] < height [i])
                    dp1 [i] = max (dp1 [i], dp1 [j] + width [i]);
            solution1 = max (dp1 [i], solution1);
        }

        for (int i = n - 1; i > -1; i--)
        {
            dp2 [i] = width [i];
            for (int j = i + 1; j < n; j++)
                if (height [i] > height [j])
                    dp2 [i] = max (dp2 [i], dp2 [j] + width [i]);
            solution2 = max (dp2 [i], solution2);
        }

        if (solution1 >= solution2)
            printf ("Case %d. Increasing (%d). Decreasing (%d).\n", test_id, solution1, solution2);
        else
            printf ("Case %d. Decreasing (%d). Increasing (%d).\n", test_id, solution2, solution1);
    }

    return 0;
}











