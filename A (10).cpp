#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>

using namespace std;

char input[10000];
int len;

int main()
{
    scanf ("%s", &input);
    int index(0), counts [10], len = strlen (input);

    memset (counts, 0, sizeof counts);

    for (int i = 0; i < len; i++)
    {
        if (input [i] == '+')
        {
            index++;
        }
        else if (input [i] == '=')
        {
            index++;
        }
        else
        {
            counts [index]++;
        }
    }

    if (counts [0] + counts [1] == counts [2])
    {
        printf ("%s\n", input);
    }
    else if (counts [0] + 1 + counts [1] == counts [2] - 1)
    {
        for (int i = 0; i < counts [0] + 1; i++)
            putchar ('|');
        putchar ('+');
        for (int i = 0; i < counts [1]; i++)
            putchar ('|');
        putchar ('=');
        for (int i = 0; i < counts [2] - 1; i++)
            putchar ('|');
        putchar ('\n');
    }
    else if (counts [0] + counts [1] - 1 == counts [2] + 1 && counts [1] >= 2)
    {
        counts [1]--;
        counts [2]++;
        for (int i = 0; i < counts [0]; i++)
            putchar ('|');
        putchar ('+');
        for (int i = 0; i < counts [1]; i++)
            putchar ('|');
        putchar ('=');
        for (int i = 0; i < counts [2]; i++)
            putchar ('|');
        putchar ('\n');
    }
    else if (counts [0] - 1 + counts [1]== counts [2] + 1 && counts [0] >= 2)
    {
        counts [0]--;
        counts [2]++;

        for (int i = 0; i < counts [0]; i++)
            putchar ('|');
        putchar ('+');
        for (int i = 0; i < counts [1]; i++)
            putchar ('|');
        putchar ('=');
        for (int i = 0; i < counts [2]; i++)
            putchar ('|');
        putchar ('\n');
    }
    else
        printf ("Impossible\n");


    return 0;
}
