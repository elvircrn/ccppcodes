#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m, matrix [100] [100], current_case = 1;

int main ()
{
    scanf ("%d", &t);
    while (t--)
    {
        printf ("Current #%d: ", current_case++);
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf ("%d", &matrix [i] [j]);

        for (int i = 0; i < n; i++)
        {
            bool allUp = true, allDown = true;
            bool allUp1 = true, allDown1 = true;
            for (int j = 1; j < m; j++)
            {
                if (matrix [i] [j - 1] > matrix [i] [j])
                    allDown = false;
                if (matrix [i] [j - 1] > matrix [i] [j])
                    allUp = false;

                if (matrix [j - 1] [i] > matrix [j] [i])
                    allDown1 = false;
                if (matrix [j - 1] [i] < matrix [j] [i])
                    allUp1 = false;
            }

            if (!(allDown || allUp || allDown1 || allUp1))
            {
                printf ("NO\n");
                goto new_case;
            }

        }

        printf ("YES\n");
        new_case:;
    }


    return 0;
}
/*
3 3
2 1 2
1 1 1
2 1 2

5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
*/
