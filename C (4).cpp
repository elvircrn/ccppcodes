#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int t, n, k, d1, d2, remaining_games;

bool check()
{
    remaining_games = n - k;

    printf ("remaining_games: %d\n", remaining_games);

    if (d1 == d2 && remaining_games % 3 == 0)
        return true;
    if (d1 == d2)
        return false;

    //x1<x2<x3
    if ((remaining_games - (d2 + d1 + d2)) % 3 == 0)
    {
        printf ("%d: one\n", (remaining_games - d2 + d1 + d2));
        return true;
    }
    //x1<x2  x2>x3
    if ((remaining_games - d1 - d2) % 3 == 0)
    {
        printf ("two\n");
        return true;
    }
    //x1>x2>x3

    if ((remaining_games - d1 - d2 - d1) % 3 == 0)
    {
        printf ("three\n");
        return true;
    }
    //x1>x2 x2<x3
    if ((remaining_games - (d1 + d2 - d1)) % 3 == 0)
    {
        printf ("four\n");
        return true;
    }
    return false;
}

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d %d %d %d", &n, &k, &d1, &d2);
        if (check ())
            printf ("yes\n");
        else
            printf ("no\n");
    }

    return 0;
}
