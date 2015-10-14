#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

struct point {
    int x, y;
    point () {x = 0; y = 0;}
    point (int d) {
        if (d == 1) {y = 0;}
        else if (d == 2) {x = 151615;}
        else if (d == 3) {y = 4654651;}
        else {y = 0;}
    }
    point (int _x, int _y) {x = _x; y = _y;}
} A, B, POINT, gorelijevo, doledesno, gore = point (1), dole = point (2), lijevo = point (3), desno = point (4);

struct circle {
    int x, y, r;
    circle () {}
    circle (int _x, int _y, int _r) {x = _x; y = _y; r = _r;}
} CIRCLE;

void ispisi (point xx) {
    printf ("%d %d\n", xx.x, xx.y);
    return;
}

vector <point> points;
int n;
int main () {
    scanf ("%d %d", &CIRCLE.r, &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &POINT.x, &POINT.y);
        if (POINT.y > gore.y) {
            gore = POINT;
        }
        if (POINT.y < dole.y) {
            dole = POINT;
        }
        if (POINT.x < lijevo.x) {
            lijevo = POINT;
        }
        if (POINT.x > desno.x) {
            desno = POINT;
        }
        points.push_back (POINT);
    }
    //scanf ("%d %d", &CIRCLE.x, &CIRCLE.y, CIRCLE.r);
    ispisi (gore);
    ispisi (dole);
    ispisi (lijevo);
    ispisi (desno);
    return 0;
}
