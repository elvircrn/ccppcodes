#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define DFS_WHITE 0
#define DFS_GREY  1
#define DFS_BLACK 2

#define MAX_STUDENTS 510

#define INF 1<<27

int color [MAX_STUDENTS];

struct edge
{
    int u, v, w;

    edge() { }
    edge(int _u, int _v, int _w) { u = _u; v = _v; w = _w; }

    bool operator< (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> edges;

bool visited [MAX_STUDENTS];
int dist [MAX_STUDENTS], value [MAX_STUDENTS], less_than [MAX_STUDENTS], students, connections;

int main()
{
    while (scanf ("%d %d", &students, &connections) == 2)
    {
        for (int i = 0; i < MAX_STUDENTS; i++)
            dist [i] = INF;

        edges.clear();

        for (int i = 0; i < connections; i++)
        {
            int u, v, w;
            scanf ("%d %d %d", &u, &v, &w);
            u++;
            v++;
            edges.push_back (edge (u, v, -w));
        }


        bool answer  = true;
        bool changed = true;

        for (int i = 0; i <= students; i++)
        {
            changed = false;
            for (edge e : edges)
            {
                if (dist [e.u] + e.w < dist [e.v])
                {
                    changed = true;
                    dist [e.v] = dist [e.u] + e.w;
                }
            }
        }

        for (edge e: edges)
            if (dist [e.v] > dist [e.u] + e.w)
                answer = false;

        if (answer)
            printf ("y\n");
        else
            printf ("n\n");
    }


    return 0;
}



/*
0 <= -(C1 + C2 + C3 + C4)

0 <= (-C1) + (-C2) + (-C3) + (-C4)
*/








































