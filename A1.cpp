#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int n, x, sum, a, cnt;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf ("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a);
        sum += a;
    }

    if (sum > 0)
    {
        while (sum > 0)
        {
            sum -= x;
            cnt++;
        }
    }
    else
    {
        while (sum < 0)
        {
            sum += x;
            cnt++;
        }
    }

    printf ("%d\n", cnt);

    return 0;
}
