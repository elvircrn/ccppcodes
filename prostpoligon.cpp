#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define bonus 100000005
using namespace std;
struct point {
    int x, y;
    point () {}
    point (int _x, int _y) {x = _x; y = _y;}
} help, points [1050];
bool found = false;
bool check (point a, point b, point c) {
    return ((c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y));
}
int t, n, a, b;
int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &a, &b);
            a += bonus;
            b += bonus;
            points [i] = point (a, b);
        }
        found = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int z = j + 1; z < n; z++) {
                    if (i == j || j == z || i == z) continue;
                    if (!check (points [i], points [j], points [z])) {
                        found = false;
                        printf ("NE\n");
                        goto l1;
                    }
                }
            }
        }
        if (found) printf ("DA\n");
        l1:;
    }
    return 0;
}
