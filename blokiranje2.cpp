#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

//#define DEBUG

/*
5 5
.....
#....
.....
.....
..#..
*/

int a_dirX [4] = { 0, 1, 0, -1 };
int a_dirY [4] = { -1, 0, 1, 0 };

int b_dirX [4] = { 0, -1, 0, 1 };
int b_dirY [4] = { 1, 0, -1, 0 };


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

    void print()
    {
        printf ("%d %d\n", x, y);
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

void solve()
{
    #ifdef DEBUG
    int debug [11] [11];
    memset (debug, 0, sizeof debug);
    #endif

    start = point (0, 0);
    finish = point (n - 1, m - 1);

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
        current = parent [current.x] [current.y];
        #ifdef DEBUG
        debug [current.x] [current.y]++;
        #endif
    }

    #ifdef DEBUG
    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            if (matrix [i] [j] == '.')
                printf ("%d", mark [i] [j]);
            else
                printf ("#");
    #endif

    memset (visited, false, sizeof visited);

    #ifdef DEBUG
    memset (mark, false, sizeof mark);
    printf ("\n<-------->\n\n");
    #endif

    start = point (n - 1, m - 1);
    finish = point (0, 0);

    while (!aQ.empty()) aQ.pop();

    aQ.push (start);
    while (!aQ.empty())
    {
        point help = aQ.top();
        aQ.pop();

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;

            if (help == finish)
                break;

            for (int i = 0; i < 4; i++)
            {
                int X = help.x + b_dirX [i];
                int Y = help.y + b_dirY [i];

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] || matrix [X] [Y] == '#')
                    continue;

                parent [X] [Y] = help;

                aQ.push (point (X, Y));
            }
        }
    }

    int cnt = 0;
    current = finish;
    while (current != start)
    {
        if (mark [current.x] [current.y])
            solution.push_back (point (current.x, current.y));
        mark [current.x] [current.y] = 1;
        #ifdef DEBUG
        debug [current.x] [current.y]++;
        #endif
        current = parent [current.x] [current.y];
    }

    #ifdef DEBUG
    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            if (matrix [i] [j] == '.')
                printf ("%d", mark [i] [j]);
            else
                printf ("#");

    printf ("\n<------->\n\n");

    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            printf ("%d", debug [i] [j]);
    #endif
}

int main ()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    solve();

    int START = 0;

    if (solution.size())
    {
        if (solution [0].x == 0 && solution [0].y == 0)
        {
            printf ("%d\n", solution.size() - 1);
            START = 1;
        }
        else
            printf ("%d\n", solution.size());
    }
    else
        printf ("0\n");
    for (int i = START; i < solution.size(); i++)
        printf ("%d %d\n", solution [i].x + 1, solution [i].y + 1);

    return 0;
}
/*
5 5
.....
#....
.....
.....
..#..

5 5
.#...
.#...
.#...
...#.
...#.

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

10 10
....###...
..#.......
#.....##.#
###.....#.
##........
.##...##..
.#.#.##..#
.###..#...
##..#.#..#
...#..#...


    FILE *in, *out;
    in = fopen ("test_case.txt", "r");
    out = fopen ("my_output.txt", "wt");
*/
