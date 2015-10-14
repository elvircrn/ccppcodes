#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int n;
double a, v0, h;
int main () {
    cin>>n>>a;
    for (int i = 0; i < n; i++) {
        scanf ("%lf %lf", &v0, &h);
        double j = v0 * v0;
        double t = 2 * a * h;
        double dd = j + t;
        double ddd = sqrt (dd);
        printf ("%.4lf\n", ddd);
    }
    return 0;
}
