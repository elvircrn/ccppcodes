#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cctype>
#include <deque>

using namespace std;

int dirx [10] = {-1, 0, 1, 0};
int diry [10] = {0, 1, 0, -1};

class point {
    public:
    int x, y;
};

class pointQ : public point {

    public:

    int progress;

    pointQ () {progress = 0;}
    pointQ (int _x, int _y) {x = _x; y = _y; progress = 0;}
    pointQ (int _x, int _y, int _p) {x = _x; y = _y; progress = _p;}

};

char zidine [35] [35];
int n, m, k, paths [35] [35], key_count;
pointQ START;
bool cango [100], visited [100] [35] [35];
int COUNTER;

deque <pointQ> keys;

int bfs (int i1, int i2) {

    pointQ start = keys [i1], end = keys [i2], help;

    queue <pointQ> Q;
    while (Q.size()) Q.pop();

    Q.push (start);
    visited [COUNTER] [start.x] [start.y] = true;

    while (!Q.empty()) {

        help = Q.front ();
        if (help.x == end.x && help.y == end.y) break;
        Q.pop();

        for (int i = 0; i < 4; i++) {

            int X = dirx [i] + help.x, Y = diry [i] + help.y;
            if (visited [COUNTER] [X] [Y] || zidine [X] [Y] == '#')
                continue;
            visited [COUNTER] [X] [Y] = true;
            Q.push (pointQ (X, Y, help.progress + 1));

        }

    }

    COUNTER++;

    return help.progress;

}

int SOLUTION = 1<<28;

void dfs (int count, int pastind, int progress, bool go[100]) {

    if (count == k) {SOLUTION = min (SOLUTION, progress); return;}

    for (int i = 0; i < keys.size(); i++) {

        if (go [i]) continue;
        go [i] = true;
        dfs (count + 1, i, progress + paths [pastind] [i], go);
        go [i] = false;

    }

    return;

}

int main () {

    scanf ("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {

        scanf ("%s", &zidine [i]);

        for (int j = 0; j < strlen (zidine [i]); j++)
            if (zidine [i] [j]== 'X')
                keys.push_front (START = pointQ (i, j));
            else if (zidine [i] [j] == 'K')
                keys.push_back (pointQ (i, j));

    }

    for (int i = 0; i < keys.size() - 1; i++) {
        for (int j = i + 1; j < keys.size(); j++) {
            int b = bfs (i, j);
            paths [i] [j] = paths [j] [i] = b;
        }
    }

    cango [0] = true;
    dfs (0, 0, 0, cango);

    printf ("%d\n", SOLUTION);

    return 0;

}
