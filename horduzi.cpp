#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a, b, c, n, cnt, sol, maxn, lb, rb;
struct point {
    int xa, xb, y;
    point () {}
    point (int _a, int _b, int _c) {y = _a; xa = _b; xb = _c;}
    bool operator < (const point xx) const
    {
        return y < xx.y;
    }
} help, points [100001];
bool compare (point aa, point bb) {
    if (aa.xa != min (aa.xa, aa.xb)) swap (aa.xa, aa.xb);
    if (bb.xa != min (bb.xa, bb.xb)) swap (bb.xa, bb.xb);
    if (aa.xb < bb.xa || bb.xb < aa.xa) return 0;
    else return 1;
}
int main () {
    //freopen ("horduzi.txt", "r", stdin);
    scanf ("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        points [i] = point (a, b, c);
    }
    sort (points, points + n);
    cnt = n;
    for (int i = 1; i < n; i++) {
        if (points [i - 1].y != points [i].y) {
            lb = i;
        }
            for (int j = i; j >= lb; j--) {
                if (compare (points [i], points [j])) {cnt--; goto l1;}
            }
        l1:;
    }
    printf ("%d\n", cnt + 2);
    return 0;
}
