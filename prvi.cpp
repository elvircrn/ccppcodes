#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int n, dd, k, cnt, array [20];
int main () {
    scanf ("%d", &k);
    for (int i = 0; i < 12; i++) {
        scanf ("%d", &array [i]);
        dd += array [i];
    }
    if (dd < k) {
        cout<<"-1"<<endl;
        return 0;
    }
    sort (array, array + 12);
    int d = 11;
    while (cnt < k) {
        cnt += array [d];
        d--;
    }
    printf ("%d\n", 12 - d - 1);
    return 0;
}
/*
asdasd
*/
