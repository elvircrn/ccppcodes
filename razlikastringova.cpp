#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 1500

char A [MAXN], B [MAXN], razlika_stringova [MAXN];
int solution [MAXN] [27], sizeA, sizeB, SOLUTION;

int main ()
{
    scanf ("%s %s", &A, &B);

    sizeA = strlen (A);
    sizeB = strlen (B);

    for (int i = 0; i + sizeB < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if (B [j] != '?')
                SOLUTION += (B [j] == A [i]);
            else
                solution [j] [A [i] - 'a']++;
        }
    }

    for (int i = 0; i < sizeB; i++)
    {
        int maxn = 0, max_index = 0;
        for (int j = 0; j < 27; j++)
        {
            if (maxn < solution [i] [j])
            {
                maxn = solution [i] [j];
                max_index = j;
            }
        }
        SOLUTION += maxn;
        razlika_stringova [i] = char (maxn + 27);
    }

    printf ("%s\n", razlika_stringova);

    return 0;
}
