#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int takmicari [101] [10001], d = 0, in, i, j, x, y, start;
int main () {
    //freopen ("tt.txt", "r", stdin);
    //freopen ("takmicari.txt", "w", stdout);
    while (1) {
        scanf ("%d", &in);
        if (in == 0) {
            scanf ("%d %d", &x, &start);
            d++;
        }
        if (in == 3) break;
        if (in == 1) {
            scanf ("%d %d", &x, &y);
            takmicari [d] [x] += y;
        }
        if (in == 2) {
            scanf ("%d", &x);
            printf ("%d\n", takmicari [d] [x] + start);
        }
    }
    return 0;
}
