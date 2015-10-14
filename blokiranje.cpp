#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int dirX [8] = { -1, 0, 1, 0, 1, -1, 1, -1 };
int dirY [8] = { 0, 1, 0, -1, 1, -1, -1, 1 };

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

vector <point> solution;

char matrix [1010] [1010];
int n, m;
point parent [1010] [1010];
bool visited [1010] [1010];
queue <point> Q;

bool find ()
{
    if (matrix [0] [0] == '#' || matrix [n - 1] [m - 1] == '#') return true;

    while (!Q.empty()) Q.pop();
    memset (visited, false, sizeof visited);

    Q.push (point (0, 0));

    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        if (help.x == n - 1 && help.y == m - 1) return true;

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;
            for (int i = 0; i < 4; i++)
            {
                int X = dirX [i] + help.x;
                int Y = dirY [i] + help.y;

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] || matrix [X] [Y] == '#') continue;

                Q.push (point (X, Y));
            }
        }
    }

    return false;
}

bool find_path()
{
    Q.push (point (0, 0));

    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        //printf ("%d %d\n", help.x, help.y);

        if (!visited [help.x] [help.y])
        {
            visited [help.x] [help.y] = true;
            for (int i = 0; i < 4; i++)
            {
                int X = dirX [i] + help.x;
                int Y = dirY [i] + help.y;

                if (X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] || matrix [X] [Y] == '#')
                    continue;

                parent [X] [Y] = point (help.x, help.y);

                Q.push (point (X, Y));
            }
        }
    }

    point current = point (n - 1, m - 1);

    while (current.x || current.y)
    {
        matrix [current.x] [current.y] = '#';

        if (!find())
            solution.push_back (point (current.x + 1, current.y + 1));

        matrix [current.x] [current.y] = '.';

        current = parent [current.x] [current.y];
    }

    return true;
}

int main ()
{

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    find_path();

    printf ("%d\n", solution.size());
    for (int i = 0; i < solution.size(); i++)
        printf ("%d %d\n", solution [i].x, solution [i].y);


    return 0;
}
