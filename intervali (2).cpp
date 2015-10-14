#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b, ll, rr, cnt, maxn;
struct field {
    int l, r;
    field () {}
    field (int _l, int _r) {l = _l; r = _r;}
    bool operator < (const field & xx) const
    {
        return l < xx.l;
    }
} help, array [60000];
int j = 0, z = 0;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        array [i] = field (a + 0, b + 0);
    }
    if (n == 1) {printf ("1\n"); return 0;}
    sort (array, array + n);
    for (int i = 0; i < n - 1; i++) {
        ll = array [i].l;
        rr = array [i].r;
        cnt = 1;
        for (j = i + 1; j < n; j++) {
            if (rr <= array [j].l) {
                cnt++;
                maxn = max (cnt, maxn);
                ll = array [j].l;
                int minp = 1000000;
                minp = min (minp, array [j].r);
                for (z = j; z < n && (array [j].l == array [z].l); z++) {
                    minp = min (minp, array [z].r);
                }
                j = z - 1;
                rr = minp;
            }
        }
    }
    printf ("%d\n", maxn);
    return 0;
}





