#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int t, n, m, x, votes [1000], v [100];

void clear_case()
{
    memset (votes, 0, sizeof votes);
}

int main ()
{
    scanf ("%d", &t);
    int winner, maximum, index;
    while (t--)
    {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            maximum = 0;
            for (int j = 0; j < n; j++)
            {
                scanf ("%d", &x);
                votes [j] += x;
            }
        }

        maximum = 0;

        for (int i = 0; i < n; i++)
        {
            if (maximum < votes [i])
            {
                maximum = votes [i];
                winner = i + 1;
            }
        }

        printf ("%d\n", winner);

        clear_case();
    }

    return 0;
}
/*
1
3 3
4 5 3
1 3 2
4 5 3
*/
