#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define n 10
#define m 10

char matrix [n] [m];

int percentage = 30;

int get_number(int limit)
{
    return rand() % limit;
}

int main()
{
    freopen ("in.txt", "w", stdout);
    srand (time (0));
    printf ("%d %d\n", n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int number = get_number (100);

            if (number < percentage)
                matrix [i] [j] = '#';
            else
                matrix [i] [j] = '.';
        }
    }

    matrix [0] [0] = '.';
    matrix [n - 1] [m - 1] = '.';

    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            putchar (matrix [i] [j]);

    return 0;
}






