#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long int ll;
ll n, t;
ll formula (ll x) {
    return ((x * (x + 1)) / 2);
}
int bs (ll x) {
    ll leftb = 0, rightb = 18000, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        ll f = formula (pivot), ff = formula (pivot - 1);
        //cout<<leftb<<" "<<rightb<<" "<<pivot<<" "<<f<<" "<<ff<<endl;
        if (ff <= x && x <= f) return pivot;
        else if (ff > x) rightb = pivot - 1;
        else leftb = pivot + 1;
    }
    return -1;
}
int main () {
    cin>>t;
    while (t--) {
        scanf ("%d", &n);
        printf ("%d\n", bs (n));
    }
    return 0;
}
