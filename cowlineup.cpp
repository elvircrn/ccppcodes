#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>

//#define DEBUG

using namespace std;

int n, k, counter [100100], A;
vector <int> elements;
map <int, int> YO;

int main()
{
    int current_index = 1;
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &A);
        if (YO [A] == 0)
        {
            YO [A] = current_index;
            elements.push_back (current_index);
            current_index++;
        }
        else
            elements.push_back(YO [A]);
    }

    int lower = 0, upper = 0;
    int n_elements = 0;
    int final_solution = 0;

    while (lower < n)
    {
        int current_solution = 0;
        while (n_elements <= k + 1 && lower < n)
        {
            if (counter [elements [lower]] == 0)
                n_elements++;

            counter [elements [lower]]++;

#ifdef DEBUG
            printf ("   lower: %d n_elements: %d\n", lower, n_elements, counter [2]);
#endif

            if (n_elements <= k + 1)
                current_solution = max (current_solution, counter [elements [lower]]);

            lower++;
        }

#ifdef DEBUG
        printf("\n");
#endif

        while (upper <= lower && n_elements > k + 1)
        {
#ifdef DEBUG
            printf ("   upper: %d\n", upper);
#endif
            counter [elements [upper]]--;

            if (counter [elements [upper]] == 0)
                n_elements--;

            upper++;
        }

        final_solution = max (final_solution, current_solution);
    }

    printf ("%d\n", final_solution);

    return 0;
}










































