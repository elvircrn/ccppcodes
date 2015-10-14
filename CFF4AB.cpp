#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <utility>

using namespace std;

int n, m;

struct area
{
    int x, y, l;

    area() { }
    area(int _x, int _y, int _l) { x = _x; y = _y; l = _l; }

    void get()
    {
        scanf ("%d %d %d", &x, &y, &l);
    }
};

area horizontal [1001], vertical [1001];

int check(int one, int two)
{
    area ONE = vertical [one], TWO = horizontal [two];
    if (horizontal [two].x <= vertical [one].x && vertical [one].x <= horizontal [two].x + horizontal [two].l)
        return min (min (ONE.x - TWO.x, (TWO.x + TWO.l - ONE.x)), min (ONE.y + ONE.l - TWO.y, TWO.y - ONE.y));
    else
        return 0;
}

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        vertical [i].get();

    for (int i = 0; i < m; i++)
        horizontal [i].get();

    int solution(0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            solution = max (solution, check (i, j));
        }
    printf ("%d\n", solution);

    return 0;
}
