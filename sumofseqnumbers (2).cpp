#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int a, b, n, p, root;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        a = ((i - 1) * i) / 2;
        b = n + a;
        root = sqrt (b * 2);
        cout<<a<<" "<<b<<" "<<root<<endl;
        if (root * (root + 1) / 2 == b || (root * (root - 1)) / 2 == b) {
            printf ("%d %d\n", i, root - 1);
            return 0;
        }
    }
    return 0;
}
