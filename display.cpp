#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, k, b, array [200], sum, solution;

int main ()
{
    scanf ("%d %d %d", &n, &k, &b);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        sum += array [i];
    }

    b = (b - 1) % n;

    int current_index = b;
    int cK = k;

    while (cK && (current_index < n))
    {
        solution += array [current_index];
        cK--;
        current_index++;
    }

    if (cK)
    {
        solution += (sum * (cK / n));

        for (int i = 0; i < cK % n; i++)
            solution += array [i];
    }

    printf ("%d\n", solution);

    return 0;
}
/*
10 20 1
1 2 3 4 5 6 7 8 9 10
*/
