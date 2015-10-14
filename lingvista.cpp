#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef long long int ll;
struct mystring {
    string String;
    ll pastind;
    mystring () {}
    mystring (string S, ll past) {String = S; pastind = past;}
    bool operator < (const mystring & xx) const
    {
        return String < xx.String;
    }
} rijeci [100001];
char a [5];
ll ind = 0, ind2 = 0;
bool commands [100001];
string words [100001], word;
ll n, bit [100001], nesto [100001], bithelp [100001];
void set (ll indd, ll val) {
    while (indd <= ind) {
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
    ll leftb = 1, rightb = ind + 1, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (rijeci [pivot].String == a) return pivot;
        else if (rijeci [pivot].String < a) leftb = pivot + 1;
        else rightb = pivot - 1;
    }
    return -1;
}
int main () {
    cin>>n;
    for (ll i = 1; i <= n; i++) {
        cin>>a>>words [i];
        for (ll kk = 0; kk < words [i].length(); kk++) words [i] [kk]= tolower (words [i] [kk]);
        if (a [0] == 'A') {
            ind++;
            rijeci [ind] = mystring (words [i], ind);
        }
        else commands [i] = 1;
    }
    sort (rijeci, rijeci + ind + 1);
    for (ll i = 1; i <= n; i++) {
        ll b = bs (words [i]);
        if (!commands [i]) {
            if (nesto [b] == 0) {
                ind2++;
                set (b, 1);
                bithelp [b] = 1;
                nesto [b] = 1;
            }
        }
        else {
            if (b == -1 || bithelp [b] == 0) puts ("no such word");
            else if (b == 1) puts ("0");
            else printf ("%lld\n", sum (b - 1));
        }
    }
    return 0;
}
