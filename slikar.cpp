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

#define INF 1<<29
#define PRAZNO_POLJE 0
#define POZICIJA_MEDE 1
#define POZICIJA_KUCE 2
#define ROJ 3
#define DRVO 4

struct point {

    int x, y, w;

    point () {}
    point (int _x, int _y) {x = _x; y = _y;}
    point (int _x, int _y, int _w) {x = _x; y = _y; w = _w;}

    bool operator == (const point & xx) const {
        return (x == xx.x && y == xx.y);
    }

};

point start, end;
vector <point> roj;
bool visited [801] [801];
int dirx [5] = {-1, 0, 1, 0};
int diry [5] = {0, 1, 0, -1};
int matrix [801] [801], dist [801] [801], maxd, h, w, m;
char unos [801];
queue <point> Q;

void flood_fill () {

    point help;

    while (!Q.empty()) {

        help = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {

            int X = dirx [i] + help.x;
            int Y = diry [i] + help.y;

            if (X < 1 || Y < 1 || X > h || Y > w || (matrix [X] [Y] != 0 && matrix [X] [Y] != POZICIJA_MEDE) || dist [X] [Y] != -1) continue;

            dist [X] [Y] = dist [help.x] [help.y] + 1;

            maxd = max (dist [help.x] [help.y], maxd);

            Q.push (point (X, Y, help.w + 1));

        }

    }

    return;

}

bool TRY (int canGo) {

    queue <point> Q;
    Q.push (point (start.x, start.y, 1));
    point help;
    memset (visited, false, sizeof visited);
    visited [start.x] [start.y] = true;

    while (!Q.empty()) {

        help = Q.front();
        Q.pop();

        if (help == end)
            return true;

        for (int i = 0; i < 4; i++) {

            int X = dirx [i] + help.x;
            int Y = diry [i] + help.y;

            if (point (X, Y) == end) return true;

            if ((help.w / w + canGo >= dist [X] [Y]) || X < 1 || Y < 1 || X > h || Y > w || visited [X] [Y] || matrix [X] [Y] == ROJ || matrix [X] [Y] == DRVO || matrix [X] [Y] == ROJ) continue;

            visited [X] [Y] = true;
            Q.push (point (X, Y, help.w + 1));

        }

    }

    return false;

}

int main () {

    scanf ("%d %d", &h, &w); m = 1;

    for (int i = 0; i < h; i++) {

        scanf ("%s", &unos);

        for (int j = 0; j < w; j++) {

            if (unos [j] == 'S') {
                dist [i + 1] [j + 1] = -1;
                matrix [i + 1] [j + 1] = 1;
                start = point (i + 1, j + 1);
            }

            else if (unos [j] == 'D') {
                dist [i + 1] [j + 1] = INF;
                matrix [i + 1] [j + 1] = 2;
                end = point (i + 1, j + 1);
            }

            else if (unos [j] == '*') {
                roj.push_back (point (i + 1, j + 1));
                matrix [i + 1] [j + 1] = ROJ;
                dist [i + 1] [j + 1] = 0;
                Q.push (point (i + 1, j + 1, 0));
            }

            else if (unos [j] == 'X')
                matrix [i + 1] [j + 1] = DRVO;

            /*else
                dist [i + 1] [j + 1] = -1;*/

        }

    }

    flood_fill ();

    int SOLUTION = -1, leftb = 0, rightb = dist [start.x] [start.y] - 1, pivot;

    for (int i = 1; i <= 50; i++)
        if (TRY (i)) {
            printf ("%d\n", i);
            return 0;
        }

    /*while (leftb <= rightb) {

        pivot = (leftb + rightb) / 2;

        bool canWalkToHouse = TRY (pivot);

        if (not canWalkToHouse) {
            rightb = pivot - 1;
        }
        else {
            leftb = pivot + 1;
            SOLUTION = max (SOLUTION, pivot);
        }
    }

    if (SOLUTION != -1) printf ("%d\n", SOLUTION);
    else puts ("KAKTUS");*/

    return 0;

}
