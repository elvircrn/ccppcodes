#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;


bool matrix[500] [500];
int t, p[50100], n;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &p [i]);
    char input[1000];

    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &input);
        for (int j = 0; j < n; j++)
        {
            matrix[i] [j] = (input [j] == '1');
        }
    }

    bool change = true;

    while (change)
    {
        change = false;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (p [i] > p [j] && matrix [i] [j])
                {
                    swap(p [i], p [j]);
                    change = true;
                }
            }
        }
    }

    printf ("%d", p [0]);
    for (int i = 1; i < n; i++)
        printf (" %d", p [i]);

    return 0;
}

/*
6
5 2 3 1 6 4
*/




