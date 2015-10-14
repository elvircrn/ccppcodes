#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct element {
    int realpos, val;
    element () {}
    element (int _r, int _v) {realpos = _r; val = _v;}
    bool operator < (const element & xx) const
    {
        return realpos < xx.realpos;
    }
};
struct drugi {
    int val, pos;
    drugi () {}
    drugi (int _v, int _p) {val = _v; pos = _p;}
    bool operator < (const drugi & xx) const
    {
        return val < xx.val;
    }
};
element elements [50001];
drugi array [50001];
int a, n;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        array [i] = drugi (a, i);
    }
    sort (array, array + n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
    }
    for (int i = 0; i < n; i++)
        printf ("%d ", array [i].pos);
}
