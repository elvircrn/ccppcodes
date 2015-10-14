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

int t, numbers[50100], n;

int main()
{
    for (int i = 0; i < 50099; i++)
        numbers [i] = 1;

    scanf ("%d %d", &n, &t);
    for (int i = 1; i < n; i++)
        scanf ("%d", &numbers[i]);

    int current_cell = 1, counter = 0;

    while (current_cell <= n && current_cell <= t)
    {
        counter++;

        if (counter > 40000)
            break;
        if (current_cell == t)
        {
            printf ("YES\n");
            return 0;
        }

        if (current_cell <= n)
            current_cell += numbers[current_cell];
        else
            break;
    }

    printf ("NO\n");

    return 0;
}









































