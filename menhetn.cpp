#include <cstdio>#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
long long int mindist = 536870912;
struct point {
    int x, y;
    point () {}
    point (long long int _x, long long int _y) {x = _x; y = _y;}
} help;
point points [1001];
long long int a, b, d, n, cnt;
long long int myaps (long long int f) {
    if (f > -1) return f;
    else return f * (-1);
}
long long int calculate (point one, point two) {
    return (myaps (one.x - two.x) + myaps (one.y - two.y));
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        points [i] = point (a, b);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
             mindist = min (mindist, calculate (points [i], points [j]));
    printf ("%d\n", mindist);
    return 0;
}

