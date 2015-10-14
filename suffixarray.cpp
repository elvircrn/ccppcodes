#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char unos[100100], query[1000];
int N, pos [100100], INDEX[100100], sort_index[100100], power, current_index;

bool cmp(int x, int y)
{
    if (pos [x] != pos [y])
        return pos [x] < pos [y];

    x += power;
    y += power;

    return (x < N && y < N) ? pos [x] < pos [y] : x > y;
}

int main()
{
    scanf ("%s %s", &unos, &query);
    N = strlen (unos);

    for (int i = 0; i <= N + 2; i++)
    {
        INDEX [i] = i;
        pos [i] = unos [i];
    }

    for (power = 1; power <= N; power *= 2)
    {
        int current_index = 0;
        sort (INDEX, INDEX + N, cmp);

        for (int i = 1; i < N; i++)
        {
            current_index += cmp (INDEX [i - 1], INDEX [i]);
            sort_index [i] = current_index;
        }

        if (sort_index [N - 1] == N - 1)
            break;

        for (int i = 0; i < N; i++)
            pos [INDEX [i]] = sort_index [i];
    }

    for (int i = 0; i < N; i++)
        printf ("%s\n", unos + INDEX [i]);

    int left_bound(0), right_bound(N - 1), pivot, q_n = strlen (query);

    while (left_bound <= right_bound)
    {
        pivot = (left_bound + right_bound) / 2;

        int comp = strncmp (query, unos + INDEX [pivot], q_n);

        if (comp == 0)
            break;
        else if (comp == -1)
            right_bound = pivot - 1;
        else
            left_bound = pivot + 1;
    }

    printf ("pivot: %d\n", pivot);

    int lo, hi;

    for (lo = pivot; lo >= 0 && strncmp (query, unos + INDEX [lo], q_n) == 0; lo--); lo++;
    for (hi = pivot + 1; hi < N && strncmp (query, unos + INDEX [hi], q_n) == 0; hi++); hi--;

    printf ("lo: %d hi: %d\n", lo, hi);

    return 0;
}

/*
ACCCBCCC
BCCC
C
CACCCBCCC
CBCCC
CC
CCACCCBCCC
CCBCCC
CCC
CCCACCCBCCC
CCCBCCC

abcxabcd b

CCCACCCBCCC CCC

abcxabcd

abcd
abcxabcd
bcd
bcxabcd
cd
cxabcd
d
xabcd

1
7 6
#######
#.#.###
#.#.###
#####.#
#.....#
#######
*/





