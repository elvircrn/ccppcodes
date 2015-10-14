#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int s, n, k, d [1000], full, SOLUTION;
void solve (int progress, int index) {
    if (progress > full / 2) SOLUTION ++;
    for (int i = index; i < n; i++) {
        solve (progress + d [i], i + 1);
    }
    return;
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &d [i]);
        full += d [i];
    }
    solve (0, 0);
    printf ("%d\n", SOLUTION);
    return 0;
}
