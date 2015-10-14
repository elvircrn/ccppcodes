#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

#define INF 1<<27

int n, numbers [1001];

int dp [1001] [1001];

int solve(int current_location, int jump_length)
{
    printf ("current_location: %d jump_length: %d\n", current_location, jump_length);
    if (current_location == n)
        return numbers[n];

    if (dp [current_location] [jump_length] != INF)
        return dp [current_location] [jump_length];

    bool found = false;

    //go back
    if (current_location - jump_length >= 1)
    {
        found = true;
        dp [current_location] [jump_length] = min (dp [current_location] [jump_length],
                                                   numbers[current_location] + solve(current_location - jump_length, jump_length));
    }

    if (current_location + jump_length <= n)
    {
        found = true;
        dp [current_location] [jump_length] = min (dp [current_location] [jump_length],
                                                   numbers[current_location] + solve(current_location + jump_length, jump_length + 1));
    }

    if (!found)
        return INF - 1;
}

int main()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &numbers [i]);

    for (int i = 0; i <= n + 5; i++)
        for (int j = 0; j <= n + 5; j++)
            dp [i] [j] = INF;

    printf ("%d\n", solve(1, 1));

    return 0;
}

/*
8
2
3
4
3
1
6
1
4

10 + 4

6
6 5 4 3 2 1
*/









































