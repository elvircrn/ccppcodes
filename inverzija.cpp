#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char A [1000100], B [1000100];
int Size, solution;
bool same = true;

int main ()
{

    scanf ("%s %s", &A, &B);

    Size = strlen (A);

    for (int i = 0; i < Size; i++)
    {
        if (same == true && A [i] != B [i])
        {
            solution++;
            same = false;
        }
        else if (A [i] == B [i])
            same = true;
    }

    printf ("%d\n", solution);

    return 0;
}
