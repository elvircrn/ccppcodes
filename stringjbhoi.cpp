#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

int solution, n, m, big [200], small [200], querry [200];
char c, input [200005], input1 [200005];

int main ()
{
    scanf ("%d %d", &n, &m);
    scanf ("%s", &input);

    scanf ("%s", &input1);

    for (int i = 0; i < m; i++)
        small [input1 [i] - 'A']++;

    /*while (isalpha (c = getchar()))
        small [c - 'A']++;*/

    for (int i = 0; i < m; i++)
    {
        querry [input [i] - 'A']++;
    }

    bool nasao = false;

    for (int i = 'A' - 'A'; i <= 'Z' - 'A'; i++)
        if (querry [i] != small [i])
        {
            nasao = true;
            break;
        }

    if (!nasao)
        solution = 1;

    for (int i = m; i < n; i++)
    {
        querry [input [i - m] - 'A']--;
        querry [input [i] - 'A']++;

        nasao = false;

        for (int j = 'A' - 'A'; j <= 'Z' - 'A'; j++)
            if (querry [j] != small [j])
            {
                nasao = true;
                break;
            }

        if (!nasao)
            solution++;
    }

    printf ("%d\n", solution);

    return 0;
}
/*
6
3
ACDDCD
DCD
*/
