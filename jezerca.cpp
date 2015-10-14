#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, cnt, SOLUTION, array [1000000], leftright [1000000], rightleft [1000000], maxright;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {scanf ("%d", &array [i]); leftright [i] = max (leftright [i - 1], array [i]);}
    for (int i = n; i >= 1; i--) rightleft [i] = max (rightleft [i + 1], array [i]);
    for (int i = 1; i <= n; i++) {
        int d = min (rightleft [i], leftright [i]) - array [i];
        if (d == 0) {
            SOLUTION = max (cnt, SOLUTION);
            cnt = 0;
        }
        cnt += d;
    }
    printf ("%d\n", SOLUTION);
    return 0;
}

