#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w) { n = _n; w = _w; }
};

struct for_queue
{
    edge E;
    int fuel;

    for_queue() { }
    for_queue(edge _E, int _fuel) { E = _E; fuel = _fuel; }

    bool operator<(const for_queue &B) const
    {
        return E.w > B.E.w;
    }

};

vector <edge> graph [200];
bool can_refill [200], visited [200];
int d [200], start = 1, end, e, v, l, n_pumps;

priority_queue <for_queue> Q;

int main()
{
    //freopen ("in.txt", "r", stdin);
    int a, b, c;
    scanf ("%d %d %d %d", &v, &n_pumps, &l, &e);
    for (int i = 0; i < e; i++)
    {
        scanf ("%d %d %d", &a, &b, &c);

        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }

    end = v;

    for (int i = 0; i < n_pumps; i++)
    {
        scanf ("%d", &a);
        can_refill [a] = true;
    }

    can_refill [1] = true;

    Q.push (for_queue (edge (start, 0), l));

    while (!Q.empty())
    {
        for_queue help = Q.top();
        int current_city = help.E.n;
        int prog_cost = help.E.w;
        int current_fuel = help.fuel;

        Q.pop();

        //printf ("out_while: %d\n", current_city);

        if (!visited [current_city])
        {
            //printf ("current_city: %d\n", current_city);
            visited [current_city] = true;
            if (can_refill [current_city])
            {
                current_fuel = l;
            }
            if (current_city == end)
            {
                printf ("%d\n", prog_cost);
                return 0;
            }

            d [current_city] = prog_cost;

            for (int i = 0; i < graph [current_city].size(); i++)
            {
                int next_city = graph [current_city] [i].n;
                int next_city_cost = graph [current_city] [i].w;
                if (!visited [next_city] && current_fuel >= next_city_cost)
                    Q.push (for_queue (edge (next_city, d [current_city] + next_city_cost), current_fuel - next_city_cost));
            }
        }
    }

    printf ("-1\n");

    return 0;
}






