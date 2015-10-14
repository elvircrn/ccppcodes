#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int tree [100], a, b, n, q, x, y;
void set (int index, int value) {
    while (index <= n) {
        cout<<index<<endl;
        tree [index] += value;
        index += index & (-index);
    }
}
int findsum (int index) {
    int sum = 0;
    while (index) {
        sum += tree [index];
        index -= index & (-index);
    }
    return sum;
}
int sum (int j, int k) {
    return (findsum(k) - findsum(j - 1));
}
int main () {
    int a;
    scanf ("%d", &n);
    while (1) {
        scanf ("%d", &a);
        set (a, 1);
    }
    /*for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        set (i, x);
    }
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf ("%d %d", &x, &y);
        printf ("%d \n", sum (x, y));
    }*/
    return 0;
}
/*
8
2 3 1 4 5 7 2 14
3
1 5
4 7
2 5
*/
