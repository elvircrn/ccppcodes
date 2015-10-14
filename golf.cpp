#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

double ballx, bally, stickx, sticky;

double distance (double x1, double y1, double x2, double y2) {
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check (double x, double y) {
    return (double (double (2) * distance (ballx, bally, x, y)) < distance (stickx, sticky, x, y));
}

int main () {

    int n;
    double x, y;

    scanf ("%lf %lf %lf %lf %d", &ballx, &bally, &stickx, &sticky, &n);

    for (int i = 1; i <= n; i++) {
        scanf ("%lf %lf", &x, &y);
        if (check (x, y)) {
            printf ("%d\n", i);
            return 0;
        }
    }

    printf ("Nadrljao je!\n");

    return 0;
}
