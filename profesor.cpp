#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int cnt, sol, maxn, n;
struct klupa {
    int a, b;
    klupa () {}
    klupa (int _a, int _b) {a = _a; b = _b;}
} klupe [5000];
int main () {
    int x, y;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &x, &y);
        klupe [i] = klupa (x, y);
    }
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            if (klupe [j].a != i && klupe [j].b != i) cnt = 0;
            else if (klupe [j].a == i || klupe [j].b == i) {
                cnt++;
                if (maxn < cnt) {
                    maxn = cnt;
                    sol = i;
                }
            }
        }
        cnt = 0;
    }
    printf ("%d %d\n", maxn, sol);
    return 0;
}
