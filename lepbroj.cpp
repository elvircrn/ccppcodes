#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, counter [100], solution;
char Number [1000100];

int main ()
{
    scanf ("%d %s", &n, &Number);

    if (n < 11)
    {
        for (int i = 0; i < n; i++)
        {
            if (counter [Number [i]])
                solution++;
            counter [Number [i]]++;
        }
    }
    else
    {
        for (int i = 0; i < n - 10; i += 10)
        {
            memset (counter, 0, sizeof counter);
            for (int j = 0; j < 10; j++)
            {
                if (counter [Number [i] - '0'])
                    solution++;
                counter [Number [i] - '0']++;
            }
        }
    }

    printf ("%d\n", solution);

    return 0;
}





