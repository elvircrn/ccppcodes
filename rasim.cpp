#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int a, b;

void rec (char array [10], int current_depth, int max_depth)
{
    if (current_depth == max_depth)
    {
        for (int i = 0; i < max_depth; i++)
            putchar (array [i]);
        putchar ('\n');
        return;
    }

    for (int i = '0'; i <= '9'; i++)
    {
        array [current_depth] = char (i);
        rec (array, current_depth + 1, max_depth);
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        array [current_depth] = char (i);
        rec (array, current_depth + 1, max_depth);
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        array [current_depth] = char (i);
        rec (array, current_depth + 1, max_depth);
    }

    array [current_depth] = ' ';
    rec (array, current_depth + 1, max_depth);
}

int main ()
{
    freopen ("unos.txt", "r", stdin);
    freopen ("izlaz.txt", "w", stdout);

    char prazno [10];

    scanf ("%d %d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        rec (prazno, 0, i);
    }

    return 0;
}
