#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ull;

ull fast_pow (ull base, ull exponent) {
    if (exponent == 0) return 1;
    else if (exponent == 1) return base;
    else if (exponent % 2 == 0) {ull t = fast_pow (base, exponent / 2); return t * t;}
    else return fast_pow (base, exponent - 1) * base;
}

ull N, help, it = 1, BROJ;

int main () {

    scanf ("%lld", &N);

    while (help + fast_pow (2, it) < N) {
        help += fast_pow (2, it);
        it++;
    } N -= (help + 1);

    for (int i = it - 1; i > -1; i--)
        if (N & fast_pow (2, i))
            printf ("7");
        else
            printf ("4"); printf ("\n");

    return 0;

}
