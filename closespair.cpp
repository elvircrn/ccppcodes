#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double myAbs (int x) {
    return (x < 0 ? (x * (-1)) : x);
}

struct point {
    int x, y;

    point() {}
    point (int _x, int _y) {x = _x; y = _y;}

    double operator * (const point &A) const {
        point B = (*this);
        return sqrt (double (myAbs (A.x - B.x) * myAbs (A.x - B.x) + myAbs (A.y -  B.y) * myAbs (A.y - B.y)));
    }
};

bool SortByX (const point &A, const point &B) {
    return (A.x < B.x);
}

bool SortByY (const point &A, const point &B) {
    return (A.y < B.y);
}

int N;
double A, B;

vector <point> points;
vector <point> pointsX;
vector <point> pointsY;

double BruteFroce (int startingIndex, int endingIndex) {

    double ret = 1<<29;

    for (int i = startingIndex; i < endingIndex; i++)
        for (int j = i + 1; j <= endingIndex; j++)
            ret = min (ret, pointsX [i] * points [j]);

    return ret;
}

double solve (int startingIndex, int endingIndex) {

    int pivot = (endingIndex + startingIndex) / 2;



    point Median = pointsX [pivot];

    if (endingIndex - startingIndex + 1 < 5)
        return BruteFroce (startingIndex, endingIndex);

    double leftSolution = solve (startingIndex, pivot - 1);
    double rightSolution = solve (pivot + 1, endingIndex);

    double delta = min (leftSolution, rightSolution);

    double ret = 1<<25;

    for (int i = pivot; (i >= startingIndex) && Median.x - pointsX [i].x < delta; i--)
        for (int j = pivot + 1; (j <= endingIndex) && (j - pivot < 7); j++)
            ret = min (pointsX [i] * pointsX [j], ret);

    return ret;
}

int main () {

    /*scanf ("%d", &N);*/ N = 1000000;
    for (int i = 0; i < N; i++) {
        //scanf ("%lf %lf", &A, &B);
        A = i + 1; B = A;
        points.push_back (point (A, B));
        pointsX.push_back (point (A, B));
        pointsY.push_back (point (A, B));
    }

    sort (pointsX.begin(), pointsX.end(), SortByX);
    sort (pointsY.begin(), pointsY.end(), SortByY);

    double SOLUTION = solve (0, N - 1);

    printf ("%lf\n", SOLUTION);

    return 0;
}
