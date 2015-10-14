#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int n, m;
bool current;
char matrix [101] [101];

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        current = i % 2;
        scanf ("%s", &matrix [i]);
        for (int j = 0; j < m; j++)
        {
            if (matrix [i] [j] != '-')
            {
                if (current)
                    printf ("B");
                else
                    printf ("W");
            }
            else
                printf ("-");
                current = !current;
        }


        printf ("\n");
    }


    return 0;
}
