#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int L, n, l, sd, durations [30];
vector <int> start_time [30];
int a, power, dp [1<<22];

int binary (int index, int L)
{
    //printf ("index: %d L: %d\n", index, L);
    //system ("pause");
    int solution = -1, left = 0, right = start_time [index].size() - 1;

    while (left <= right)
    {
        int pivot = (left + right) / 2;

        if (start_time [index] [pivot] + durations [index] < L)
            left = pivot + 1;
        else if (start_time [index] [pivot] <= L && L <= start_time [index] [pivot] + durations [index])
        {
            solution = max (solution, pivot);
            left = pivot + 1;
        }
        else
            right = pivot - 1;
    }

    return solution;
}

int num (int bits)
{
    int ret = 0;
    while (bits)
    {
        bits -= (bits & (-bits));
        ret++;
    }
    return ret;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    int solution = 123123;
    scanf ("%d %d", &n, &l);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &durations [i]);
        scanf ("%d", &sd);
        for (int j = 0; j < sd; j++)
        {
            scanf ("%d", &a);
            start_time [i].push_back(a);
        }
    }

    power = 1<<n;

    for (int i = 0; i < power; i++)
    {
        //printf ("%d\n", i);
        for (int j = 0; j < n; j++)
        {
            //place j in set power
            if (!(i & (1<<j)))
            {
                L = dp [i];

                int s = binary (j, L);

                if (s == -1)
                    continue;

                int candidate = start_time [j] [s] + durations [j];
                dp [i + (1<<j)] = max (dp [i + (1<<j)], candidate);

                if (candidate >= l)
                    solution = min (solution, num (i + (1<<j)));
            }
        }
    }

    printf ("%d\n", solution);


    return 0;
}
/*
4 100
50 3 15 30 55
40 2 0 65
30 2 20 90
20 1 0

5 55
10 20 30 40 50
*/







































