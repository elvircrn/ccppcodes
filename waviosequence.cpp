#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int solution, n, array [30000], S [30000], S1 [30000], S2 [30000], top_index;

int main()
{
    while (scanf ("%d", &n) == 1)
    {
        solution = 0;
        top_index = 0;

        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &array [i]);
            int current_index = lower_bound(S, S + top_index, array [i]) - S;

            S [current_index] = array [i];

            if (current_index == top_index)
                top_index++;

            S1 [i] = top_index;
        }

        top_index = 0;

        S [0] = 0;

        for (int i = n - 1; i > -1; i--)
        {
            int current_index = lower_bound(S, S + top_index, array [i]) - S;

            S [current_index] = array [i];

            if (current_index == top_index)
                top_index++;

            S2 [i] = top_index;
        }

        for (int i = 0; i < n; i++)
            solution = max (solution, min (S1 [i], S2 [i]));

        printf ("%d\n", 2 * solution - 1);
    }

    return 0;
}




















