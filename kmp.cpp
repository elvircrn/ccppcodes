#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char needle [100], haystack [100000];
int b [100], n_len, hay_len;

void preprocess()
{
    int i = 0, j = -1;

    b [0] = -1;

    while (i < n_len)
    {
        while (j >= 0 && needle [i] != needle [j])
            j = b [j];

        i++;
        j++;

        b [i] = j;
    }
}

void search()
{
    bool found(false);
    int i = 0, j = 0;
    while (i < hay_len)
    {
        while (j >= 0 && haystack [i] != needle [j])
            j = b [j];

        i++;
        j++;

        if (j == n_len)
        {
            printf ("String found at: %d.\n", i - j);
            found = true;
        }
    }

    if (!found)
        printf ("Needle not found in haystack.\n");
}

int main()
{
    scanf ("%s %s", &needle, &haystack);
    n_len   = strlen (needle);
    hay_len = strlen (haystack);

    preprocess();
    search();

    return 0;
}




















