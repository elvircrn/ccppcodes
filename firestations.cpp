#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int dist [600] [600];

struct edge
{
    int from, where, w;

    edge() { }
    edge(int _where, int _w) { where = _where; w = _w; }
    edge(int _from, int _where, int _w) { from = _from; w = _where; w = _w; }

    bool operator < (const edge &B) const
    {
        return w > B.w;
    }

    void get()
    {
        scanf ("%d %d %d", &from, &where, &w);
    }

    void print()
    {
        printf ("%d %d %d\n", from, where, w);
    }
};

vector <edge> graph [600];
bool visited [1000], is_astation [1000];
int solution, maximum, e, f, t, firestations [200], vertices, kopija [600] [600];


void clear_case()
{
    memset (is_astation, false, sizeof is_astation);
    for (int i = 0; i < 550; i++)
        graph [i].clear();
    vertices = 0;
}

void dijkstra (int s);

int main ()
{

    memset (dist, 0, sizeof dist);

    t = 1;//scanf ("%d", &t);
    edge in = edge();

    while (t--)
    {
        scanf ("%d %d", &f, &e);
        for (int i = 0; i < f; i++)
        {
            scanf ("%d", &firestations [i]);
            is_astation [firestations [i]] = true;
        }
        vertices = e;
        while (scanf ("%d %d %d", &in.from, &in.where, &in.w) == 3)
        {
            if (in.from == 0 && in.where == 0 && in.w == 0)
                break;
            vertices = max (max (in.from, vertices), in.where);

            graph [in.from].push_back  (edge (in.where, in.w));
            graph [in.where].push_back (edge (in.from, in.w));

            dist [in.from] [in.where] = in.w;
            dist [in.where] [in.from] = in.w;
        }

        for (int ind = 0; ind < f; ind++)
        {
            priority_queue <edge> Q;
            int current_station = firestations [ind];

            memset (visited, false, sizeof visited);

            Q.push (edge (current_station, 0));

            while (!Q.empty())
            {
                edge help = Q.top();
                Q.pop();
                if (!visited [help.where])
                {
                    visited [help.where] = true;
                    dist [current_station] [help.where] = help.w;
                    dist [current_station] [help.where] = help.w;

                    for (int i = 0; i < graph [help.where].size(); i++)
                        if (!visited [graph [help.where] [i].where])
                            Q.push (edge (graph [help.where] [i].where, dist [current_station] [help.where] + graph [help.where] [i].w));
                }
            }
        }

        maximum = 0;

        for (int i = 0; i < f; i++)
            for (int j = 1; j <= vertices; j++)
            {
                maximum = max (dist [firestations [i]] [j], maximum);
            }

        for (int i = vertices; i >= 1; i--)
        {
            if (is_astation [i])
                continue;

            memcpy (kopija, dist, sizeof dist);

            printf ("%d\n", i);

            dijkstra (i);
        }

        printf ("%d\n", solution);

        clear_case();
    }

    return 0;
}

void dijkstra (int source)
{
    priority_queue <edge> Q;
    Q.push (edge (source, 0));
    memset (visited, false, sizeof visited);
    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        if (!visited [help.where])
        {
            visited [help.where] = true;
            kopija [source] [help.where] = help.w;

            for (int i = 0; i < graph [help.where].size(); i++)
                if (!visited [graph [help.where] [i].where])
                    Q.push (edge (graph [help.where] [i].where, kopija [source] [help.where] + help.w));
        }
    }

    int new_maximum = 0;

    for (int i = 1; i <= vertices; i++)
    {
        if (is_astation [i])
            continue;
        for (int j = 1; j <= vertices; j++)
        {
            /*if (is_astation [j])
                continue;*/

            new_maximum = max (new_maximum, kopija [i] [j]);
        }
    }

    if (maximum >= new_maximum)
    {
        cout<<"new_maximum: "<<new_maximum<<endl;
        solution = source;
    }
}




