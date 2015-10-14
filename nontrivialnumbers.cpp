#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, sol;
double sum, minimum = 1<<30, cnt;
int main () {
    scanf ("%d %d", &n, &m);
    if (n == 1) {
        printf ("%d \n", n);
        return 0;
    }
    for (int i = n; i <= m; i++) {
        sum = 0;
        for (int j = 1; j < i / 2 + 1; j++)
            if (i % j == 0)
                sum += j;
        cnt = sum / n;
        if (minimum > cnt) {
            minimum  = cnt;
            sol = i;
        }
    }
    printf ("%d \n", sol);
    return 0;
}
