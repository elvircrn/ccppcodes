#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int mod = 1000007;

char matrix [200] [200];
int dp [200] [200], t, n;

int solve(int x, int y)
{
    dp [x] [y] = 1;

    for (int i = x; i > -1; i--)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        memset (dp, 0, sizeof dp);
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf ("%s", &matrix [i]);
            for (int j = 0; j < n; j++)
            {
                if (matrix [i] [j] == 'W')
                {
                    printf ("%d\n", solve(i, j) % );
                }
            }
        }

    }

    return 0;
}
