#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char matrix [1001] [1001];
int n;
bool row, column;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    for (int i = 0; i < n; i++)
    {

        bool r = true;
        bool c = true;
        for (int j = 0; j < n; j++)
        {
            if (matrix [i] [j] == '.')
                r = false;

            if (matrix [j] [i] == '.')
                c = false;
        }

        if (c)
            column = true;
        if (r)
            row = true;

        if (row && column)
        {
            printf ("-1\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (column)
            {

            }
        }
    }

    return 0;
}


















