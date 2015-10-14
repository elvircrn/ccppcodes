#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w) { n = _n; w = _w; }

    bool operator< (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> graph [51000];
int dp [50100] [110], N, M;

int solve (int prev_node, int current_index, int counter)
{
    printf ("current_node: %d\n", current_index);

    if (counter > M)
        return 0;
    //if (dp [current_index] [counter] != -1)
    //    return dp [current_index] [counter];
    if (counter == M)
        return 1;
    if (graph [current_index].size() == 1)
        return 0;

    int solution = 0;

    for (int i = 0; i < graph [current_index].size(); i++)
    {
        if (prev_node == graph [current_index] [i].n)
            continue;
        solution += solve (current_index, graph [current_index] [i].n, counter + graph [current_index] [i].w);
    }

    return (dp [current_index] [counter] = solution);
}

int main()
{
    int a, b, c, solution = 0;

    memset (dp, -1, sizeof dp);

    scanf ("%d %d", &N, &M);

    for (int i = 0; i < N - 1; i++)
    {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (b, c));
        graph [b].push_back (edge (a, c));
    }

    for (int i = 1; i <= N; i++)
        solution += solve (i, i, 0);

    printf ("%d\n", solution);

    return 0;
}






