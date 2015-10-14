#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

#define INF 123
#define DP dp [r] [c] [mc] [mb] [p]

bool matrix[20] [20];
int dp [10] [10] [1<<9] [1<<3] [3];

int solve(int r, int c, int mc, int mb, bool p)
{
    if (r == 9)
    {
        if (mc)
            return DP = INF;
        else
            return 0;
    }

    if (c == 9)
    {
        if (p)
            return DP = INF;

        if (r % 3 == 2 && mb)
            return DP = INF;

        return solve(r + 1, 0, mc, mb, 0);
    }

    if (DP != -1)
        return DP;

    //set to 1
    int p1 = !matrix [r] [c] + solve(r, c + 1, mc ^ (1<<c), mb ^ (1<<(c / 3)), !p);

    //set to 0
    int p2 = matrix [r] [c] + solve(r, c + 1, mc, mb, p);

    return DP = min (p1, p2);
}

int main()
{
    /*int r = 0, c = 0;
    char cc;
    while ((cc = getchar()) != EOF && r < 9 && c < 9)
    {
        if (isalnum(cc))
        {
            matrix[r] [c] = (cc == '1');
            c++;

            if (c == 9)
            {
                r++;
                c = 0;
            }
        }
    }
    */

    for (int i = 0; i < 9; i++)
    {
        char in [9];
        scanf ("%s", &in);
        for (int j = 0; j < 9; j++)
            matrix [i] [j] = (in [j] == '1');
    }

    memset(dp, -1, sizeof (dp));

    printf("%d\n", solve(0, 0, 0, 0, 0));

    return 0;
}

/*
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
*/











