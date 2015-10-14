#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstring>
#include <vector>

using namespace std;

char A[10100], B[5100];
int min_cost = 90000000, current_index, a, c, g, t, current_occurence [300], cost [300], total_cost;

vector <int> occurence [200];

int binary_search(char letter, int left_index, int right_index)
    if (left_index ==)
{
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%s %s %d %d %d %d", &A, &B, &cost ['A'], &cost ['C'], &cost ['G'], &cost ['T']);
    int lenA = strlen (A);
    int lenB = strlen (B);

    for (int i = 0; i < lenB; i++)
    {
        occurence [B [i]].push_back (i);
        total_cost += cost [B [i]];
    }

    printf ("total_cost: %d\n", total_cost);

    occurence['A'].push_back (-1);
    occurence['T'].push_back (-1);
    occurence['G'].push_back (-1);
    occurence['C'].push_back (-1);

    current_occurence ['A'] = 0;
    current_occurence ['T'] = 0;
    current_occurence ['G'] = 0;
    current_occurence ['C'] = 0;

    for (int i = 0; i < lenA; i++)
    {
        current_occurence ['A'] = 0;
        current_occurence ['T'] = 0;
        current_occurence ['G'] = 0;
        current_occurence ['C'] = 0;

        int current_cost = 0;

        printf ("i: %d\n", i);

        for (int j = 0; j < lenB; j++)
        {
            printf ("   j: %d\n", j);

            if ((i + j) == lenA || occurence [A [i + j]] [current_occurence [A [i + j]]] == -1)
            {
                min_cost = min (min_cost, total_cost - current_cost);
                printf ("i: %d j: %d cost: %d total_cost: %d current_cost: %d\n", i, j, total_cost - current_cost, total_cost, current_cost);
                break;
            }

            if (current_index > occurence [A [i + j]] [current_occurence [A [i + j]]])
            {

            }

            current_index = occurence [A [i + j]] [current_occurence [A [i + j]]];

            current_occurence [A [i + j]]++;

            current_cost += cost [A [i + j]];
            printf ("   %c\n", A [i + j]);
        }
    }

    printf ("%d\n", min_cost);

    return 0;
}
/*
TCGCAG
TGCAG
10 10 15 15
*/































