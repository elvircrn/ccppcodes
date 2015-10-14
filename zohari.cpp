#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long int ull;
ull base, exponent, mod;
int fast_pow (ull exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return base;
    if (exp % 2 == 0) {
        int t = fast_pow (exp / 2) % mod;
        return t * t;
    }
    else return fast_pow (exp - 1) % mod * base % mod;
}
int main () {
    cin>>base>>exponent>>mod;
    cout<<fast_pow (exponent)<<endl;
    return 0;
}
