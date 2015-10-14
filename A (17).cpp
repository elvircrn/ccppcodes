#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int sol, n, q [10000], p [10000];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d", &p [i], &q [i]);
        sol += (q [i] - p [i]) >= 2;
    }

    printf ("%d\n", sol);

    return 0;
}
