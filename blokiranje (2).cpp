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


int my_vector [1000000];
int top_index = -1;

int get_size()
{
    return top_index + 1;
}

int get_top()
{
    if (top_index > -1)
        return my_vector [top_index];
    else
        return -1;
}

void push(int number)
{
    top_index++;
    my_vector [top_index] = number;
}

void remove_top()
{
    if (top_index >= 0)
        top_index--;
}

int get_number (int x, int y)
{
    return x * 10000 + y;
}

int getX (int number)
{
    return number / 10000;
}

int getY (int number)
{
    return number % 10000;
}

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y)
    {
        x = _x;
        y = _y;
    }

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

    bool operator< (const point &B) const
    {
        if (x != B.x)
            return x < B.x;
        else
            return y < B.y;
    }
};

char matrix [1010] [1010];
bool visited [1010] [1010];
short debug [1010] [1010], n, m;
int parent [1010] [1010];
bool global;

point start, finish;

point dir [4];
point help;

bool dfs(int number)
{
    top_index = 0;
    my_vector [0] = 0;

    parent [n - 1] [m - 1] = get_number (-1, -1);
    parent [0] [0] = get_number (-2, -1);

    bool nasao = false;

    while (get_size() > 0)
    {
        int h = get_top();
        remove_top();

        help = point (getX(h), getY(h));

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
                int X = help.x + dir [i].x;
                int Y = help.y + dir [i].y;

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] || matrix [X] [Y] == '#')
                    continue;

                parent [X] [Y] = get_number (help.x, help.y);

                push (get_number (X, Y));
            }
        }
    }

    if (!nasao)
        return false;

    int current_number = get_number (n - 1, m - 1);

    while (current_number != 0)
    {
        debug [getX (current_number)] [getY (current_number)]++;
        current_number = parent [getX (current_number)] [getY (current_number)];
    }

    global = true;

    return true;
}

void solve()
{
    dir [0] = point (-1, 0);
    dir [1] = point (0, 1);
    dir [2] = point (1, 0);
    dir [3] = point (0, -1);

    sort (dir, dir + 4);

    int counter(0);
    int asd(0);
    while (next_permutation (dir, dir + 4))
    {
        if (counter < 15)
            break;
        counter++;
        memset (visited, false, sizeof visited);
        dfs (0);
    }

    if (!global)
    {
        int asd = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0 || i == n - 1 && j == m - 1)
                    continue;
                else if (matrix [i] [j] == '.')
                    asd++;
            }
        }

        printf ("%d\n", asd);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0 || i == n - 1 && j == m - 1)
                    continue;
                else if (matrix [i] [j] == '.')
                    point (i + 1, j + 1).print();
            }
        }
    }
    else
    {
        int SIZE(0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == 0 && j == 0 || i == n - 1 && j == m - 1)
                    continue;
                else if (debug [i] [j] == counter)
                    SIZE++;

        printf ("%d\n", SIZE);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == 0 && j == 0 || i == n - 1 && j == m - 1)
                    continue;
                else if (debug [i] [j] == counter)
                    printf ("%d %d\n", i + 1, j + 1);
        exit (0);
    }
}

int main ()
{
    freopen ("in.txt", "r", stdin);
    freopen ("outsol.txt", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    solve();

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
*/
