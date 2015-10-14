#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

typedef unsigned long long int ull;

int dirX [8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dirY [8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }

    void print()
    {
        printf ("%d %d\n", x, y);
    }

    bool operator == (const point &B) const
    {
        return x == B.x && y == B.y;
    }
};

int get_number(const point &p)
{
    int number = (8 * p.x) + p.y;
}

point get_point(int number)
{
    return point(number / 8, number % 8);
}

bool board [10] [10];
point start, knight;
int n;

bool is_taken(int b, const point &p)
{
    return b & 1<<get_number (p);
}

int mark(int b, const point &p)
{
    return b | get_number (p);
}

void bfs()
{
    queue <pair <point, pair <ull, int> > > Q;

    Q.push (make_pair (start, make_pair (0, 0)));

    while (!Q.empty())
    {
        point help = Q.front().first;
        ull visited = Q.front().second.first;
        int cost = Q.front().second.second;

        for (int i = 0; i < 8; i++)
        {
            point current_point = point (help.x + dirX [i], help.y + dirY [i]);

            if (get_number (current_point) < 0 || get_number (current_point) > 63 || board [current_point.x] [current_point.y])
                continue;


        }
    }
}

int main ()
{
/*
    scanf ("%d", &n);
    start.get();

    for (int i = 0; i < n; i++)
    {
        knight.get();
        board [knight.x - 1] [knight.y - 1] = true;
    }
*/
    int cnt = 0;

    int k = ++cnt;

    cout<<k<<endl;


    return 0;
}










