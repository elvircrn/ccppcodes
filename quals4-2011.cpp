#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n, m, querry [100001], nn, leftb, rightb;
int bit [3950000];
int sum (int indd) {
    int s = 0;
    while (indd) {
        s += bit [indd];
        indd -= indd & (-indd);
    }
    return s;
}
void set (int indd, int val) {
    while (indd <= nn +5) {
        bit [indd] += val;
        indd += indd & (-indd);
    }
}
int main () {
    scanf ("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {scanf ("%d", &querry [i]); nn = max (nn, querry [i]);}
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &leftb, &rightb);
        if (leftb > nn) continue;
        set (leftb, 1);
        set (rightb + 1, -1);
    }
    for (int i = 0; i < n; i++) {
        printf ("%d\n", sum (querry [i]));
    }
    return 0;
}
