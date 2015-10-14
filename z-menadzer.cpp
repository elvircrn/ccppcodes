#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef long long int ll;
ll dp [100001], n, a, b, c;
struct movie {
    ll p, k, o;
    movie () {}
    movie (ll _p, ll _k, ll _o) {p = _p; k = _k; o = _o;}
    bool operator < (const movie & x) const
    {
        return p < x.p;
    }
} array [100001], help;
ll bs (ll ind) {
    ll  minpivot = 200000;
    movie past = array [ind];
    ll leftb = ind, rightb = n - 1, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        help = array [pivot];
        if (past.k < help.p) {
            minpivot = min (minpivot, pivot);
            rightb = pivot - 1;
        }
        else if (past.k >= help.p) leftb = pivot + 1;
        else rightb = pivot - 1;
    }
    if (minpivot == 200000) return -1;
    else return minpivot;
}
int dostuff () {
    ll currentsum, maxsol = 0;
    for (ll i = 0; i < n; i++) {
        ll helpind = i;
        movie ds = array [i];
        currentsum = ds.o;
        //cout<<i<<endl;
        while (helpind < n - 1) {
            ll b = bs (helpind);
            if (b == -1) goto skip;
            helpind = b;
            movie now = array [helpind];
            if (dp [helpind] < currentsum + now.o) {
                dp [helpind] = currentsum + now.o;
                currentsum = dp [helpind];
            }
            //cout<<helpind<<" "<<currentsum<<endl;
            maxsol = max (maxsol, currentsum);
        }
        skip:;
        maxsol = max (maxsol, currentsum);
    }
    return maxsol;
}
int main () {
    scanf ("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        array [i] = movie (a, b, c);
    }
    sort (array, array + n);
    printf ("%d\n", dostuff());
    return 0;
}
