#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
struct solution {
    unsigned long long int b, e;
    bool find;
    solution () {find = 0;}
} help;
solution asd;
unsigned long long int a, b, leftb, rightb;
unsigned long long int fast_pow (unsigned long long int base, unsigned long long int exp) {
    unsigned long long int solution = 1;
    if (exp % 2) solution = base;
    while (exp >>= 1) {
        base *= base;
        if (exp % 2) solution = solution * base;
    }
    return solution;
}
solution solve (unsigned long long int x) {
    unsigned long long int lef = 1, rig = 63;
    while (lef <= rig) {
        //printf ("%lld %lld\n", lef, rig);
        unsigned long long int pivot = (lef + rig) / 2;
        unsigned long long int k = fast_pow (x, pivot);
        if (a <= k && k <= b && (k * x) > b) {
            printf ("%lld %lld\n", x, pivot);
            exit (0);
        }
        else if (k < a || (k < b && k * x < b)) lef = pivot + 1;
        else if (k > b) rig = pivot - 1;
    }
    return asd;
}
int main () {
    scanf ("%lld %lld", &a, &b);
    leftb = sqrt (a);
    rightb = sqrt (b);
    for (int i = leftb; i <= rightb; i++) {
        help = solve (i);
        if (help.find) {
            printf ("%lld %lld\n", help.b, help.e);
            return 0;
        }
    }
    return 0;
}
