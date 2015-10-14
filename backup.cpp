#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int array [100001];
unsigned long long int cnt;
int fast_pow ( int x, int n ) {
    if ( n == 0 ) return 1;
    if ( n % 2 == 0 ) {
        int t = fast_pow ( x, n / 2 );
        return ( t % 1000000007 * t % 1000000007 ) % 1000000007;
    }
    else {
        int t = fast_pow ( x, n - 1 );
        return ( x % 1000000007 * t % 1000000007 ) % 1000000007;
    }
}
int search (int m, int c, int r) {
    int sum, pivot, leftb = c, rightb = r;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        sum = array [c] + array [pivot];
        if (sum == m) {
            printf ("%d %d\n", c, pivot);
            return pivot;
        }
        else if (sum < m) leftb = pivot + 1;
        else if (sum > m) rightb = pivot - 1;
    }
    return -1;
}
int main () {
    /*int n, m, help;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &array [i]);
    sort (array, array + n + 1);
    for (int i = 1; i <= n; i++) {
        int s = search (m, i, n);
        if (s == -1) continue;
        else cnt += fast_pow (2, s - i - 1);
    printf ("%lld\n", cnt);
    }*/
    printf ("%d\n", fast_pow (2, 1000000));
    return 0;
}
