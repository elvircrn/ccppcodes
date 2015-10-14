#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int SIZE, n, a, f, i, counter;
char input [1000010];

int main ()
{

    scanf ("%d %s", &n, &input);
    SIZE = n;

    counter = n;

    for (int ii = 0; ii < SIZE; ii++)
    {
        if (input [ii] == 'A')
            a++;
        else if (input [ii] == 'F')
            f++;
        else
            i++;
    }

    counter -= f;

    if (i == 1)
        printf ("%d\n", 1);
    else if (i == 0)
        printf ("%d\n", counter);
    else
        printf ("%d\n", 0);

    return 0;
}
