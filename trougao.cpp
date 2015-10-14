#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define MIN 1e-5
double myabs (double x) {
    if (x < 0) return (x * (-1));
    else return x;
}
bool customcompare (double one, double two) {
    return (myabs (one - two) < MIN);
}
int n, cnt, maximum;
double xx, yy;
struct point {
    double x, y;
    point () {}
    point (double _x, double _y) {x = _x; y = _y;}
} points [100];
double area (point one, point two, point three) {
    double help = one.x * (two.y - three.y) + two.x * (three.y - one.y) + three.x * (one.y - two.y);
    return (myabs (help / 2));
}
bool check (point one, point two, point three, point four) {
    double BIGAREA = area (one, two, three), area1 = area (one, two, four), area2 = area (two, three, four), area3 = area (one, three, four);
    return customcompare (BIGAREA, area1 + area2 + area3);
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%lf %lf", &xx, &yy);
        points [i] = point (xx, yy);
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                cnt = 0;
                if (i == j || j == k || i == k) continue;
                for (int z = 0; z < n; z++) {
                    if (i == j || i == z || i == k || j == k || j == z || z == k) continue;
                    if (check (points [i], points [j], points [k], points [z])) cnt++;
                    maximum = max (cnt, maximum);
                }
            }
        }
    }
    printf ("%d\n", maximum + 3);
    return 0;
}
