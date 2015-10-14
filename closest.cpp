#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char first [100], second [100], A [100], B [100], digits [100];
int lenA, lenB;
bool noZero = true, found = true;

int main ()
{
    scanf ("%s %s", &A, &B);

    lenA = strlen (A);

    for (int i = 0; i < lenA; i++)
        digits [B [i] - '0']++;

    int cnt = 0;

    while (digits [A [cnt] - '0'])
    {
        digits [A [cnt] - '0']--;
        first [cnt] = A [cnt];
        noZero = false;
        cnt++;
    }

    for (int i = cnt; i < lenA; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (digits [j] || (j == 0 && noZero == false && digits [j]))
            {
                noZero = false;
                digits [j]--;
                first [i] = j + '0';
            }
        }
    }

    for (int i = 0; i < lenA; i++)
        printf ("%c", first [i]);

    return 0;
}



