#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int dp [100] [100], a, b;
int main () {
    dp [1] [1] = 1;
    scanf ("%d %d", &a, &b);
    a++;
    b++;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == 1 && j == 1 || i < j) continue;
            dp [i] [j] = dp [i - 1] [j] + dp [i] [j - 1];
        }
    }
    printf ("%d\n", dp [a] [b]);
    return 0;
}
