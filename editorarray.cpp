#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector <char> A, B;
int t;

int main()
{
    char c;

    while (isalpha (c = getchar()))
    {
        A.push_back (c);
    }

    scanf ("%d", &t);
    char q[2];
    for (int i = 0; i < t; i++)
    {
        scanf ("%s", &q);
        if (q [0] == 'L')
        {
            if (A.empty())
                continue;
            B.push_back (A [A.size() - 1]);
            A.pop_back();
        }
        else if (q [0] == 'D')
        {
            if (B.empty())
                continue;

            A.push_back (B [B.size() - 1]);
            B.pop_back();
        }
        else if (q [0] == 'B')
        {
            if (A.empty())
                continue;
            A.pop_back();
        }
        else
        {
            scanf ("%s", &q);
            A.push_back (q [0]);
        }
    }

    for (int i = 0; i < A.size(); i++)
        putchar (A [i]);
    for (int i = B.size() - 1; i >= 0; i--)
        putchar (B [i]);
    putchar ('\n');

    return 0;
}




