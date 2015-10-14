#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef long long int ll;
ll ind = 1;
string words [10001], word, rijeci [10001];
ll n, bit [10001];
void set (ll indd, ll val) {
    while (indd <= ind + 5) {
        bit [indd] += val;
        indd += indd & (-indd);
    }
    return;
}
ll sum (ll indd) {
    ll s = 0;
    while (indd) {
        s += bit [indd];
        indd -= indd & (-indd);
    }
    return s;
}
ll bs (string a) {
    ll leftb = 0, rightb = n, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (rijeci [pivot] == a) return pivot;
        else if (rijeci [pivot] < a) leftb = pivot + 1;
        else rightb = pivot - 1;
    }
    return -1;
}
int main () {
    ll ss;
    cin>>n;
    ind = n;
    for (ll i = 1; i <= n; i++) {
        cin>>words [i];
        rijeci [i] = words [i];
    }
    sort (rijeci, rijeci + n + 1);
    for (ll i = 1; i <= n; i++) {
        ll b = bs (words [i]);
        set (b, 1);
        ss = sum (b - 1);
        int ddd = sum (i), dd = sum (b);
        cout<<ss<<" "<<(i - ss) - (sum (b) - ss)<<endl;
    }
    return 0;
}
