#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char word [10000];
int power, pos [10000], len, RA [10000], SA [10000];

bool cmp(int x, int y)
{
    if (pos [x] != pos [y])
        return pos [x] < pos [y];

    if (x + power >= len || y + power >= len)
        return x > y;
    else
        return pos [x + power] < pos [y + power];
}

int main()
{
    while (isalpha (word [len++] = getchar()))
    {
        SA [len - 1] = len - 1;
        pos [len - 1] = word [len - 1];
    }

    len--;
    word [len] = '\0';

    for (power = 1; power <= len; power *= 2)
    {
        sort (SA, SA + len, cmp);

        for (int i = 0; i < len - 1; i++)
            RA [i + 1] = RA [i] + cmp (SA [i], SA [i + 1]);
        for (int i = 0; i < len; i++)
            pos [SA [i]] = RA [i];
    }

    for (int i = 0; i < len; i++)
        printf ("%s\n", word + SA [i]);

    return 0;
}
/*
ybcdhijeklmnopxfgqrtstauvw
*/
