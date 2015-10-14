#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 1000010

char A [MAXN], B [MAXN];
int current_index, solution [27], sizeA, sizeB, SOLUTION;
//vector <char> razlika_stringova;
char razlika_stringova [MAXN];

int main ()
{
    //freopen ("test_input.txt", "r", stdin);
    scanf ("%s %s", &A, &B);

    sizeA = strlen (A);
    sizeB = strlen (B);

    /*for (int i = 0; i < sizeB; i++)
    {
        for (int j = i; j <= sizeA - (sizeB - i); j++)
        {
            SOLUTION += (B [i] != A [j]);
            solution [i] [A [j] - 'a']++;
        }
    }*/

    int maximum;
    char index;

    for (int i = 0; i < sizeB; i++)
    {
        memset (solution, 0, sizeof solution);
        maximum = 0;
        index = 0;
        for (int j = i; j <= sizeA - (sizeB - i); j++)
        {
            solution [A [j] - 'a']++;
            SOLUTION += (B [i] != A [j]);
            if (solution [A [j] - 'a'] == maximum && index > A [j])
            {
                index = A [j];
            }
            if (solution [A [j] - 'a'] > maximum)
            {
                maximum = solution [A [j] - 'a'];
                index = A [j];
            }
        }
        if (B [i] != '?')
        {
            razlika_stringova [i] = B [i];
        }
        else
        {
            razlika_stringova [i] = index;
            SOLUTION -= maximum;
        }
    }

    /*for (int i = 0; i < sizeB; i++)
    {
        int maxn = 0, max_index = 0;
        for (int j = 0; j < 26; j++)
        {
            if (maxn < solution [i] [j])
            {
                maxn = solution [i] [j];
                max_index = j;
            }
        }

        if (B [i] == '?')
            SOLUTION -= maxn;

        if (B [i] == '?')
            razlika_stringova [current_index] = char (max_index + 'a');
            //razlika_stringova.push_back (char (max_index + 'a'));
        else
            razlika_stringova [current_index] = B [i];
            //razlika_stringova.push_back (B [i]);

        current_index++;
    }*/

    for (int i = 0; i < sizeB; i++)
        printf ("%c", razlika_stringova [i]);

    printf ("\n%d\n", SOLUTION);

    return 0;
}
