#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define MALO 1e-5
#define PUNO 1e5

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
vector <double> cosines;

double getCosine (const Vector2 &A) {
    double distance = sqrt (double (A.x - reference.x) * double (A.x - reference.x) + double (A.y - reference.y) * double (A.y - reference.y));
    double k = A.y - reference.y;
    if (distance == 0) return PUNO;
    k = (k < 0) ? k * double (-1) : k;

    return double (double (k) / double (distance));
}

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &points [i].x, &points [i].y);

    for (int i = 0; i < n; i++) {

        cosines.clear();

        reference = points [i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cosines.push_back (getCosine (points [j]));
        }

        sort (cosines.begin(), cosines.end());

        #ifdef DEBUG
        cout<<"<------------>"<<endl;

        for (int j = 0; j < cosines.size(); j++) {
            cout<<cosines [j]<<endl;
        }
        #endif

        cnt = 1;

        for (int j = 1; j < cosines.size(); j++) {
            if (compare (cosines [j - 1], cosines [j]))
                cnt++;
            else {
                #ifdef DEBUG
                printf ("j: %d\n", j);
                #endif
                cnt = 1;
            }
            solution = max (solution, cnt);
        }

        #ifdef DEBUG
        printf ("cnt: %d\n", cnt);
        #endif
    }

    printf ("%d\n", solution + 1);

    return 0;
}

/*
5
1 1
1 2
1 3
1 4
4 1

3
1 1
2 2
3 3
*/
