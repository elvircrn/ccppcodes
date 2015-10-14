#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m, matrix [100] [100], current_case = 1;
bool final_matrix [100] [100];

int main ()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf ("%d", &matrix [i] [j]);

        for (int i = 0; i < n; i++)
        {
            final_matrix [i] [0] = true;
            for (int j = 1; j < m; j++)
            {
                if (matrix [i] [j - 1] > matrix [i] [j])
                    break;
                final_matrix [i] [j] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            final_matrix [i] [m - 1] = true;
            for (int j = m - 2; j > -1; j--)
            {
                if (matrix [i] [j - 1] < matrix [i] [j])
                    break;
                final_matrix [i] [j] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            final_matrix [0] [i] = true;
            for (int j = 1; j < m; j++)
            {
                if (matrix [j - 1] [i] > matrix [j] [i])
                    break;
                final_matrix [j] [i] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            final_matrix [n - 1] [i] = true;
            for (int j = m - 2; j > -1; j--)
            {
                if (matrix [j - 1] [i] < matrix [j] [i])
                    break;
                final_matrix [j] [i] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (final_matrix [i] [j] == true)
                    cnt++;

        printf ("Case #%d: ", current_case++);
        if (cnt == n * m)
            printf ("YES\n");
        else
            printf ("NO\n");

        memset (final_matrix, false, sizeof final_matrix);
    }


    return 0;
}
/*
1
5 5
3 2 3 2 3
3 2 3 2 3
3 2 3 2 3
3 2 3 2 3
3 2 3 2 3
*/
