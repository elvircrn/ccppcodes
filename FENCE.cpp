#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double n;

int main () {
    double r, O;
    while (true) {
        scanf ("%lf", &n);
        if (n < 1) break;
        r = n / (2 * M_PI);
        printf ("%.2lf\n", r * r * M_PI * 2);
    }
    return 0;
}
