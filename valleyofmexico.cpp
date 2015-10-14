#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct edge
{
    int from, where;

    edge() { }
    edge(int _from, int _where) { from = _from; where = _where; }
};

int v, e;
vector <int> graph [1001];
vector <edge> edges;
vector <edge> candidates;

bool dfs (int checked, int current_node, int prev_node)
{
    if (checked == v)
        return true;


    for (int i = 0; i < graph [current_node].size(); i++)
    {

    }
}

int main()
{
    scanf ("%d %d", &v, &e);

    bool found(false);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);

        edges.push_back(edge (min (a, b), max (a, b)));

        if (abs (a - b) == 1)
            candidates.push_back (edge (a, b));

        graph [a].push_back (b);
        graph [b].push_back (a);

        if (abs (a - b) == 1)
            found = true;
    }

    if (!found || e < v - 1)
    {
        printf ("-1\n");
        return 0;
    }


    for (int i = 0; i < candidates.size(); i++)
    {
        if (dfs (2, candidates [i].from, candidates [i].where))
        {
            printf ("picka cuna kuuuurac\n");
        }
    }

    return 0;
}

























