#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, dp [20] [20] [20] [20] [20], matrix [20] [20];

int solve(int x1, int y1, int x2, int y2, int current_fence)
{
    if (dp [x1] [y1] [x2] [y2] [current_fence] != -1)
        return dp [x1] [y1] [x2] [y2] [current_fence];

}

int main()
{
    memset(dp, -1, sizeof dp);

    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf ("%d", &matrix [i] [j]);



    return 0;
}
/*
3 2
1 1 2
1 1 2
2 2 4
*/



































