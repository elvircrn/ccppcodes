#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, a, hash [100000], cnt, d;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        hash [a] = i;
        if (a == 1) d = i;
    }
    for (int i = 1; i < d; i++) {
        cnt += i;
        cnt %= 10000;
    }
    printf ("%d\n", cnt);
    return 0;
}
