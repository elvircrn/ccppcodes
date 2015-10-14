#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
bool negative;
typedef long long int ull;
ull positive = -1, a, b, c, d, left1, left2, right1, right2, n, array [100001];
int main () {
    scanf ("%lld\n", &n);
    for (ull i = 0; i < n; i++) {
        scanf ("%lld", &array [i]);
        if (array [i] < 0) negative = 1;
    }
    for (ull i = 0; i < n; i++) {
        if (array [i] < 0) {
            positive = i;
            break;
        }
    }
    sort (array, array + n);
    left1 = array [0] * array [1];
    right2 = array [n - 2] * array [n - 1];
    if (left1 >= right2) printf ("%lld %lld ", array [0], array [1]);
    else printf ("%lld %lld ", array [n - 2], array [n - 1]);
    if (positive == -1) printf ("%d %d\n", array [0], array [1]);
    else if (negative) printf ("%lld %lld\n", array [0], array [n - 1]);
    else printf ("%lld %lld\n", array [0], array [1]);
    return 0;
}
