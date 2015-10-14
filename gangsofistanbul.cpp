#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

//#define DEBUG

using namespace std;

int n, m;

vector <int> solution;

int calculate(int current_gang, int cow_numbers, vector <int> G)
{
    sort (G.begin() + 1, G.end());

#ifdef DEBUG

    printf ("       calc:\n");
    printf ("       entry:\n       current_gang: %d cow_numbers: %d\n", current_gang, cow_numbers);

#endif

    while (G.back() > 0)
    {
        for (int i = G.size() - 1; i > 0; i--)
        {
            if (G [i])
            {
#ifdef DEBUG
                printf ("       %d\n", i + 1);
#endif
                if (cow_numbers == 0)
                {
                    current_gang = i;
                    cow_numbers = 1;
                }
                else if (current_gang == i)
                    cow_numbers++;
                else
                    cow_numbers--;
                G [i]--;

                if (G [i - 1] <= G [i])
                    break;
            }
        }
    }

    for (int i = 0; i < G [0]; i++)
    {
#ifdef DEBUG
        printf ("       1\n");
#endif
        if (cow_numbers == 0)
        {
            current_gang = i;
            cow_numbers = 1;
        }
        else if (current_gang == i)
            cow_numbers++;
        else
            cow_numbers--;
    }

    if (current_gang == 0)
        return cow_numbers;
    else
        return 0;
}

int main()
{
    scanf ("%d %d", &n, &m);
    vector <int> G(m);

    for (int i = 0; i < m; i++)
        scanf ("%d", &G [i]);

    int r = calculate(0, 0, G);

    if (r)
    {
        printf("YES\n%d\n", r);
        /*
        for (int i = 0; i < G [0] - r; i++)
        {
            solution.push_back(1);
            G [0]--;
        }
        */

        int current_gang = 0, cow_numbers/* = solution.size()*/ = 0;
        bool gate = false;

        for (int i = 0;; i++)
        {
#ifdef DEBUG
            printf ("i: %d\n", i);
#endif
            gate = false;

            for (int j = 0; j < m; j++)
            {
                if (G [j])
                {
#ifdef DEBUG
                    printf ("   G  [%d]: %d\n", j, G [j]);
#endif
                    gate = true;

                    int p1 = current_gang, p2 = cow_numbers;

                    G [j]--;

                    if (cow_numbers == 0)
                    {
                        current_gang = j;
                        cow_numbers = 1;
                    }
                    else if (current_gang == i)
                        cow_numbers++;
                    else
                        cow_numbers--;

                    if (r != calculate(current_gang, cow_numbers, G))
                    {
                        G [j]++;
                        current_gang = p1;
                        cow_numbers  = p2;
                    }
                    else
                    {
                        solution.push_back(j + 1);
                        break;
                    }
                }
            }
#ifdef DEBUG
            printf ("current_gang: %d cow_numbers: %d\n", current_gang, cow_numbers);
#endif
            if (!gate)
                break;

            //system ("pause");
        }

        for (int i = 0; i < solution.size(); i++)
            printf("%d\n", solution [i]);
    }
    else
        printf ("NO\n");

    return 0;
}



//yourlogohere






































