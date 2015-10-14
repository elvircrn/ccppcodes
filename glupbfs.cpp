#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

string matrix[201];

int n, m, A;

string dir[4] = { "UP", "RIGHT", "DOWN", "LEFT" };
string opp[4] = { "DOWN", "LEFT", "UP", "RIGHT" };

bool valid(int x, int y)
{
    return !(x < 0 || y < 0 || x >= n || y >= m || (matrix [x] [y] != 'T' && matrix [x] [y] != 'C' && matrix [x] [y] != '.'));
}

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }

    void get()
    {
        cin>>x>>y;
    }

    bool operator == (const point &B) const
    {
        return (x == B.x && y == B.y);
    }

    bool operator != (const point &B) const
    {
        return (x != B.x || y != B.y);
    }
};

struct queue_element
{
    point p;

    int heuristic()
    {
        return 0;
    }
};

point current_location, start;
int visited[201] [201];
int next [201] [201];

bool check_path(const point &from, const point &where)
{
    queue <point> Q;
    memset(visited, -1, sizeof visited);

    visited [from.x] [from.y] = true;

    Q.push(start);
    while (!Q.empty())
    {
        point help = Q.front();
        Q.pop();

        if (help == where)
            return visited[where.x] [where.y];

        for (int i = 0; i < 4; i++)
        {
            int X = help.x + dirX [i], Y = help.y + dirY [i];
            if (valid(X, Y) && visited [X] [Y] == -1)
            {
                next [help.x] [help.y] = i;
                visited [X] [Y] = visited [help.x] [help.y] + 1;
                Q.push(point(X, Y));
            }
        }
    }

    return -1;
}

vector <string> cache;

int main()
{
    point end(-1, -1);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>A;
    cin.ignore();

    // game loop
    while (1)
    {
        current_location.get();

        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            cin >> matrix[i];
            cin.ignore();

            for (int j = 0; j < m; j++)
            {
                if (matrix [i] [j] == 'T')
                    start = point(i, j);
                else if (matrix [i] [j] == 'C')
                    end = point(i, j);
            }
        }

        int res;

        if (end.x != -1)
        {
            res = check_path(current_location, end);

            point eend = end, loc = current_location;

            if (res != -1)
            {
                while (eend != current_location)
                {

                }
            }
        }

        cout << "RIGHT" << endl;
    }

    return 0;
}








































