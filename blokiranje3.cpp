#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

#define DEBUG
/*
int a_dirX [4] = { -1, 0, 1, 0 };
int a_dirY [4] = { 0, 1, 0, -1 };

int b_dirX [4] = { 1, 0, -1, 0 };
int b_dirY [4] = { 0, -1, 0, 1 };
*/


struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    bool operator == (point &B)
    {
        return (x == B.x && y == B.y);
    }

    bool operator != (point &B)
    {
        return !((*this) == B);
    }
};

char matrix [1010] [1010];
bool visited [1010] [1010];

int n, m;
bool mark [1010] [1010], nasao = false;

stack <point> aQ;
vector <point> solution;

point parent [1010] [1010];

point start, finish;

int a_dirX [4] = { 0, 1, 0, -1 };
int a_dirY [4] = { 1, 0, -1, 0 };

int b_dirX [4] = { 0, 1, 0, 1 };
int b_dirY [4] = { -1, 0, 1, 0 };

void solve()
{
    start = point (n - 1, m - 1);
    finish = point (0, 0);

    int debug [10] [10];
    memset (debug, 0, sizeof debug);

    bool nasao = false;

    aQ.push (start);
    while (!aQ.empty())
    {
        point help = aQ.top();
        aQ.pop();

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;

            if (help == finish)
            {
                nasao = true;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int X = help.x + a_dirX [i];
                int Y = help.y + a_dirY [i];

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] || matrix [X] [Y] == '#')
                    continue;

                parent [X] [Y] = help;

                aQ.push (point (X, Y));
            }
        }
    }

    if (nasao == false)
    {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (i == n - 1 && j == m - 1)
                    continue;
                else if (matrix [i] [j] == '#')
                    continue;
                else
                    solution.push_back (point (i, j));
            }
        return;
    }

    point current = finish;
    while (current != start)
    {
        mark [current.x] [current.y] = 1;
        debug [current.x] [current.y]++;
        current = parent [current.x] [current.y];
    }

    #ifdef DEBUG
    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            if (matrix [i] [j] == '.')
                printf ("%d", mark [i] [j]);
            else
                printf ("#");
    #endif
}

int main ()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    solve();

    if (solution.size()) printf ("%d\n", solution.size() - 1);
    else printf ("0\n");
    for (int i = 1; i < solution.size(); i++)
        printf ("%d %d\n", solution [i].x + 1, solution [i].y + 1);

    //system ("pause");

    return 0;
}
/*
10 10
.#..#.....
..#.#..#..
#.......##
.#.....#..
...##.###.
...#..##..
..#....#..
.##......#
##..###...
####......
*/
