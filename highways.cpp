#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int a, b, c, n, m, start, end;

struct edge
{
    int n, w;

    edge () { }
    edge (int _n, int _w) { n = _n; w = _w; }

    bool operator < (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> graph [10000];
bool visited [100100];
int dist [10100];
priority_queue <edge> Q;

int main ()
{
    scanf ("%d %d %d %d", &n, &m, &start, &end);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }

    Q.push (edge (start, 0));

    return 0;
}
