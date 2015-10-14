#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define INF 1<<27
#define start 1
#define end   v

bool visited [300];
int parent [300], D[300], dist[300] [300];

struct edge
{
    int m, n, w;

    edge() { }
    edge(int _m, int _n, int _w) { m = _m; n = _n; w = _w; }

    bool operator< (const edge &B) const
    {
        return w > B.w;
    }
};

int e, v;

vector <int> graph[300];

int shortest_path()
{
    memset(visited, false, sizeof visited);
    memset(D, 0, sizeof D);
    memset(parent, -1, sizeof parent);
    priority_queue <edge> Q;

    parent [start] = start;
    D [start] = 0;

    Q.push(edge(start, start, 0));
    while (!Q.empty())
    {
        edge help = Q.top();
        Q.pop();

        if (!visited[help.n])
        {
            visited[help.n] = true;
            D [help.n] = help.w;

            parent[help.n] = help.m;

            if (help.n == end)
                return help.w;

            for (int i = 0; i < graph [help.n].size(); i++)
                if (!visited [graph [help.n] [i]])
                    Q.push(edge(help.n, graph[help.n] [i], D [help.n] + dist[help.n] [graph [help.n] [i]]));

        }
    }
}

int main()
{
    vector <int> main_path;

    scanf ("%d %d", &v, &e);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf ("%d %d %d", &a, &b, &c);

        graph[a].push_back(b);
        graph[b].push_back(a);

        dist [a] [b] = c;
        dist [b] [a] = c;
    }

    shortest_path();

    int current = end;

    while (parent [current] != current)
    {
        main_path.push_back(current);
        current = parent [current];
    }

    main_path.push_back(start);

    int solution = 0;
    int length = shortest_path();

    for (int i = 0; i < main_path.size() - 1; i++)
    {
        dist[main_path[i]] [main_path[i + 1]] *= 2;
        dist[main_path[i + 1]] [main_path[i]] *= 2;

        solution = max (solution, shortest_path() - length);

        dist[main_path[i]] [main_path[i + 1]] /= 2;
        dist[main_path[i + 1]] [main_path[i]] /= 2;
    }

    printf("%d\n", solution);

    return 0;
}
/*
5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2
*/













































