#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

char choices [4] [221];

int main()
{
    int ind;
    int count(0);
    for (int i = 0; i < 4; i++)
        scanf ("%s", &choices [i]);

    for (int i = 0; i < 4; i++)
    {
        bool found = true;
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;

            int lenA = strlen (choices [i]) - 2;
            int lenB = strlen (choices [j]) - 2;

            if ((lenA <= lenB / 2) == false)
            {
                found = false;
                break;
            }
        }

        if (found == true)
        {
            count++;
            ind = i;
            continue;
        }

        found = true;
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;

            int lenA = strlen (choices [i]) - 2;
            int lenB = strlen (choices [j]) - 2;

            if ((lenA >= lenB * 2) == false)
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            count++;
            ind = i;
        }
    }

    if (count == 1)
    {
        printf ("%c\n", ind + 'A');
    }
    else
        printf ("C\n");

    return 0;
}
