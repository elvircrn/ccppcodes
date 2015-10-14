#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MOD 1000000007

typedef unsigned long long int ull;

ull n, x, dva, cetiri;

ull fast_pow (ull base, ull exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base % MOD;
    if (exp % 2 == 0) {
        ull t = fast_pow (base, exp / 2);
        return t * t;
    }
    else return ((base % MOD) * (fast_pow (base, exp - 1))) % MOD;
}

ull calc (ull nn) {
    return((nn * (nn + 1)) / 2);
}

int main () {
    cin>>n;
    cetiri = fast_pow (4, n);
    dva = fast_pow (2, n);
    cout<<cetiri - calc (dva - 1)<<endl;
    return 0;
}



