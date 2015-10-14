#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int n, counter [1000], N;
char word [100000];
bool found;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &word);
        counter [word [0]]++;
    }

    for (int i = 0; i < 300; i++)
        if (counter [i] >= 5)
        {
            putchar (i);
            found = true;
        }

    if (!found)
        printf ("PREDAO"); putchar ('\n');

    return 0;
}

