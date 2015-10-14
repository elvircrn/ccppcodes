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

char matrix [200] [200];
int n, max_sol = 1, rijesenje, dp [200] [200], maximum;

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

point parent [200] [200], max_pos = point (0, 0);

int main ()
{
    scanf ("%d", &n); getchar();
    for (int i = 0; i < n - 1; i++)
        gets (matrix [i]);

    scanf ("%s", &matrix [n - 1]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            parent [i] [j] = point (i, j), dp [i] [j] = 1;

    bool promjena = true;

    while (promjena)
    {
        promjena = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int X = dirX [k] + i;
                    int Y = dirY [k] + j;


                    if (X < 0 || Y < 0 || X >= n || Y >= n || matrix [i] [j] <= matrix [X] [Y])
                        continue;

                    if (dp [i] [j] < dp [X] [Y] + 1)
                    {
                        promjena = true;
                        parent [i] [j] = point (X, Y);
                        dp [i] [j] = dp [X] [Y] + 1;
                    }

                    if (dp [i] [j] > max_sol)
                    {
                        max_sol = dp [i] [j];
                        max_pos = point (i, j);
                    }
                }
            }
        }
    }

    point current_point = max_pos;
    deque <char> solution;

    if (n == 1)
    {
        printf ("%c\n", matrix [0] [0]);
        return 0;
    }

    while (max_sol--)
    {
        solution.push_front (matrix [current_point.x] [current_point.y]);
        current_point = parent [current_point.x] [current_point.y];
    }

    for (int i = 0; i < solution.size(); i++)
        printf ("%c", solution [i]);
    printf ("\n");

    return 0;
}





