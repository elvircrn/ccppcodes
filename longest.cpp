#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

#define MAX 1<<27

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };
deque <char> solution;

char matrix [200] [200];
int n, max_sol, rijesenje;


void dfs (char prev, int locationX, int locationY, int depth)
{
    if (depth > max_sol)
    {
        max_sol = depth;
    }
    for (int i = 0; i < 4; i++)
    {
        int X = locationX + dirX [i];
        int Y = locationY + dirY [i];

        if (X < 0 || Y < 0 || X >= n || Y >= n || prev >= matrix [X] [Y])
            continue;

        dfs (matrix [X] [Y], X, Y, depth + 1);
    }
}

bool printaj = false;

bool dfs2 (char prev, int locationX, int locationY, int depth)
{
    //printf ("%d\n", depth);
    if (depth == max_sol)
    {
        printaj = true;
    }
    if (printaj)
    {
        solution.push_front (matrix [locationX] [locationY]);
        return false;

    }
    for (int i = 0; i < 4; i++)
    {
        int X = locationX + dirX [i];
        int Y = locationY + dirY [i];

        if (X < 0 || Y < 0 || X >= n || Y >= n || prev >= matrix [X] [Y] || printaj)
            continue;

        dfs2 (matrix [X] [Y], X, Y, depth + 1);
    }

    if (printaj)
    {
        solution.push_front (matrix [locationX] [locationY]);
        return false;

    }

    return false;
}

int main ()
{

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dfs (matrix [i] [j], i, j, 1);

    //printf ("%d\n", max_sol);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (printaj)
                break;
            else
            {
                dfs2 (matrix [i] [j], i, j, 1);
                if (printaj)
                {
                    for (int i = 0; i < solution.size(); i++)
                        cout<<solution [i];
                    cout<<endl;
                }
            }

    return 0;
}

