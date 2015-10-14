#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;
int sum (int n) {
    return ((n * (n + 1)) / 2);
}
int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n / 2 + 1; i++) {
        int sum = 0;
        for (int j = i; j <= n / 2 + 1; j++) {
            sum += j;
            //printf ("i: %d sum: %d\n", i, sum);
            if (sum == n) {
                printf ("%d %d\n", i, j - 1);
                return 0;
            }
            else if (sum > n) break;
        }
    }
    return 0;
}
