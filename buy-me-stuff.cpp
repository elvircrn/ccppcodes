#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int array [20001], t, n, sol;
int main () {
    scanf ("%d", &t);
    while (t--) {
        sol = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) scanf ("%d", &array [i]);
        if (n < 3) {printf ("0 \n"); continue;}
        sort (array, array + n + 1);
        n -= 2;
        for (int i = n; i >= 1; i -= 3) {sol += array [i];}
        printf ("%d \n", sol);
    }
    return 0;
}
