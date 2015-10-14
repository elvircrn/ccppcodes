#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a, b, c, x, y, z, cnt, sol, maxn, help;
double minn = 100000;
int main () {
    scanf ("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
    for (int i = 500; i > 0; i--) {
        if (x % i == 0 && y % i == 0 && z % i == 0) {
            x /= i;
            y /= i;
            z /= i;
            break;
        }
    }
    minn = min (double (a) / double (x), min (double (b) / double (y), double (c) / double (z)));
    cout<<a - (x * minn)<<" "<<b - (y * minn)<<" "<<c - (z * minn)<<endl;
    return 0;
}
