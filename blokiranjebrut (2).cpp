#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int range_min, range_max, n, solution, array [1000];

int main()
{
    freopen ("in.txt", "r", stdin);
    //freopen ("outbrute.txt", "w", stdout);

    scanf ("%d %d %d", &n, &range_min, &range_max);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    int power = (1<<n);

    for (int i = 0; i < power; i++)
    {
        int cnt(0);
        for (int j = 0; j < 10; j++)
        {
            if ((i & 1<<j))
                cnt += array [j];
        }

        if (range_min <= cnt && cnt <= range_max)
        {
            solution++;
            for (int j = 0; j < 10; j++)
            {
                if ((i & 1<<j))
                    printf ("%d\n", array [j]);
            }
            printf ("<---------->\n\n");
        }
    }

    printf ("%d\n", solution);

    return 0;
}
