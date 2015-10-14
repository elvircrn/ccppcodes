#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int t, n, r;

struct city
{
    int x, y;

    city() { }
    city(int _x, int _y) { x = _x; y = _y; }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }
};

int region_counter;
city cities [1010];

struct edge
{
    int from, where;
    float weight;

    edge() { }
    edge(int a, int b)
    {
        from  = a;
        where = b;
    }
    edge(int a, int b, float _weight)
    {
        from  = a;
        where = b;
        weight = _weight;
    }

    int w() const
    {
        #define n cities [from]
        #define m cities [where]

        return (n.x - m.x) * (n.x - m.x) + (n.y - m.y) * (n.y - m.y);

        #undef n
        #undef m
    }

    float sqrw() const
    {
        return (float)sqrt ((float)w());
    }

    bool different_state() const
    {
        return (w() <= r);
    }

    bool operator< (const edge &B) const
    {
        return weight > B.weight;
    }
};

float d [1010];
bool visited [1010];
priority_queue <edge> Q;

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &t);
    while (t--)
    {
        region_counter = 0;

        scanf ("%d %d", &n, &r);
        for (int i = 0; i < n; i++)
        {
            cities [i].get();
            d [i] = 0;
            visited [i] = false;
        }

        Q.push (edge (0, 0));

        while (!Q.empty())
        {
            edge help = Q.top();
            Q.pop();

            if (!visited [help.where])
            {
                d [help.where] = help.
                visited [help.where] = true;
            }
        }
    }

    return 0;
}






