#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

ll fast_pow (ll base, ll exponent, ll mod) {
    if (exponent == 0) return 1LL;
    else if (exponent == 1) return (base % mod);
    else if (exponent % 2 == 0) {ll t = fast_pow (base, exponent / 2, mod); t %= mod; return ((t * t) % mod);}
    else return ((fast_pow (base, exponent - 1, mod) % mod) * (base % mod)) % mod;
}

ll g [20000000];

int main () {

    unsigned long long int A = 2, B = 500000000000000, C = 20092010;

    cout<<B<<endl;

    cout<<fast_pow(A, B, C)<<endl;

    for (int i = 0; i <= 1999; i++) g [i] = 1;

    for (int i = 2000; i <= 100000; i++) {
        g [i] = g [i - 2000] + g [i - 1999];
        if (i % 2000 == 0) {
            cout<<i<<" : "<<g [i]<<endl;
        }
    }

    return 0;
}
