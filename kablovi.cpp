#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class point
{
public:
    float x, y;

    point () {}
    point (float _x, float _y) { x = _x; y = _y; }
};

float distance (float Ax, float Ay, float Bx, float By)
{
    return float (sqrt ((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)));
}

int n;
vector <point> points;

struct for_queue
{
    int index;
    float progress;

    for_queue () { }
    for_queue (int _index, float _progress) { index = _index; progress = _progress; }

    bool operator < (const for_queue &x) const
    {
        return progress < x.progress;
    }
};

priority_queue <for_queue> Q;
float solution, a, b;
bool visited [200];

int main ()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        points.push_back (point (a, b));
        cout<<points [i].x<<" "<<points [i].y<<endl;
    }

    Q.push (for_queue (0, 0.0f));
    while (!Q.empty())
    {
        for_queue help = Q.top();
        Q.pop();
        if (!visited [help.index])
        {
            visited [help.index] = true;

            for (int i = 0; i < n; i++)
            {
                if (!visited [i])
                {
                    Q.push (for_queue (i, distance
                                       (points [help.index].x, points [help.index].y, points [i].x, points [i].y)));
                    solution += distance (points [help.index].x, points [help.index].y, points [i].x, points [i].y);
                }
            }
        }
    }

    cout<<solution<<endl;

    return 0;
}
/*
3
1 1
2 2
3 3
*/














