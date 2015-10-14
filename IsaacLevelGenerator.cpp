#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algortithm>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>

using namespace std;

#define fiedlHeight 10
#define fieldWidth 10

int getRandomInt (int bound) {
    return (int (rand()) % bound + 1);
}

int dirx[5] = {-1, 0, 1, 0};
int diry[5] = {0, 1, 0, -1};

int matrix [50] [50];

struct point {
    int x, y, cnt;

    point () {}
    point (int _x, int _y) {x = _x; y = _y;}
    point (int _x, int _y, int c) {x = _x; y = _y; cnt = c;}
};

bool canPlaceField (point Point) {

    int count = 0;

    for (int i = 0; i < 4; i++) {

        int X = Point.x + dirx [i];
        int Y = Point.y + diry [i];

        if (matrix [i] [j])
            count++;
    }

    if (count > 1)
        return false;
    else
        return true;

}

point parent [50] [50];
queue <point> Q;
int currentFeidls;

int main () {

    Q.push (point (5, 5, 7));
    currentFields = 7;

    while (!Q.empty()) {

        point help = Q.top();
        Q.pop();
        if (currentFields < 1) continue;
        matrix [help.x] [help.y] = 1;
        currentFields--;

        for (int i = 0; (i < 4) && currentFields; i++) {
            int X = dirx [i] + help.x;
            int Y = diry [i] + help.y;

            if (X < 1 || Y < 1 || X > fieldHeight || > fieldWidth || !canPlaceField (point (X, Y)))
                continue;

            if (currentFields > 1)
                Q.push (point (X, Y, currentFields - getRandomInt ));

        }
    }

    return 0;
}
