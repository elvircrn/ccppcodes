#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int myabs (int x) {
    if (x < 0) return x * (-1);
    else return x;
}
int jedan = 1, dva, sol, minimum = 1<<30;
int nesto [1000], a [100], b [100];
int n;
void rek (int l) {
    if (l == n) {
        jedan = 1;
        dva = 0;
        bool used = false;
        for (int i = 0; i < n; i++) {
            if (nesto [i]) {
                used = true;
                jedan *= a [i];
                dva += b [i];
            }
        }
        if (used) minimum = min (minimum, myabs (jedan - dva));
        return;
    }
    for (int i = 0; i < 2; i++) {
        nesto [l] = i;
        rek (l + 1);
    }
    return;
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &a [i], &b [i]);
    rek (0);
    printf ("%d\n", minimum);
    return 0;
}
