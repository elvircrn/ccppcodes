#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

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

point points [5], points1 [5];
int minX = 3000, minY = 3000, maxX, maxY;
bool gorelijevo, goredesno, dolelijevo, doledesno;

int main ()
{

    for (int i = 0; i < 3; i++)
    {
        points [i] = point();
        points [i].get();

        minX = min (minX, points [i].x);
        minY = min (minY, points [i].y);

        maxX = max (maxX, points [i].x);
        maxY = max (maxY, points [i].y);
    }

    for (int i = 0; i < 3; i++)
    {
        //gore lijevo
        if (points [i].x == minX && points [i].y == maxY)
            gorelijevo = true;
        //gore desno
        if (points [i].x == maxX && points [i].y == maxY)
            goredesno = true;
        //dole lijevo
        if (points [i].x == minX && points [i].y == minY)
            dolelijevo = true;
        //dole desno
        if (points [i].x == maxX && points [i].y == minY)
            doledesno = true;
    }

    if (!gorelijevo)
        printf ("%d %d\n", minX, maxY);
    else if (!goredesno)
        printf ("%d %d\n", maxX, maxY);
    else if (!dolelijevo)
        printf ("%d %d\n", minX, minY);
    else
        printf ("%d %d\n", maxX, minY);

    return 0;
}
/*
    186
   + 83
*/
