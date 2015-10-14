#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, d, t [2000];

int main()
{
    int sum = 0;
    scanf ("%d %d", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &t [i]);
        sum += t [i];
        if (i != n)
            sum += 10;
    }

    int dd = d;

    sort (t + 1, t + n + 1);

    int counter = 0;

    int i = n;

    while (d > 0 && i > 0)
    {
        d -= t [i];

        if (d >= 10)
        {
            d -= 10;
            counter += 2;
        }

        i--;
    }

    if (d > 0)
        counter += (d / 5);

    if (sum > dd)
        printf ("-1\n");
    else
        printf ("%d\n", counter);

    return 0;
}
















