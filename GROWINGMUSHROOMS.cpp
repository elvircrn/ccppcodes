#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define dif 1e-5

int n, t1, t2;
double k, a, b, maxH, drop, solution1, solution2;
vector <double> ranking;
vector <double> past;

bool visited [10000];

double myabs (double x) {
    if (x < 0) return x * (-1);
    else return x;
}

bool cmp (double x, double y) {
    if (myabs (x - y) < dif) return true;
    else return false;
}

int main () {
    scanf ("%d %d %d %lf", &n, &t1, &t2, &k);
    for (int i = 0; i < n; i++) {
        scanf ("%lf %lf", &a, &b);

        solution1 = (a * t1);
        solution1 = solution1 - (solution1 * double (k / 100));
        solution1 += (t2 * b);
        solution2 = (b * t1);
        solution2 = solution2 - (solution2 * double (k / 100));
        solution2 += (t2 * a);

        ranking.push_back (max (solution1, solution2));
        past.push_back (max (solution1, solution2));
    }
    sort (ranking.begin(), ranking.end());
    for (int i = 0; i < past.size(); i++) {
        for (int j = 0; j < ranking.size(); j++) {
            if (visited [j]) continue;
            if (cmp (past [j], ranking [past.size() - i - 1])) {visited [j] = true; printf ("%d %.2lf\n", j + 1, ranking [past.size() - i - 1]); break;}
        }
    }
    return 0;
}
