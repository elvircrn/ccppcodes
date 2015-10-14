#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef unsigned long long int ull;
ull parent [1000001], tree_size [1000001];
ull Find (ull k) {
    if (parent [k] == k) return k;
    else return parent [k] = Find (parent [k]);
}
bool Union (ull x, ull y) {
    ull one = Find (x), two = Find (y);
    if (one == two) return 0;
    else {
        if (tree_size [one] <= tree_size [two]) {
            tree_size [two] += tree_size [one];
            parent [one] = two;
        }
        else {
            tree_size [one] += tree_size [two];
            parent [two] = one;
        }
    }
    return 1;
}
struct edge {
    ull n, m, w;
    edge () {}
    edge (ull _n, ull _m, ull _w) {n = _n; m = _m; w = _w;}
    bool operator < (const edge & xx) const
    {
        return w < xx.w;
    }
} help;
edge array [2020001];
ull v, safe, e, sol, cnt;
int main () {
    freopen ("in.txt", "r", stdin);
    ull a, b, c;
    scanf ("%d %d %d", &v, &safe, &e);
    for (ull i = 0; i <= v; i++) parent [i] = i, tree_size [i] = 1;
    for (ull i = 0; i < safe; i++) {
        scanf ("%llu %llu", &a, &b);
        if (Union (a, b)) cnt++;
    }
    ull ind = 0;
    for (ull i = 0; i < e; i++) {
        scanf ("%llu %llu %llu", &a, &b, &c);
        array [i] = edge (a, b, c);
        ind++;
    }
    sort (array, array + e);
    ull sol = 0;
    for (ull i = 0; i < e; i++) {
        help = array [i];
        help = array [i];
        if (Union (help.n, help.m)) {
            cnt++;
            sol += help.w;
        }
        //if (cnt > v) break;
    }
    cout<<sol<<endl;
    return 0;
}
