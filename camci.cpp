#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Boat
{
    int position, size;

    Boat () { }
    Boat (int _size, int _position) { position = _position; size = _size; }

    bool operator < (const Boat &xx) const
    {
        return max (position, size) < max (xx.position, xx.size);
        //return position < xx.position;
    }
};

int n, far_right, solution = 1;
Boat boats [10001];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &boats [i].size, &boats [i].position);

    sort (boats, boats + n);

    far_right = boats [0].position;

    for (int i = 1; i < n; i++)
    {
        if (far_right <= boats [i].position)
        {
            far_right = max (far_right + boats [i].size, boats [i].position);
            solution++;
        }
        else
        {
            far_right = min (far_right, )
        }
    }

    printf ("%d\n", solution);

    return 0;
}
/*
7
5 9
2 17
6 10
3 11
2 16
4 13
5 6
*/
