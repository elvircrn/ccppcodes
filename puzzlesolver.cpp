#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define EMPTY     '.'
#define BLOCK     '#'
#define STOP      'S'
#define DIE       'X'
#define CHARACTER 'O'
#define TOKEN     'T'
#define END       'E'
#define START     'B'

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

struct Point2
{
    int x, y;

    Point2() { }
    Point2(int _x, int _y) { x = _x; y = _y; }

    void print() const
    {
        printf ("%d %d\n", x, y);
    }
};

char matrix [1000] [1000];
int width, height;

Point2 start, end;

void display_matrix()
{
    for (int i = 1; i <= height; i++, printf ("\n"))
        for (int j = 1; j <= width; j++)
            putchar (matrix [i] [j]);
}

bool can_move_to(Point2 current_location, int direction)
{
    return !(matrix [current_location.x + dirX [direction]] [current_location.y + dirY [direction]] == BLOCK);
}

Point2 move_to(const Point2 current_location, int direction)
{
    Point2 location = current_location;
    while (matrix [location.x] [location.y] != BLOCK && matrix [location.x] [location.y] != STOP)
    {
        location.x += dirX [direction];
        location.y += dirY [direction];
    }

    if (matrix [location.x] [location.y] == BLOCK)
    {
        location.x -= dirX [direction];
        location.y -= dirY [direction];
    }

    return location;
}

void dfs (const Point2 current_location, int prev_direction)
{
    current_location.print();
    system ("pause");
    if (matrix [current_location.x] [current_location.y] == TOKEN)
    {
        printf ("HOORAY\n");
        system ("pause");
    }
    for (int i = 0; i < 4; i++)
    {
        if (prev_direction == i || !can_move_to (current_location, i))
            continue;
        dfs (move_to(current_location, i), i);
    }
}

int main ()
{
    //freopen ("in.txt", "r", stdin);

    memset (matrix, BLOCK, sizeof matrix);

    scanf ("%d %d", &height, &width); getchar();
    for (int i = 1; i <= height; i++, getchar())
        for (int j = 1; j <= width; j++)
        {
            scanf ("%c", &matrix [i] [j]);
            if (matrix [i] [j] == START)
                start = Point2(i, j);
            else if (matrix [i] [j] == END)
                end = Point2(i, j);
        }

    for (int i = 0; i < 4; i++)
        dfs (start, i);

    return 0;
}
