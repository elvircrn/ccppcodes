#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
double x = 1;
int solve (double d) {
    double me = 0;
    int cnt = 1;
    while (me < d) {
        cnt++;
        me += double (double (1) / double (cnt));
    }
    return cnt - 1;
}
int main () {
    scanf ("%lf", &x);
    while (x) {
        printf ("%d card(s)\n", solve (x));
        scanf ("%lf", &x);
    }
    return 0;
}
