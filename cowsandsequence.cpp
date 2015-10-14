#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ll;

ll solution, current_index(1), x, a, t, val[200100], add [200100];

int main()
{
    scanf ("%I64d ", &t);
    while(t--)
    {
        int q;
        scanf ("%I64d ", &q);
        if (q == 1)
        {
            scanf ("%I64d  %I64d ", &a, &x);
            solution += x * a;
            add [a] += x;
        }
        else if (q == 2)
        {
            scanf ("%lld", &x);
            current_index++;
            val[current_index] = x;
            solution += x;
        }
        else
        {
            if (current_index > 1)
            {
                solution -= (val [current_index] + add [current_index]);
                add [current_index - 1] += add [current_index];
                add [current_index] = 0;
                val [current_index] = 0;
                current_index--;
            }
        }

        printf ("%.7f\n", (float)solution / (float)current_index);
    }

    return 0;
}







