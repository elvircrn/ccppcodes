#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstring>
#include <vector>

using namespace std;

char characters[4] = { 'A', 'T', 'G', 'C' };

char A[10100], B[5100];
int min_cost = 90000000, current_index, a, c, g, t, current_occurence [300], cost [300], total_cost;
int last_occurence [100];

int occurence [100] [10100];

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%s %s %d %d %d %d", &A, &B, &cost ['A'], &cost ['C'], &cost ['G'], &cost ['T']);
    int lenA = strlen (A);
    int lenB = strlen (B);

    for (int i = 0; i < lenB; i++)
    {
        total_cost += cost [B [i]];
    }

    for (int i = 0; i < 4; i++)
        occurence [characters [i]] [0] = -1;

    for (int i = 0; i < lenA; i++)
    {
        if (i == 0)
        {
            occurence [A [i]] [i] = 0;
        }
        else
        {
            for (int j = 0; j < 4; j++)
                occurence [characters [j]] [i] = occurence [characters [j]] [i - 1];
            occurence [A [i]] [i] = i;
        }
    }

    for (int i = lenA - 1; i > -1; i--)
    {
        if (i == lenA - 1)
            occurence [A [i]] [i] = lenA - 1;
        else
        {
            for (int j = 0; j < 4; j++)
                occurence [characters [j]] [i] = occurence [characters [j]] [i + 1];
            occurence [A [i]] [i] = i;
        }
    }

    memset (last_occurence, -1, sizeof last_occurence);

    for (int i = 0; i < lenA; i++)
    {
        int current_cost = 0;
        current_index = -1;
        prev_index = -1;
        printf ("i: %d\n", i);

        for (int j = 0; j < lenB; j++)
        {
            int occ = occurence [B [j]] [i + j];
            if (occ == -1)
            {

                goto l1;
            }
        }

        l1:;
    }

    printf ("%d\n", min_cost);

    return 0;
}
/*
TCGCAG
TGCAG
10 10 15 15
*/































