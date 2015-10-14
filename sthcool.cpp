#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

const int dirx [8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int diry [8] = {0, 1, 1, 1, 0, -1, -1, -1};

char field [100] [100];
int  n;
bool path [100] [100], visited [100] [100];

pair <int, int> start;
pair <int, int> end;

struct point {

    int x, y, w;

    point () {}
    point (int a, int b) {x = a; y = b;}
    point (int a, int b, int c) {x = a; y = b; w = c;}

    bool operator < (const point & xx) const {
        return w > xx.w;
    }

};

struct HOLD {

    point A, B;

    HOLD () {}
    HOLD (point AA, point BB) {A = AA; B = BB;}

    bool operator < (const HOLD & xx) const {
        return B < xx.B;
    }

};

point parent [100] [100];
priority_queue <HOLD> Q;
HOLD help;

int myAbs (int x) {
    return (x < 0) ? (x * -1) : x;
}

int menhetn (point N) {
    return N.x + myAbs (N.y - (n - 1));
    //return 1;
}

void find_path () {

    Q.push (HOLD (point (n - 1, 0), point (n - 1, 0, 0)));

    visited [n - 1] [0] = true;

    while (!Q.empty()) {

        help = Q.top();
        Q.pop();

        if (visited [help.B.x] [help.B.y] && help.B.x != n - 1 && help.B.y != 0) continue;

        parent [help.B.x] [help.B.y] = help.A;
        visited [help.B.x] [help.B.y] = true;

        //cout<<help.B.x<<" "<<help.B.y<<endl; system ("pause");

        if (help.B.x == 0 && help.B.y == n - 1) {cout<<help.B.w<<endl; return;}

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited [i] [j] && field [i] [j] != '#') {
                    putchar ('V');
                }
                else {
                    putchar (field [i] [j]);
                }
            }
            putchar ('\n');
        }

        system ("pause");
        system ("cls");*/

        for (int i = 0; i < 8; i++) {

            int X = dirx [i] + help.B.x, Y = diry [i] + help.B.y;

            if (X < 0 || Y < 0 || X >= n || Y >= n || visited [X] [Y] || field [X] [Y] == '#') continue;

            if (!visited [X] [Y])
                Q.push (HOLD (help.B, point (X, Y, help.B.w + menhetn (point (X, Y)) + 1)));

        }

    }

    return;

}

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s", &field [i]);

    find_path (); path [n - 1] [0] = true; parent [n - 1] [0] = point (n - 1, 0);

    int XX = 0, YY = n - 1;

    while ((XX != n - 1 || YY != 0)) {

        path [XX] [YY] = true;

        int a = XX;

        XX = parent [XX] [YY].x; YY = parent [a] [YY].y;

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (path [i] [j] == true)
                putchar ('E');
            else
                putchar (field [i] [j]);

        }
        putchar ('\n');

    }

    return 0;
}
/*

10
..........
..........
..........
.#######..
.......#..
.......#..
.......#..
.......##.
..........
..........

10
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........

*/
