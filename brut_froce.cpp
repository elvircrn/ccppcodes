#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }
};

char matrix [1010] [1010];
int n, m;
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

vector <point> solution;

int main ()
{
    FILE *in, *out;
    in = fopen ("test_case.txt", "r");
    out = fopen ("brut_output.txt", "wt");

    fscanf (in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf (in, "%s", &matrix [i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix [i] [j] == '.')
            {
                matrix [i] [j] = '#';
                if (!find()) solution.push_back (point (i, j));
                matrix [i] [j] = '.';
            }
        }
    }

    fprintf (out, "%d\n", solution.size());
    for (int i = 0; i < solution.size(); i++)
        fprintf (out, "%d %d\n", solution [i].x + 1, solution [i].y + 1);

    fclose (in);
    fclose (out);

    return 0;
}
