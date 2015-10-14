#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

long long int current_case, t, a, b, solution;

long long int get_rev (long long int x)
{
    int rev = 0, current = x;
    while (current)
    {
        rev *= 10;
        rev += (current % 10);
        current /= 10;
    }

    return rev;
}

int main ()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);

    scanf ("%lld", &t);
    while (t--)
    {
        int sol = 0;
        scanf ("%lld %lld", &a, &b);

        solution = 0;
        long long int s = sqrt (b);

        for (long long int i = 1; i <= s; i++)
        {
            if (a <= i * i && i * i <= b && get_rev (i * i) == i * i && get_rev (i) == i)
                solution++;
        }

        current_case++;
        printf ("Case #%lld: %lld\n", current_case, solution);
    }

    return 0;
}
/*
1
520001400003 1214428244121
*/
