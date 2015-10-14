#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int dp [1010] [1010], n, m, a, b, c, SOLUTION;

void set_values (int x, int y, int z) {
    int X1 = x, X2 = x, Y1 = y, Y2 = y + 1;
    int b1 = X1, b2 = Y1, b3 = X2, b4 = Y2; X1 -= z; X2 -= z;
    for (int i = 0; i <= z; i++) {
        bool found = false;
        if (X1 > 0 && Y1 > 0 && X1 <= m && Y1 <= m) {
            dp [X1] [Y1]++;
            found = true;
        }
        else if (X1 > 0 && X1 <= m) dp [X1] [1]++;
        if (X2 > 0 && Y2 > 0 && X2 <= m && Y2 <= m) {
            dp [X2] [Y2]--;
        }
        X1++; Y1--;
        X2++; Y2++;
    }
    X1 = b1; Y1 = b2; X2 = b3; Y2 = b4; X1 += z; X2 += z;
    for (int i = 0; i < z; i++) {
        bool found = false;
        if (X1 > 0 && Y1 > 0 && X1 <= m && Y1 <= m) {
            dp [X1] [Y1]++;
            found = true;
        }
        else if (X1 > 0 && X1 <= m) dp [X1] [1]++;
        if (X2 > 0 && Y2 > 0 && X2 <= m && Y2 <= m) {
            dp [X2] [Y2]--;
        }
        X1--; Y1--;
        X2--; Y2++;
    }
    return;
}

int main() {

    scanf ("%d %d", &n, &m); swap (n, m);
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        set_values (a, b, c);
    }

    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt += dp [i] [j];
            SOLUTION = max (cnt, SOLUTION);
        }
    }

    printf ("%d", SOLUTION);

    return 0;
}
/*
5 1
1 1 2
*/
