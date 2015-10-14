#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
double euclideandistance (int x1, int y1, int x2, int y2) {
    return sqrt (double ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
struct point {
    int x, y;
    point () {}
    point (int _x, int _y) {x = _x; y = _y;}
    bool operator < (const point & xx) const
    {
        return x < xx.x;
    }
} points [1001];
int bs (int i, int j, int dist) {
    int x1 = points [i].x + dist, y1 = points [i].y, x2 = points [i].x, y2 = points [i].y + dist;
    int leftb = 0, rightb = n;
    while (leftb <= rightb) {
        int pivot = (leftb + rightb) / 2;
        if (x1 == )
    }
    return 0;
}
int solve (int i, int j) {
    double aa = euclideandistance (points [i].x, points [i].y, points [j].x, points [j].y);
    if (int (aa) - aa != 0) return 0;
    else return bs (i, j, int (aa));
}
int n, a, b, cnt;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        points [i] = point (a, b);
    }
    sort (points, points + n);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            cnt += solve (i, j);
    printf ("%d\n", cnt);
    return 0;
}
