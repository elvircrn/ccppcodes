#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char A [100100], B [100100];
int index, ind [10], len, lenB;

int main()
{
    scanf ("%s %s", &A, &B);
    len = strlen (A);
    lenB = strlen (B);

    if (len != lenB)
    {
        printf ("NO\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (A [i] != B [i])
        {
            ind [index] = i,
            index++;
            if (index > 10)
                break;
        }
    }

    if (index > 2)
    {
        printf ("NO\n");
    }
    else if (A [ind [0]] == B [ind [1]] && A [ind [1]] == B [ind [0]])
        printf ("YES\n");
    else
        printf ("NO\n");
    return 0;
}
