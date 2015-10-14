#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ull;

ull N;

ull process (ull x) {
    return (x * (x + 1));
}

bool binary_Search (int x) {

    int leftb = 1, rightb = 40000, pivot;

    while (leftb <= rightb) {

        pivot = process ((leftb + rightb) / 2);
        if (pivot == x) return true;
        else if (pivot < x) leftb = (leftb + rightb) / 2 + 1;
        else rightb = (leftb + rightb) / 2 - 1;

    }

    return false;

}

int main () {

    cin>>N;

    for (int i = 1; i <= 40000; i++) {
        if (binary_Search ((2 * N) - (i * i + i))) {
            printf ("YES\n");
            return 0;
        }
    }

    printf ("NO\n");

    return 0;
}
