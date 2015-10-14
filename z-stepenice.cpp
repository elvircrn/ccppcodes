#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef unsigned long long int ul;
unsigned long long int n, k, dp [100001];
int main () {
    cin>>n>>k;
    for (int i = 1; i <= k; i++) {
        for (int j = i; j > 0; j--) {
            dp [i] += dp [j] % 1021987;
        }
        dp [i]++;
        dp [i] = dp [i] % 1021987;
    }
    if (n <= k) {printf ("%d\n", dp [n]); return 0;}
    for (int i = k + 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp [i] += dp [i - j] % 1021987;
        }
            dp [i] %= 1021987;
    }
    cout<<dp [n] % 1021987<<endl;
    return 0;
}
