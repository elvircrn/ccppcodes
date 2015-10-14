#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define UP   -1
#define DOWN  1

#define INF 1<<27

int n, m;

char matrix [111] [111];
int values [111] [111], dp [111] [111] [2];

int solve (int x, int y, bool direction)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;

    if (dp [x] [y] [direction] != -1)
        return dp [x] [y] [direction];

    if (x == n - 1 && y == m - 1)
        return values [x] [y];

    int s1 = 0, s2 = 0;

    //continue in the same direction
    if (!direction)
        s1 = solve(x - 1, y, direction);
    else
        s1 = solve(x + 1, y, direction);

    //go right
    s2 = max (solve(x, y + 1, direction), solve (x, y + 1, !direction)) + values [x + 1] [y];

    return dp [x] [y] [direction] = max (s1, s2);
}

int main()
{
    memset (dp, -1, sizeof dp);

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &matrix [i]);
        for (int j = 0; j < m; j++)
        {
            if (isdigit (matrix [i] [j]))
                values [i] [j] = matrix [i] [j] - '0';
            else
                values [i] [j] = 0;
        }
    }


    printf ("%d\n", solve(n - 1, 0, false) + values [n - 1] [0]);

    return 0;
}
/*
2 2
99
88


5 10
..3.......
..........
..7.**....
.9**...1..
..8..9....

*/
