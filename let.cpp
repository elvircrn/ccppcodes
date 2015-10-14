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
ull k, n, T, c, l, t, dp [100111] [50], MAXIMUM;
int main () {
    cin>>k>>n>>T;
    for (ull i = 0; i < n; i++) {
        cin>>c>>l>>t;
        dp [t] [l] += c;
    }
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= k; j++) {
            if ((i) <= j) break;
            dp [i] [j] = max (max (dp [i - 1] [j], dp [i - 1] [j - 1]), dp [i - 1] [j + 1]) + dp [i] [j];
            MAXIMUM = max (MAXIMUM, dp [i] [j]);
        }
    }
    cout<<MAXIMUM<<endl;
    return 0;
}
