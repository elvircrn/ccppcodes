#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef int ull;

ull solution, n, dp [10000];
vector <ull> S;
ull array []= { 1, 2, 3, 4, 5 };
int main()
{
    while (next_permutation (array, array + 5))
    {
        solution = 0;
        n = 5;
        S.clear();
        for (int i = 0; i < n; i++)
        {
            int index, X = array [i];
            if (i == 0)
                S.push_back (X);
            else if (X > S [S.size() - 1])
                S.push_back (X);
            else
            {
                index = (lower_bound (S.begin(), S.end(), X) - S.begin()) - 1;
                if (index == -1)
                {
                    S.clear();
                    S.push_back (X);
                }
                else if (S.size() - 1 == index)
                    S.push_back (X);
                else
                    S [index + 1] = X;
            }

            int s_size = S.size();


            solution = max (solution, s_size);
        }

        for (int i = 0; i < 20; i++)
            dp [i] = 1;
        int sol = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (array [j] < array [i] && dp [i] < dp [j] + 1) {
                    dp [i] = dp [j] + 1;
                    sol = max (dp [i], sol);
                }
            }
        }
        if (sol != solution)
        {
            printf ("sol: %d solution: %d\n", sol, solution);
            for (int i = 0; i < n; i++)
            {
                printf ("%d ", array [i]);
            }
            printf ("\n");
            break;
        }
    }

    return 0;
}

