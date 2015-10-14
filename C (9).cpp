#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>

using namespace std;

int n, m;
int count [10], matrix [1100] [1100], solution [1100] [1100];
char in[3];

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf ("%s", &in);
            if (!strcmp (in, "00"))
            {
                matrix [i] [j] = 0;
            }
            else if (!strcmp (in, "01"))
            {
                matrix [i] [j] = 1;
            }
            else if (!strcmp (in, "10"))
            {
                matrix [i] [j] = 2;
            }
            else
                matrix [i] [j] = 3;

            count [matrix [i] [j]]++;
        }
    }

    count [2] += count [1];
    bool found(false);


    for (int i = n - 1; i > -1; i--)
    {
        if (!count [2] && !count [3])
            break;
        if (!count [3])
        {
            for (int j = 0; j < m; j++)
            {
                if (count [2])
                {
                    solution [i] [j] = 2;
                    count [2]--;
                }
                else
                {
                    goto l1;
                }
            }
        }
        else
        {
            for (int j = m - 1; j > -1; j--)
            {
                if (count [3])
                {
                    solution [i] [j] = 3;
                    count [3]--;
                }
                else if (count [2])
                {
                    solution [i] [j] = 2;
                    count [2]--;
                }
                else
                    goto l1;
            }
        }
    }

    l1:;

    for (int i = 0; i < m; i++)
    {
        if (!solution [0] [i])
            printf ("00 ");
        else if (solution [0] [i] == 2)
            printf ("10 ");
        else if (solution [0] [i] == 3)
            printf ("11 ");
    }

    printf ("\n");

    for (int i = 1; i < n; i++, printf ("\n"))
    {
        for (int j = 0; j < m; j++)
        {
            if (solution [i] [j] == 0)
                printf ("00 ");
            else if (solution [i] [j] == 3)
                printf ("11 ");
            else if (solution [i - 1] [j] == 2)
            {
                printf ("01 ");
                solution [i] [j] = 1;
            }
            else
                printf ("10 ");
        }
    }

    return 0;
}





