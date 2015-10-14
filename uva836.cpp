#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n;
char matrix [100] [100];
int m [100] [100];

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%s", &matrix [0]);

        n = strlen (matrix [0]);
        for (int i = 1; i < n; i++)
            scanf ("%s", &matrix [i]);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m [i] [j] = (matrix [i] [j] == '1');
            }
        }
    }

    return 0;
}
