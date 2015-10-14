#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int n, m;
char matrix [100] [100];
bool visited [100] [100];

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }

    void print()
    {
        printf ("%d %d\n", x, y);
    }
};

vector <point> solution;

bool check (int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || matrix [x] [y] == '#')
        return false;
    else
        return true;
}

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

bool find()
{
    if (matrix [0] [0] == '#')
        return true;

    queue <point> Q;
    memset (visited, false, sizeof visited);

    Q.push (point (0, 0));

    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        visited [help.x] [help.y] = true;

        if (help.x == n - 1 && help.y == m - 1)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int X = help.x + dirX [i];
            int Y = help.y + dirY [i];

            if (check (X, Y) && !visited [X] [Y])
                Q.push (point (X, Y));
        }
    }

    return false;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("outbrute.txt", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == m - 1)
                break;
            if (matrix [i] [j] == '.')
            {
                matrix [i] [j] = '#';
                if (!find())
                    solution.push_back (point (i + 1, j + 1));
                matrix [i] [j] = '.';
            }
        }
    }

    printf ("%d\n", solution.size());
    for (int i = 0; i < solution.size(); i++)
        solution [i].print();

    return 0;
}
