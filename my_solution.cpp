#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;
/*
int a_dirX [4] = { -1, 0, 1, 0 };
int a_dirY [4] = { 0, 1, 0, -1 };

int b_dirX [4] = { 1, 0, -1, 0 };
int b_dirY [4] = { 0, -1, 0, 1 };
*/
int a_dirX [4] = { 0, 1, 0, -1 };
int a_dirY [4] = { -1, 0, 1, 0 };

int b_dirX [4] = { -1, 0, 0, 1 };
int b_dirY [4] = { 0, -1, 1, 0 };


struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

char matrix [1010] [1010];
bool visited [1010] [1010];

int n, m;
bool mark [1010] [1010];

stack <point> aQ;
vector <point> solution;

point parent [1010] [1010];

void solve()
{
    bool nasao = false;

    aQ.push (point (0, 0));
    while (!aQ.empty())
    {
        point help = aQ.top();
        aQ.pop();

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;

            if (help.x == n - 1 && help.y == m - 1)
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

    point current = point (n - 1, m - 1);
    while (current.x || current.y)
    {
        mark [current.x] [current.y] = 1;
        current = parent [current.x] [current.y];
    }

    /*for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            printf ("%d", mark [i] [j]);*/

    memset (visited, false, sizeof visited);
    //memset (mark, 0, sizeof mark);

    while (!aQ.empty()) aQ.pop();

    aQ.push (point (0, 0));
    while (!aQ.empty())
    {
        point help = aQ.top();
        aQ.pop();

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;

            if (help.x == n - 1 && help.y == m - 1)
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

    current = point (n - 1, m - 1);
    while (current.x || current.y)
    {
        if (mark [current.x] [current.y] && (current.x != 0 || current.y != 0) && (current.x < n || current.y < m))
            solution.push_back (point (current.x, current.y));
        mark [current.x] [current.y] = 1;
        current = parent [current.x] [current.y];
    }

    /*printf ("\n");

    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            printf ("%d", mark [i] [j]);*/
}

int main ()
{
    freopen ("test_case.txtd", "r", stdin);
    freopen ("my_output.txt", "w", stdout);
    //input = fopen ("test_case.txt", "r");
    //out = fopen ("my_output.txt", "w");
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
5 5
.#...
.#...
.#...
...#.
...#.

5 5
.....
.....
.....
.....
.....
*/
