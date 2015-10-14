#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define MALO 0.0000001
#define PUNO 1100000.00

//#define DEBUG

int N;

double myAps (double X) {
    return (X < 0) ? X * double (-1) : X;
}

bool compare (double A, double B) {
    return (myAps (A - B) < MALO);
}

class Vector2 {
public:
    int x, y;

    Vector2 () {}
    Vector2 (int _x, int _y) {x = _x; y = _y;}
};

int n, solution, cnt;
Vector2 reference, points [1000];
vector <double> coeffs;

double getCoeff (const Vector2 &A) {
    Vector2 B = reference;
    if (compare (B.x, A.x)) return PUNO;
    if (compare (B.y, A.y)) return PUNO + 5;
    double k = (double (B.y - A.y) / double (B.x - A.x));
    return k;
}

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &points [i].x, &points [i].y);

    for (int i = 0; i < n; i++) {

        coeffs.clear();

        reference = points [i];
        for (int j = 0; j < n; j++)
            if (i != j)
                coeffs.push_back (getCoeff (points [j]));

        sort (coeffs.begin(), coeffs.end());

        cnt = 1;

        for (int j = 1; j < coeffs.size(); j++) {
            solution = max (solution, cnt);
            if (compare (coeffs [j - 1], coeffs [j]))
                cnt++;
            else
                cnt = 1;
            solution = max (solution, cnt);
        }

    }

    printf ("%d\n", solution + 1);

    return 0;
}
/*
2
1 1
2 2

5
1 1
2 2
3 3
9 10
10 11
*/
