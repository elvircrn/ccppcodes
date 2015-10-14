#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
struct bomb {
    int pos, radius;
    bomb () {}
    bomb (int _p, int _r) {pos = _o; radius = _r;}
    bool operator < (const bomb & xx) const
    {
        return pos < xx.pos;
    }
};
bomb bombs [100001];
int n, array [i], ss, p, np, currentpos, it, cnt, maxsol, sol;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &array [i]);
    }
    for (int i = 0; i < n; i++) {
        scanf ("%d", &ss);
        bombs [i] = bomb (array [i], ss);
    }
    sort (bombs, bombs + n);
    it = bombs [0].pos + bombs [0].radius;

    for (i = 1; i < n; i++) {
        it += bombs [i].pos + bombs [i].radius;
    }
    return 0;
}
