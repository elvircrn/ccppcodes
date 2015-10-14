#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int sides [2001], n, cnt, j, z, sol, hash [1000001], maxn;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &sides [i]);
        hash [sides [i] - 1]++;
        maxn = max (sides [i], maxn);
    }

    sort (sides, sides + n);
    for (int i = maxn - 1; i >= 0; i--)
        hash [i] = hash [i + 1] + hash [i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (maxn >= sides [i] + sides [j])
                sol += hash [sides [i] + sides [j]];

    printf ("%d\n", sol);

    return 0;
}
