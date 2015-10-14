#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll f (ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) {
    return ((a2 - a1) * (a2 - a1) + (c2 - c1) * (c2 - c1) + (b2 - b1) * (b2 - b1));
}
ll n, x1, y1, z1, x2, y2, z2, array [5001], cnt = 0;
int main () {
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
        array [i] = f (x1, y1, z1, x2, y2, z2);
    }
    ll cnt = 1;
    sort (array, array + n);
    for (ll i = 1; i < n; i++) {
        if (array [i] != array [i - 1]) cnt++;
    }
    printf ("%lld\n", cnt);
    return 0;
}
