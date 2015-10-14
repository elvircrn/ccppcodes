/*
8
2 3 1 4 5 7 2 14
3
1 5
4 7
2 5
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int q, tree [100000], n, a, b, array, MaxID;
void update (int index, int value) {
    while (index <= n) {
        tree [index] += value;
        index += index & (-index);
    }
}
int sum (int x) {
    int s = 0;
    while (x) {
        s += tree [x];
        n &= n & (-n);
    }
    return s;
}
int broj (int x) {
    return (sum (x) - sum (x - 1));
}
int update2 (int x, int value) {
    update (x, value - broj (x));
}
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &array);
        update (i, array);
    }
    for (int i = 0; i <= n; i++) {
        printf ("%d %d \n", i, tree [i]);
    }
    system ("pause");
    return 0;
}
