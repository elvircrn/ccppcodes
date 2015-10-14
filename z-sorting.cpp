#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int array1 [50001], array2 [50002], n, carray1 [50001];

int BinarySearch (int x) {
    int leftb = 0, rightb = n, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (array1 [pivot] == x) return pivot;
        else if (array1 [pivot] > x) rightb = pivot - 1;
        else leftb = pivot + 1;
    }
    return 0;
}


int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &array1 [i]);
        carray1 [i] = array1 [i];
    }
    for (int i = 0; i < n; i++)
        scanf ("%d", &array2 [i]);

    sort (array1, array1 + n);
    sort (array2, array2 + n);

    for (int i = 0; i < n; i++)
        printf ("%d ", array2 [BinarySearch (carray1 [i])]); printf ("\n");

    return 0;
}
