#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int sides [5000], n = 123, cnt, j, z, sol, hash [1500001], maxn;

int main () {
    while (true) {
        scanf ("%d", &n);
        if (n == 0) break;
        for (int i = 0; i <= n + 100; i++) hash [i] = 0; sol = 0; maxn = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &sides [i]);
            hash [sides [i] - 1]++;
            maxn = max (sides [i], maxn);
        }
        sort (sides, sides + n);
        for (int i = maxn - 1; i >= 0; i--) {
            hash [i] = hash [i + 1] + hash [i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (maxn < sides [i] + sides [j]) continue;
                sol += hash [sides [i] + sides [j]];
            }
        }
        printf ("%d\n", sol);
    }
    return 0;
}
