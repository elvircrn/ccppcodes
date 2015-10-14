#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
long long int nesto [3001], n, sol, cnt;
int main () {
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++) scanf ("%lld", &nesto [i]);
    sort (nesto, nesto + n);
    for (int i = 0; i < n / 2 + 1; i++) cnt += nesto [i] / 2 + 1;
    printf ("%lld\n", cnt);
    return 0;
}
