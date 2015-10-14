#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int tree [200001], input, k, n, a, b;
int stand [200001];
void ADD (int pos, int val) {
    while (pos <= n) {
        tree [pos] += val;
        pos += pos & (-pos);
    }
}
int sum (int pos) {
    int suma = 0;
    while (pos) {
        suma += tree [pos];
        pos -= pos & (-pos);
    }
    return suma;
}
int main () {
    scanf ("%d %d", &n, &k);
    n++;
    for (int i = 0; i < k; i++) {
        scanf ("%d", &input);
        if (input == 1) {
            scanf ("%d %d", &a, &b);
            ADD (a, 1);
            ADD (b + 1, -1);
        }
        else {
            scanf ("%d", &a);
            printf ("%d\n", (sum (a) % 2));
        }
    }
    return 0;
}
