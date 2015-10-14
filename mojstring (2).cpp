#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char prvi [40], drugi [40];
int letters [1000], kopija [1000];

int formula(int *niz)
{
    int rez = 1;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        rez *= (niz [i] + 1);
    }

    return rez;
}

int main ()
{
    scanf ("%s %s", &prvi, &drugi);

    for (int i = 0; i < strlen (drugi); i++)
    {
        letters [drugi [i]]++;
        kopija [drugi [i]] = letters [drugi [i]];
    }

    int solution = 0;

    for (int i = 0; i < strlen (prvi); i++)
    {
        for (int j = 'A'; j < prvi [i]; j++)
        {
            if (!kopija [j])
            {
                continue;
            }
            kopija [j]--;
            solution += (formula(kopija) - 1);
            kopija [j]++;
        }
        kopija [prvi [i]]--;
    }

    printf ("%d\n", solution);

    return 0;
}
