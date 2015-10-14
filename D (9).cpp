#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

#define MAX 10000

int abs (int x)
{
    return (x > 0) ? x : -x;
}

int n, minimum = 1000000, array [1100], hash [100000], novi [1100];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        hash [array [i] + MAX]++;
        minimum = min (array [i] + MAX, minimum);
    }

    sort (array, array + n);

    int MAX_FINAL, MIN_FINAL, MIN = array [0], solution = 1000100;

    for (int i = 1; i < 10000; i++)
    {
        MIN = array [0];
        for (int j = -10000; j <= 10000; j++)
        {
            MIN = array [0] + j;
        }
        int cnt = abs (array [0] - MIN);
        novi [0] = MIN;
        for (int j = 1; j < n; j++)
        {
            if (array [j] == novi [j - 1])
            {
                novi [j] = novi [j - 1] + i;
                cnt = max (cnt, i);
            }
            else
            {
                int a = novi [j - 1] + i;
                cnt = max (cnt, abs (a - novi [j]));
                novi [j] = a;
            }
        }

        if (solution > cnt)
        {
            solution = cnt;
            MIN_FINAL = novi [0];
            MAX_FINAL = novi [n - 1];
        }
    }

    printf ("%d\n%d %d", solution, MIN_FINAL, MAX_FINAL);

    return 0;
}














