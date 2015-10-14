#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define BLOCK '#'
#define EMPTY '.'
#define START 'A'
#define STAR '*'
#define END 'B'
#define DIR 4

const int dirX [] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dirY [] = {0, 1, 0, -1, -1, 1, 1, -1};

class Point {
public:
    int x, y;

    Point () {}
    Point (int _x, int _y) {x = _x; y = _y;}
};

class Node: public Point {
public:
    int w, h;

    Point Parent;

    Node() {}
    Node (int _x, int _y) : Point (_x, _y){}
    Node (int _x, int _y, int _w, int _h) : Point (_x, _y) {
        w = _w;
        h = _h;
    }
    Node (int _x, int _y, int _w, int _h, Point A) : Point (_x, _y) {
        w = _w;
        h = _h;
        Parent = A;
    }

    bool operator < (const Node &B) const {
        return h > B.h;
    }

    bool operator == (const Node &B) const {
        return (((*this).x == B.x) && (*this).y == B.y);
    }

};

Node Start, End, Parent [100] [100];

int FieldHeight, FieldWidth, d [100] [100];
char Field[100] [100], C;

int myAbs (int X) {
    return (X > 0) ? X : (X * (-1));
}

int Distance (Node start, Node end) {
    return ((myAbs (start.x - end.x) + myAbs (start.y - end.y)));
}

int AStar() {

    priority_queue <Node> Q;
    bool visited [100] [100];

    Parent [Start.x] [Start.y] = Node (-1, -1, -1, -1, Point (-1, -1));

    Q.push (Start);

    while (!Q.empty()) {

        Node help = Q.top();
        Q.pop();

        if (visited [help.x] [help.y] == false) {

            visited [help.x] [help.y] = true;
            d [help.x] [help.y] = help.w;

            Parent [help.x] [help.y] = Node (help.Parent.x, help.Parent.y, 0, 0, Point (-1, -1));

            if (help == End)
                return d [help.x] [help.y];

            for (int i = 0; i < 4; i++) {

                int X = help.x + dirX [i];
                int Y = help.y + dirY [i];

                if (X < 0 || Y < 0 || X >= FieldHeight || Y >= FieldWidth || Field [X] [Y] == BLOCK || visited [X] [Y])
                    continue;

                Node ToPush = Node (X, Y, help.w + 1, Distance (Node (X, Y, 0, 0), End) + help.w, Point (help.x, help.y));
                Q.push (ToPush);
            }
        }

    };

    return -1;
}

void PrintMap (int H, int W) {
    for (int i = 0; i < H; i++, printf ("\n"))
        for (int j = 0; j < W; j++)
            putchar (Field [i] [j]);
}

int main () {

    scanf ("%d %d", &FieldHeight, &FieldWidth);
    for (int i = 0; i < FieldHeight; i++) {

        scanf ("%s", Field [i]);

        for (int j = 0; j < FieldWidth; j++) {

            if (Field [i] [j] == START)
                Start = Node (i, j, 0, 0, Point (-1, -1));

            else if (Field [i] [j] == END)
                End = Node (i, j, 0, 0);
        }
    }

    printf ("%d\n", AStar());

    Node current = End;

    while (current.x != -1) {
        Field [current.x] [current.y] = STAR;
        current = Parent [current.x] [current.y];
    }

    PrintMap(FieldHeight, FieldWidth);

    return 0;
}
/*
9 9
........A
......###
.........
...####..
.........
#####.#..
......#..
....###..
....B....
*/
