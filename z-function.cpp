/*
0 1 2
3 2 1
5
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int dp [2000000], a, b, c, f1, f2, f3, x;
int f (int n) {
    if (n == 1) return f1;
    else if (n == 2) return f2;
    else if (n == 3) return f3;
    if (dp [n]) return dp [n] % 10000;
    else dp [n] = (a % 10000 * (f (n - 1) % 10000)) % 10000  + b % 10000 * (f (n - 2) % 10000) % 10000 + c % 10000 * (f (n - 3) % 10000) % 10000;
}
int main () {
    scanf ("%d %d %d %d %d %d %d", &f1, &f2, &f3, &c, &b, &a, &x);
    for (int i = 1; i <= 10; i++) {
        printf ("%d %d \n", i, f (i));
    }
    return 0;
}
