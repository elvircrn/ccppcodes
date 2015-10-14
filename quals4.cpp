#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

ll n, m, querry [100101], A, B, dp [310001], secondIND, cnt;

struct point {
    ll x, type;
    point () {}
    point (ll _x, ll _t) {x = _x; type = _t;}
    bool operator < (const point & xx) const {
        if ((*this).x == xx.x) return (*this).type > xx.type;
        else return (*this).x < xx.x;
    }
};

vector <point> points;

ll bs (ll p) {
    ll leftb = 0, rightb = points.size(), pivot;

    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (points [pivot].x <= p && p < points [pivot + 1].x) {
            int was = points [pivot].x;
            while (was == points [pivot + 1].x) pivot++;
            return pivot;
        }
        else if (p < points [pivot].x) rightb = pivot - 1;
        else leftb = pivot + 1;
    }

    return -1;
}

int main () {
    scanf ("%d %d", &n, &m);

    for (ll i = 0; i < m; i++) scanf ("%d", &querry [i]);

    for (ll i = 0; i < n; i++) {
        scanf ("%d %d", &A, &B);
        points.push_back (point (A, 1));
        points.push_back (point (B + 1, -1));
    }

    sort (points.begin (), points.end());

    for (ll i = 1; i <= points.size(); i++) dp [i] = dp [i - 1] + points [i - 1].type;

    for (ll i = 0; i < m; i++) printf ("%d\n", dp [bs (querry [i]) + 1]);

    return 0;
}

