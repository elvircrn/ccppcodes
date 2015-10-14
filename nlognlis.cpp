#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int solution, top_index, n;
vector <int> S;

int main()
{
    scanf ("%d", &n);

    int current_index, X;
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &X);
        if (i == 0)
            S.push_back (X);
        else if (X > S [S.size() - 1])
            S.push_back (X);
        else
        {
            current_index = (lower_bound (S.begin(), S.end(), X) - S.begin()) - 1;

            if (S.size() - 1 == current_index)
                S.push_back (X);
            else
                S [current_index + 1] = X;
        }

        int s_size = S.size();

        solution = max (solution, s_size);
    }

    printf ("%d\n", solution);

    return 0;
}
/*
5
2 3 1 4 5
*/
