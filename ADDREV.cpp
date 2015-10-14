#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int reverse (int x) {
    int rev = 0, cp = x;
    while (cp) {
        rev *= 10;
        rev += cp % 10;
        cp /= 10;
    }
    return rev;
}

int n, a, b;

int main () {
    scanf ("%d", &n);
    while (n--) {
        scanf ("%d %d", &a, &b);
        printf ("%d\n", reverse (reverse (a) + reverse (b)));
    }
    return 0;
}
/*
8 4
1
2
3
4
5
6
7
8
*/
