#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int sides [2001], n, cnt, j, z, sol;
int bs (int l, int r) {
    int pivot, leftb = l, rightb = r, minpivot = n;
    while (leftb < rightb) {
        //printf ("%d %d\n", leftb, rightb);
        pivot = (leftb + rightb) / 2;
        if (sides [l] + sides [r] < sides [pivot]) {
            minpivot = min (pivot, minpivot);
            rightb = pivot - 1;
            return pivot;
        }
        else if (sides [l] + sides [r] >= sides [pivot]) leftb = pivot + 1;
    }
    return minpivot;
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &sides [i]);
    sort (sides, sides + n);
    for (int i = 0; i < n - 2; i++) {
        z = bs (j, n);
        for (int j = i + 1; j < n - 1; j++) {
            int zz = z;
            z = j;
            cnt = sides [i] + sides [j];
            //if (cnt < sides [z]) sol += n - z - 1;
            //else zz = n - 1;
            while (cnt > sides [zz] && z < n) {zz++;}
            if (zz == n - 1 && cnt < sides [zz]) sol++;
            else sol += (n - 1) - z - 1;
            z++;
        }
    }
    printf ("%d\n", sol);
    return 0;
}
