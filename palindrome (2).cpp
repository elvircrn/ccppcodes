#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N 200000

int n, b [MAX_N], len;
char input [MAX_N];

char get_rev_index(int index)
{
    return input [len - index - 1];
}

void kmpPreprocess()
{
    b [0] = -1;
    int i = 0, j = -1;
    while (i < len)
    {
        while (j >= 0 && get_rev_index (i) != get_rev_index (j))
            j = b [j];
        i++;
        j++;

        b [i] = j;
    }
}

int kmpSearch()
{
    int i = 0, j = 0;
    while (i < len)
    {
        while (j >= 0 && get_rev_index(j) != input [i])
            j = b [j];

        i++;
        j++;
    }

    return j;
}

int main()
{
    scanf ("%d %s", &len, &input);

    kmpPreprocess();
    int sol = kmpSearch();

    if (sol == len)
        printf ("%d\n", 0);
    else
    {
        printf ("%d\n", len - sol);
    }

    return 0;
}






