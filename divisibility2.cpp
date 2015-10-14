#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, SIZE;
char number [1001];

bool check (int integer)
{
    int brojac = number [0] - '0';

    for (int i = 0; i < SIZE; i++)
    {
        if (brojac < integer)
        {
            brojac *= 10;
            if (i != 0)
                brojac += number [i] - '0';
            else
                brojac = number [i] - '0';
            brojac -= ((brojac / integer) * integer);
        }
        else
            brojac -= ((brojac / integer) * integer);
    }

    return !brojac;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        scanf ("%s", &number);
        SIZE = strlen (number);
        if (check (n))
            printf ("DA\n");
        else
            printf ("NE\n");
    }

    return 0;
}
