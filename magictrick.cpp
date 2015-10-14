#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, x, y, visited [100], row1 [5], row2 [5], dummy;

int main()
{
    freopen ("in.txt", "r", stdin);
    int t;
    scanf ("%d", &t);
    for (int test_id = 1; test_id <= n; test_id++)
    {
        printf ("Case #%d: ", test_id);
        memset (visited, false, sizeof visited);
        scanf ("%d", &x);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                scanf ("%d", &dummy);
                if (i + 1 == x)
                    visited [dummy]++;
            }

        int counter(0);

        scanf ("%d", &y);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                scanf ("%d", &dummy);
                if (i + 1 == x)
                    visited [dummy]++;

                counter += visited [dummy] >= 2;
            }

        if (counter == 1)
        {
            for (int i = 1; i <= 16; i++)
                if (visited [i] == 2)
                {
                    printf ("%d\n", i);
                    break;
                }
        }
        else if (counter == 0)
            printf ("Volunteer cheated!\n");
        else
            printf ("Bad magician\n");
    }

    return 0;
}
/*
3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/













