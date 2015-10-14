#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dX [5] = { -1, 0, 1, 0, 0};
int dY [5] = { 0, 1, 0, -1, 0};

char matrix [200] [200];
int n;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int count = 0;
            for (int k = 0; k < 5; k++)
            {
                int X = i + dX [k];
                int Y = j + dY [k];

                if (matrix [X] [Y] == '#')
                    count++;
            }

            if (count == 5)
            {
                for (int k = 0; k < 5; k++)
                {
                    int X = i + dX [k];
                    int Y = j + dY [k];

                    matrix [X] [Y] = 'A';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix [i] [j] == '#')
            {
                printf ("NO\n");
                return 0;
            }

    printf ("YES\n");

    return 0;
}











