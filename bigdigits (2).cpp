#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ull;

ull len, A, B, S, dp [200] [30] [5], limit, dp1 [200] [100];
char str_limit [30];

ull solve (ull current_progress, ull size, bool taken)
{
    if (current_progress == 0)
        return 1;
    else if (current_progress < 0 || size == 0)
        return 0;
    if (dp [current_progress] [size] [taken] != -1)
        return dp [current_progress] [size] [taken];

    if (dp [current_progress] [size] [taken] == -1)
        dp [current_progress] [size] [taken] = 0;

    if (!taken)
    {
        for (ull i = (str_limit [len - size] - '0') - 1; i >= (size == len) ? 1 : 0; i--)
        {
            dp [current_progress] [size] [taken] += solve (current_progress - i, size - 1, true);
        }
        dp [current_progress] [size] [taken] += solve (current_progress - (str_limit [len - size] - '0'), size - 1, false);
    }
    else
    {
        for (ull i = 0; i <= 9; i++)
        {
            dp [current_progress] [size] [taken] += solve (current_progress - i, size - 1, true);
        }
    }

    return dp [current_progress] [size] [taken];
}

ull solve (ull current_progress, ull size)
{
    if (current_progress == 0)
        return 1;
    else if (current_progress < 0 || size == 0)
        return 0;
    if (dp1 [current_progress] [size] != -1)
        return dp1 [current_progress] [size];

    if (dp1 [current_progress] [size] == -1)
        dp1 [current_progress] [size] = 0;

    for (ull i = 0; i <= 9; i++)
    {
        dp1 [current_progress] [size] += solve (current_progress - i, size - 1);
    }

    return dp1 [current_progress] [size];
}

ull ret (ull number, ull sum)
{
    memset (dp, -1, sizeof dp);

    sprintf (str_limit, "%lld", number);

    len = strlen (str_limit);

    ull sol = solve (sum, len, false);

    memset (dp1, -1, sizeof dp1);

    sol += solve (sum, len - 1);

    return sol;
}

int main()
{
    scanf ("%lld %lld %lld", &A, &B, &S);

    if (S == 0 && A == 0)
    {
        printf ("1\n");
        return 0;
    }
    else if (A == 0)
    {
        printf ("%lld\n", ret (B, S));
        return 0;
    }

    printf ("%lld\n", ret (B, S) - ret (A - 1, S));

    return 0;
}










