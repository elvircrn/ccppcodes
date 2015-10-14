#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, q, brojnik, nazivnik, bs;

int calculate (int x) {
    return (x * (x + 1)) / 2;
}

int BinarySearch (int x) {
    int lb = 1, rb = 9999, pivot, pr;

    while (lb <= rb) {
        pr = pivot;
        pivot = (lb + rb) / 2;

        if (calculate (pivot) == x || ) return pivot;
        if (calculate (pivot) > x) rb = pivot - 1;
        else lb = pivot + 1;
    }

    return pivot;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &q);
        bs = BinarySearch (q);
        cout<<bs<<endl;
        if (bs % 2) {
            brojnik = q - calculate (bs);
            nazivnik = q - bs;
        }
        else {
            brojnik = q - calculate (bs);
            nazivnik = bs;
        }
        //printf ("%d/%d\n", brojnik, nazivnik);
    }
    return 0;
}
/*
2
7
14
*/
