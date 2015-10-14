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

int n, numbers [1000000], numbers1 [1000000];


int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &numbers [i]);
        numbers1 [i] = numbers [i];
    }

    sort (numbers1, numbers1 + n);

    int l = -1, r = -1;

    for (int i = 0; i < n; i++)
    {
        if (numbers [i] != numbers1 [i])
        {
            if (l < 0)
                l = i;
            else
                r = i;
        }
    }

    if (l < 0 || r < 0)
    {
        printf ("yes\n1 1\n");
        return 0;
    }


    for (int i = 0; i <= (r - l) / 2; i++)
    {
        if (l + i >= r - i)
            break;
        swap (numbers [l + i], numbers [r - i]);
    }

    for (int i = 0; i < n; i++)
        if (numbers [i] != numbers1 [i])
        {
            printf ("no\n");
            return 0;
        }

    printf ("yes\n%d %d\n", l + 1, r + 1);

    return 0;
}
