#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m, solution1, solution2, matrix [310] [310], r [310], c [310];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf ("%d", &matrix [i] [j]);
            c [i] += matrix [i] [j];
            r [j] += matrix [i] [j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cnt1(0), cnt2(0), minimum1(1123), minimum2(1123);

        for (int j = 0; j < n; j++)
        {
            minimum1 = min (matrix [i] [j], minimum1);
            cnt1 += matrix [i] [j];

            minimum2 = min (matrix [j] [i], minimum2);
            cnt2 += matrix [j] [i];
        }

        solution1 += cnt1 - minimum1;
        solution2 += cnt2 - minimum2;
    }

    printf ("solution1: %d\n", solution1);
    printf ("solution2: %d\n", solution2);

    return 0;
}
/*
5
4 2 2 3 3
4 2 1 4 0
1 3 4 0 1
4 3 0 2 3
0 0 3 0 4
*/
