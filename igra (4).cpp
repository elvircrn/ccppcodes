#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [130], dp [130] [130];

int solve (int left_bound, int right_bound)
{
    if (left_bound == right_bound)
        return array [left_bound];
    else if (left_bound > right_bound)
        return 0;

    if (dp [left_bound] [right_bound] != -1)
        return dp [left_bound] [right_bound];

    /**

    solve (left_bound, right_bound - 1) + array [right_bound]
    solve (left_bound + 1, right_bound) + array [left_bound]

    */
}

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    memset (dp, -1, sizeof dp);

    return 0;
}






