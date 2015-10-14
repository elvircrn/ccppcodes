#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
//778000

using namespace std;

bool isPrime [810000];

void GeneRatePrimes (int bound) {

    int S = sqrt (bound) + 5;

    for (int i = 2; i <= S + 5; i++) {

        if (!isPrime [i]) continue;

        for (int j = i * i; j <= bound; j += i) {
            isPrime [j] = false;
        }
    }

    return;
} //600851475143

const long long int N = 600851475143;

int main () {

    memset (isPrime, true, sizeof isPrime);

    GeneRatePrimes(800000);

    for (long long int i = 780000; i >= 2; i--)
        if (isPrime [i] && 600851475143 % i == 0) {
            printf ("%lld\n", i); break;
        }

    return 0;
}
