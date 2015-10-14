#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int dX [4] = { -1, 0, 1, 0 };
int dY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    bool operator == (const point &B) const
    {
        return ((x == B.x) && (y == B.y));
    }

    void Print()
    {
        printf ("%d %d\n", x, y);
    }
};

char line [500];
bool flood_visited [500] [500];
bool taken [500] [500];
int w, h, flood_parent [500] [500];

int current_max, total_max, cycle_counter, global_counter = 0;

void dfs (point current_location)
{
    global_counter++;
    flood_visited [current_location.x] [current_location.y] = true;
    for (int i = 0; i < 4; i++)
    {
        int X = current_location.x + dX [i];
        int Y = current_location.y + dY [i];

        if (X > 0 && Y > 0 && X <= 3 * h && Y <= 3 * w && !flood_visited [X] [Y])
        {
            dfs (point (X, Y));
        }
    }
}

void construct_boundaries ()
{
    for (int i = 1; i <= 3 * w; i++)
    {
        if (!flood_visited [1] [i])
        {
            dfs (point (1, i));
        }
        if (!flood_visited [3 * h] [i])
        {
            dfs (point (3 * h, i));
        }
    }

    for (int i = 1; i <= 3 * h; i++)
    {
        if (!flood_visited [i] [1])
        {
            dfs (point (i, 1));
        }
        if (!flood_visited [i] [3 * w])
        {
            dfs (point (i, 3 * w));
        }
    }
}

void clear_case()
{
    memset (flood_visited, false, sizeof flood_visited);
    memset (flood_parent, 0, sizeof flood_parent);
    memset (taken, false, sizeof taken);
}

int main ()
{
    int t = 0;
    scanf ("%d %d", &w, &h);
    while (h || w)
    {
        for (int i = 1; i <= h; i++)
        {
            scanf ("%s", &line);
            for (int j = 1; j <= w; j++)
            {
                if (line [j - 1] == '/')
                {
                    taken [i * 3 - 2] [j * 3] = true;
                    taken [i * 3 - 1] [j * 3 - 1] = true;
                    taken [i * 3] [j * 3 - 2]= true;
                    flood_visited [i * 3 - 2] [j * 3] = true;
                    flood_visited [i * 3 - 1] [j * 3 - 1] = true;
                    flood_visited [i * 3] [j * 3 - 2]= true;
                }
                else
                {
                    taken [i * 3 - 2] [j * 3 - 2] = true;
                    taken [i * 3 - 1] [j * 3 - 1] = true;
                    taken [i * 3] [j * 3] = true;
                    flood_visited [i * 3 - 2] [j * 3 - 2] = true;
                    flood_visited [i * 3 - 1] [j * 3 - 1] = true;
                    flood_visited [i * 3] [j * 3] = true;
                }
            }
        }

        construct_boundaries();

        int counter = 0, solution = 0;

        for (int i = 1; i <= 3 * h; i++)
        {
            for (int j = 1; j <= 3 * w; j++)
            {
                if (!flood_visited [i] [j])
                {
                    global_counter = 0;
                    dfs (point (i, j));
                    counter++;
                    solution = max (solution, global_counter);
                }
            }
        }

        printf ("Maze #%d:\n", ++t);

        if (counter)
        {
            printf("%d Cycles; the longest has length %d.\n", counter, solution / 3);
        }
        else
        {
            printf("There are no cycles.\n");
        }

        printf ("\n");

        clear_case();

        scanf ("%d %d", &w, &h);
    }

    return 0;
}
/*
6 4
\//\\/
\///\/
//\\/\
\/\///

2 2
/\
\/

*/
