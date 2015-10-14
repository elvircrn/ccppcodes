#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define MAX_N 1000100

char needle [MAX_N * 2], haystack [MAX_N * 2], b [MAX_N * 2];
int n, m;

void kmpPreprocess()
{
    b [0] = -1;
    b [1] = 0;
    b [2] = 0;
    b [3] = 0;

    int i = 0, j = -1;

    while (i < m)
    {
        while (j >= 0 && needle [i] != needle [j])
            j = b [j];

        i++;
        j++;

        b [i] = j;
    }
}

int kmpSearch()
{
    int counter(0), i = 0, j = 0;

    while (i <= n)
    {
        while (j >= 0 && haystack [i] != needle [j])
            j = b [j];

        i++;
        j++;

        if (j == m)
            counter++;
    }

    return counter;
}

int main ()
{
    freopen ("in.txt", "r", stdin);
    int t;
    scanf ("%d", &t); getchar(); //getchar();
    while (t--)
    {
        //getchar();
        scanf ("%[^\n]s", &needle);
        //printf ("%s\n", needle);
        m = strlen (needle);
        n = 2 * m;

        for (int i = 0; i < m; i++)
        {
            haystack [i + m] = needle [i];
            haystack [i] = needle [i];
        }

        kmpPreprocess();

        printf ("%d", m / (kmpSearch() - 1));
        if (t)
            printf ("\n");
    }

    return 0;
}

/*
abcd
aaaa
ababab

abaaababaaab
.






amanaplanacanallanacanalpanama
















*/

