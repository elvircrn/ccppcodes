#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int array [200041], n, q, a, b, sum [200041];
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &array [i]);
        sum [i] = sum [i - 1] + array [i];
    }
    scanf ("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf ("%d %d", &a, &b);
        printf ("%d\n", sum [b] - sum [a - 1]);
    }
    return 0;
}
