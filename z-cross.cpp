#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int negative = 1e-10;
int n;
double a, b, minimum = 10000000.0000;
bool customcompare (double x, double y) {
    return ((x - y) < negative);
}
struct point {
    double a, b;
    point () {}
    point (double _a, double _b) {a = _a; b = _b;}
    bool operator < (const point & x) const
    {
        return a < x.a;
    }
    bool operator == (const point & x) const
    {
        return (a == x.a && b == x.b);
    }
} points [50001];
double generateminimum (double x, double y) {
    double a1, b1, a2, b2, cnt;
    a1 = x;
    b1 = y;
    /*if (customcompare (points [0].a, x) && customcompare (points [0].b, b)) {
        a2 = points [1].a;
        b2 = points [1].b;
    }
    else {*/
        a2 = points [n - 1].a;
        b2 = points [n - 1].b;
    //}
    cnt = (a2 - a1) / (b2 - b1);
    return (double) (-1) * (double) cnt;
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%lf %lf", &a, &b);
        points [i] = point (a, b);
    }
    sort (points, points + n);
    for (int i = 0; i < n; i++)
        minimum = min (generateminimum (points [i].a, points [i].b), minimum);
    printf ("%.2lf\n", minimum);
    return 0;
}
