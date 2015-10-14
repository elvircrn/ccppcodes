#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int sum (int number)
{
    int ret = 0;

    while (number)
    {
        ret += (number % 10);
        number /= 10;
    }

    return ret;
}

int a, b, cnt [10000], solution, solution_index;

int main()
{
    scanf ("%d %d", &a, &b);

    int s = sum (a - 1);

    int start = (a / 10) * 10;
    int end   = (b / 10 + 1) * 10;

    for (int i = start; i <= end; i += 10)
    {
        int s = sum (i);

        cnt [s]++;
        cnt [s + 10]--;
    }

    for (int i = start; i <= a; i++)
    {
        cnt [sum (i)]--;
        cnt [sum (i) + 1]++;
    }

    for (int i = b + 1; i <= end; i++)
    {
        cnt [sum (i)]--;
        cnt [sum (i) + 1]--;
    }

    int current = 0;

    for (int i = 0; i <= 998; i++)
    {
        current += cnt [i];
        if (solution <= current)
        {
            solution = current;
            solution_index = i;
        }
    }

    printf ("%d\n", solution_index - 1);

    return 0;
}
/*
elvir
kerim
damir
samir
zile
mido

*/




