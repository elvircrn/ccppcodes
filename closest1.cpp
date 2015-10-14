#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char first [100], second [100], A [100], B [100], digitsB [100];
int lenA, lenB;
bool noZero = true, nasao;

int main ()
{
    scanf ("%s %s", &A, &B);

    lenA = strlen (A);

    for (int i = 0; i < lenA; i++)
        digitsB [B [i] - '0']++;

    for (int i = 0; i < lenA; i++)
    {
        if (nasao)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (digitsB [j])
                {
                    first [i] = j + '0';
                    digitsB [i]--;
                    break;
                }
            }
        }
        else
        {
            for (int j = A [i] - '0'; j <= 9; j++)
        }
    }

    return 0;
}
