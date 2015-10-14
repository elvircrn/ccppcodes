#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int array [10];

int main ()
{
    int n = 5;
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    while (true)
    {
        bool promjena = false;

        for (int i = 0; i < n - 1; i++)
            if (array [i] > array [i + 1])
            {
                promjena = true;
                swap (array [i], array [i + 1]);
                for (int i = 0; i < n; i++)
                    printf ("%s%d", (i ? " " : ""), array [i]);
                printf ("\n");
            }

        if (!promjena)
            break;
    }


    return 0;
}
