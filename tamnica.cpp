#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int getSize (int width)
{
    if (width == 1)
        return 1;
    else
        return (2 * width) + 2 * (width - 2);
}

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    void print()
    {
        printf ("%d %d\n", x, y);
    }

    point operator + (const point &B) const
    {
        return point (x + B.x, y + B.y);
    }
};

int dirX [4] = { 0, -1, 0, 1 };
int dirY [4] = { -1, 0, 1, 0 };

struct field
{
    static int matrix [200] [200];
    static int matrix_size;

    static void Kreate (int number)
    {
        int last = 0, direction = 0;

        for (int i = 1; i <= 100; i += 2)
        {
            last += getSize (i);
            if (last >= number)
            {
                matrix_size = i;
                break;
            }
        }

        point current = point (matrix_size, matrix_size + 1);

        while (last)
        {
            point help = current;

            help.x = current.x + dirX [dir]
        }
    }
};

int main ()
{

    return 0;
}



