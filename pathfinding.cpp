#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

char matrix [100] [100];
int n, m;
point start;

int main ()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &matrix [i]);
        for (int j = 0; j < m; j++)
            if (matrix [i] [j] == 'S')
                start = point (i, j);
    }


    return 0;
}










