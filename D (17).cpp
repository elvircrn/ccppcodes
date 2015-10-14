#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define LIMIT 100100

struct edge
{
    long long int m, n, w;

    edge() { }
    edge(long long int _n, long long int _w) { n = _n; w = _w; }
    edge(long long int _m, long long int _n, long long int _w) { m = _m; n = _n; w = _w; }
};

struct tree_edge
{
    long long int n, w;

    tree_edge() { }
    tree_edge(long long int _n, long long int _w) { n = _n; w = _w; }
};

long long int v, q, impact [LIMIT];
vector <edge> graph [100100];
vector <edge> edges;

long long int root = 1;
long long int d [LIMIT];
double total;

long long int dfs1(int prev_node, int current_node)
{
    long long int counter = 0;

    for (long long int i = 0; i < graph [current_node].size(); i++)
    {
        long long int u = graph [current_node] [i].n;

        if (prev_node == u)
            continue;

        counter += dfs1(current_node, u) + 1;
    }

    return d[current_node] = counter;
}

long long int ret(long long int i, long long int weight)
{
    long long int from = edges [i].m, where = edges [i].n;

    if (d [from] > d [where])
        swap (from, where);

    long long int left_part  = d [from] + 1;
    long long int right_part = v - (d [from] + 1);

    long long int k = (left_part * (right_part - 1) * right_part + (right_part * (left_part - 1) * left_part));

    return weight * k * 6;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>v;
    for (long long int i = 0; i < v - 1; i++)
    {
        long long int a, b, c;
        cin>>a>>b>>c;

        graph [a].push_back(edge(b, c));
        graph [b].push_back(edge(a, c));
        edges.push_back(edge(a, b, c));
    }

    dfs1(root, root);

    for (long long int i = 0; i < edges.size(); i++)
        total += ret(i, edges [i].w);

    cin>>q;

    cout<<fixed<<setprecision(6);

    long long int edge_index, weight;
    while (q--)
    {
        cin>>edge_index>>weight;
        edge_index--;

        total -= ret(edge_index, edges [edge_index].w);
        total += ret (edge_index, weight);

        edges[edge_index].w = weight;

        double average = total / ((double)v * ((double)v - 1) * ((double)v - 2));

        cout<<average<<endl;
    }

    return 0;
}

/*
3
2 3 5
1 3 3
5
1 4
2 2
1 2
2 1
1 1

19
1 8 1
1 6 1
1 2 1
1 15 1
15 12 1
15 17 1
17 19 1
17 18 1
15 16 1
15 14 1
12 13 1
12 11 1
8 9 1
8 10 1
6 7 1
5 6 1
3 2 1
4 2 1

*/




































