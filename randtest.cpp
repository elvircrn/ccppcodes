#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

double myAbs (int x) {
    return (x < 0 ? (x * (-1)) : x);
}

int mA (int x) {
    return (x < 0 ? (x * (-1)) : x);
}

int getRandomInt (int bound) {
    return (int (rand()) % bound);
}

struct point {
    int x, y;

    point() {}
    point (int _x, int _y) {x = _x; y = _y;}

    double operator * (const point &A) const {
        point B = (*this);
        return sqrt (double ((A.x - B.x) * (A.x - B.x) + (A.y -  B.y) * (A.y - B.y)));
    }
};

vector <point> pointsX;

bool SortByX (const point &A, const point &B) {
    return (A.x < B.x);
}

bool SortByY (const point &A, const point &B) {
    return (A.y < B.y);
}

int main () {

    while (true)
        getRandomInt(997);

    return 0;
}
