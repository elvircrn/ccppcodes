#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N 10000000

int n, len, b [MAX_N], counter;
char input [MAX_N], c;

int main()
{
    while (scanf ("%d", &n) == 1)
    {
        counter = 0;

        scanf ("%s", &input); getchar();
        len = strlen (input);

        //preprocess
        int i = 0, j = -1;
        b [0] = -1;
        while (i < len)
        {
            while (j >= 0 && input [i] != input [j])
                j = b [j];

            i++;
            j++;

            b [i] = j;
        }

        bool found(false);

        //kmpsearch
        i = 0;
        j = 0;
        while (isalpha (c = getchar()))
        {
            while (j >= 0 && c != input [j])
                j = b [j];

            i++;
            j++;

            if (j == len)
            {
                printf ("%d\n", i - j);
                j = b [j];
                found = true;
            }
        }

        if (!found)
            putchar ('\n');
    }

    return 0;
}



