#include <isotream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct paradajz {
    int l, r, w;
    paradajz () {}
    paradajz (int _l, int _r, int _w) {l = _l; r = _r; w = _w;}
    bool operator < (const paradajz & xx) const
    {
        return w > xx.w;
    }
} array [1000000];
int n, d, a, sol, cnt;
int main () {
    scanf ("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
    }
    return 0;
}
