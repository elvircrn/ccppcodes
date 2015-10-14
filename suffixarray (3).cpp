#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char input[1000];
int len, gap = 1, sort_index[1000];

bool cmp_help(int x, int y)
{
    if (input [x] != input [y])
        return input [x] < input [y];

    if (x + gap < len && y + gap < len)
        return input [x + gap] < input [y + gap];
    else
        return x > y;
}

bool cmp(int x, int y)
{

}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%s", &input);
    len = strlen (input);

    for (int i = 0; i < len; i++)
        sort_index [i] = i;

    sort (sort_index, sort_index + len, cmp_help);

    for (gap = 1;; gap *= 2)
    {
        sort (sort_index, sort_index + len, cmp_help);

    }
    for (int i = 0; i < len; i++)
    {
        for (int j = sort_index [i]; j < len; j++)
            putchar (input [j]); putchar ('\n');
    }

    return 0;
}










