#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define MOD 1000000000

using namespace std;

bool mod;

typedef long long int ull;

ull n, m, one [2000], two [2000], cnt = 1;

ull digit_count (ull x) {
    ull sol = 0, COPY = x;
    while (COPY) {
        sol++;
        COPY /= 10;
    }
    return sol;
}

int main () {

    cin>>n;
    for (int i = 1; i <= n; i++) cin>>one [i];
    cin>>m;
    for (int i = 1; i <= m; i++) cin>>two [i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ull g = __gcd (one [i], two [j]);
            one [i] /= g;
            two [j] /= g;
            if (cnt * g > 1000000000) mod = true;
            cnt = (cnt % MOD) * (g % MOD);
            cnt %= MOD;
        }
    }
    if (digit_count (cnt) < 9 && mod) for (int i = 1; i <= 9 - digit_count (cnt); i++) cout<<"0";
    cout<<cnt<<endl;

    return 0;
}
