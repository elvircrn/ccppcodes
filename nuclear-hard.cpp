#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int rsolution, n, c_reactors [1000100], reactors [1000100];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &reactors [i]);
        c_reactors [i] = reactors [i];
    }

    sort (reactors, reactors + n);

    int solution = 0;

    for (int i = 0; i < n; i++)
    {
        rsolution += (c_reactors [i] != reactors [n - (i + 1)]);
        solution += (c_reactors [i] != reactors [i]);
    }

    printf ("%d\n", min (rsolution, solution));

    return 0;
}
