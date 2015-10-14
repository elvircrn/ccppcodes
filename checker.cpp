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

double BruteForce (int startingIndex, int endingIndex) {

    double ret = 1<<29;

    for (int i = startingIndex; i < endingIndex; i++)
        for (int j = i + 1; j <= endingIndex; j++)
            ret = min (ret, pointsX [i] * pointsX [j]);

    return ret;
}

int A, B, N, t = 10;

double solve (int startingIndex, int endingIndex) {

    int pivot = (endingIndex + startingIndex) / 2;

    if (endingIndex - startingIndex + 1 < 0 || endingIndex < 0 || startingIndex < 0)
        return 1<<29;

    if (endingIndex - startingIndex + 1 < 5)
        return BruteForce (startingIndex, endingIndex);

    point Median = pointsX [pivot];


    double leftSolution = solve (startingIndex, pivot - 1);
    double rightSolution = solve (pivot + 1, endingIndex);

    double delta = min (leftSolution, rightSolution);

    double ret = 1<<25;

    for (int i = pivot; (i >= startingIndex) && Median.x - pointsX [i].x < delta; i--)
        for (int j = pivot + 1; (j >= startingIndex) && (j <= endingIndex) && (pointsX [j].x - Median.x < delta); j++)
            if (i < 0 || j < 0)
                continue;
            else
                ret = min (pointsX [i] * pointsX [j], ret);

    return ret;
}

int main () {
    srand(time (0));

    N = 100000;
    t = 10;

    int RAND = 997;

    for (int i = 1; i <= 1; i++) {

        N = 1000;

        for (int j = 0; j < N; j++) {
            A = getRandomInt (RAND);
            B = getRandomInt (RAND);
            pointsX.push_back (point (A, B));
        }

        sort (pointsX.begin(), pointsX.end(), SortByX);

        double USER = solve (0, N - 1);
        double BF   = BruteForce (0, N - 1);
        //double BF = 0;

        while (pointsX.size()) pointsX.pop_back();

        printf ("<Test case %d, Number of points %d> Brute Force: %.5lf User Output: %.5lf\n", i, N, BF, USER);

    }

    return 0;
}
