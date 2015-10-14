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

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }
};

int arrayX [1000100], arrayY [1000100], SUMX [1000100], SUMY [1000100], n, q, INDEX;
point triangle [1000100] [6];

char A [2], B [2];

int main ()
{

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int leftX = 2000000, rightX = 0, leftY = 2000000, rightY = 0;

        for (int j = 0; j < 3; j++)
        {
            triangle [i] [j] = point();

            triangle [i] [j].get();

            leftX = min (triangle [i] [j].x, leftX);
            rightX = max (triangle [i] [j].x, rightX);

            leftY = min (triangle [i] [j].y, leftY);
            rightY = max (triangle [i] [j].y, rightY);
        }

        if (rightX - leftX >= 2)
        {
            arrayX [leftX + 1]++;
            arrayX [rightX]--;
        }

        if (rightY - leftY >= 2)
        {
            arrayY [leftY + 1]++;
            arrayY [rightY]--;
        }
    }

    scanf ("%d", &q);

    SUMX [0] = arrayX [0];
    SUMY [0] = arrayY [0];

    for (int i = 1; i <= 1000000; i++)
    {
        SUMX [i] = SUMX [i - 1] + arrayX [i];
        SUMY [i] = SUMY [i - 1] + arrayY [i];
    }

    while (q--)
    {
        scanf ("%s %s %d", &A, &B, &INDEX);

        int sum = 0;

        if (A [0] == 'x')
            printf ("%d\n", SUMX [INDEX]);
        else
            printf ("%d\n", SUMY [INDEX]);
    }

    return 0;
}
