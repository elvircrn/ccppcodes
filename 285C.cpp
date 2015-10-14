#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
    int u, v;

    edge() { }
    edge(int _u, int _v) { u = _u; v = _v; }
};

int e;
int degree[100000], s[100000], weights;
vector <edge> edges;

struct pq
{
    int vertex;

    pq() { }
    pq(int _vertex) { vertex = _vertex; }

    bool operator< (const pq &B) const
    {
        return weights [vertex] > weights [B.vertex];
    }
};

int main()
{
    scanf ("%d", &e);
    for (int i = 0; i < e; i++)
    {
        scanf ("%d %d", &degree[i], s[i]);
        weights[i] = degree[i];
    }

    while (!)


    return 0;
}




































