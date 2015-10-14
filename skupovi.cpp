#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
typedef long long int ull;
ull n, k, array [1100101], cnt, sol, bs;
ull fast_pow (ull base, ull exponent, ull mod) {
    if (exponent == 0) return 1;
    else if (exponent == 1) return base % mod;
    else if (exponent % 2 == 0) {
        ull t = fast_pow (base, exponent / 2, mod) % mod;
        return t % mod * t % mod;
    }
    else return fast_pow (base, exponent - 1, mod) % mod * base % mod;
}
ull binarysearch (ull element, ull l, ull r) {
    ull leftb = l, rightb = r, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (pivot < 0 || pivot > 100001) return 0;
        if (array [pivot] == element) {
            if (pivot == l - 1) return 0;
            cnt += fast_pow (2, pivot - l - 1,  1000000007);
            cnt %= 1000000007;
            return 0;
        }
        else if (array [pivot] > element) rightb = pivot - 1;
        else leftb = pivot + 1;
    }
    return (0);
}
int main () {
    cin>>n>>k;
    for (ull i = 0; i < n; i++) cin>>array [i];
    sort (array, array + n);
    for (ull i = 0; i < n; i++) {
        if (k - array [i] < 0) break;
        binarysearch (k - array [i], i, n - 1);
        cnt %= 1000000007;
    }
    cout<<cnt<<endl;
    return 0;
}

/*
6 11
2 4 6 8 10 12

0


5 9
7 2 9 5 4

5
*/
