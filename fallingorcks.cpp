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
        printf ("%.4lf\n", sqrt (v0 * v0 + 2 * a * h));
    }
    return 0;
}
