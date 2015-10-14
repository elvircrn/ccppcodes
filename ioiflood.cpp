#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LEFT  0
#define UP    1
#define RIGHT 2
#define DOWN  3

#define DFS_WHITE 0
#define DFS_GREY  1
#define DFS_BLACK 2

#define DEBUG

struct point
{
    int x, y, index;

    point() { }
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void get(int _index)
    {
        index = _index;
        scanf ("%d %d", &x, &y);
    }

    int get_direction(const point &B) const
    {
        if (B.x - x < 0)
            return LEFT;
        else if (B.y - y > 0)
            return UP;
        if (B.x - x > 0)
            return RIGHT;
        else
            return DOWN;
    }

    void print()
    {
        printf ("x: %d y: %d\n", x, y);
    }

    bool operator == (const point &B) const
    {
        return x == B.x && y == B.y;
    }

    bool operator < (const point &B) const
    {
        return (x == B.x) ? y > B.y : x < B.x;
    }
};

struct edge
{
    point a, b;

    edge() { }
    edge(const point &_a, const point &_b)
    {
        a = _a;
        b = _b;
    }

    bool operator< (const edge &B) const
    {
        return (a == B.a) ? b < B.b : a < B.a;
    }

    int get_direction()
    {
        if (a.x != b.x)
            return RIGHT;
        else
            return UP;
    }
};

vector <vector <int> > directions = { { 3, 0, 1 } , { 0, 1, 2 }, { 1, 2, 3 }, { 2, 3, 0 } };
int color[1000100];
vector <vector <int> > graph(100100);
vector <point> points(100100);
vector <edge> edges;
int n, w, current_color = 2, color_index[100100];
map <edge, int>  visited;
map <edge, bool> destroyed;
stack <int> S;

void dfs(int current_index, int prev_index, int prev_direction)
{
    #ifdef DEBUG

    points[current_index].print();

    printf ("origin:                            ");
    if (prev_direction == LEFT)
        printf ("LEFT\n");
    else if (prev_direction == UP)
        printf ("UP\n");
    else if (prev_direction == RIGHT)
        printf ("RIGHT\n");
    else
        printf ("DOWN\n");
    system ("pause");

    #endif

    S.push(current_index);
    color[current_index] = DFS_GREY;
    color_index[current_index] = current_color;

    //choose the best direction
    for (int direction : directions[prev_direction])
    {
        #ifdef DEBUG
        if (direction == LEFT)
            printf ("LEFT:\n");
        else if (direction == UP)
            printf ("UP:\n");
        else if (direction == RIGHT)
            printf ("RIGHT:\n");
        else
            printf ("DOWN:\n");
        #endif
        //traverse neigbors
        for (int next : graph[current_index])
        {
            #ifdef DEBUG
            printf ("   neigbors: %d %d\n", points[next].x, points[next].y);
            #endif
            if (next == prev_index || color[next] == DFS_BLACK)
                continue;

            //found the right point
            if (direction == points[current_index].get_direction(points[next]))
            {
                //found a loop
                if (color[next] == DFS_GREY && color_index[next] == current_color)
                {
                    #ifdef DEBUG
                    printf ("||||||||||||next GREY: "); printf ("S.size(): %d ", S.size());  points[next].print();
                    #endif

                    //flush the queue
                    destroyed[edge(points[next], points[current_index])] = true;
                    destroyed[edge(points[current_index], points[next])] = true;

                    w--;

                    while(!S.empty())
                    {
                        if (S.top() == next)
                        {
                            S.pop();
                            break;
                        }

                        int x = S.top();
                        S.pop();
                        int y = S.top();

                        #ifdef DEBUG
                        printf ("D: \n");
                        printf ("ind: %d %d\n", x + 1, y + 1);
                        points[x].print();
                        points[y].print();
                        #endif

                        w--;
                        destroyed[edge(points[x], points[y])] = true;
                        destroyed[edge(points[y], points[x])] = true;
                    }

                    current_color++;

                    color_index[current_index] = current_color;
                }
                else if (color[next] == DFS_GREY && color_index[next] < current_color && !visited[edge(points[current_index], points[next])])
                {
                    visited[edge(points[current_index], points[next])] = true;
                    visited[edge(points[next], points[current_index])] = true;

                    dfs(next, current_index, direction);
                }
                //found a non visited node
                else if (color[next] == DFS_WHITE)
                {
                    visited[edge(points[current_index], points[next])] = true;
                    visited[edge(points[next], points[current_index])] = true;
                    dfs(next, current_index, direction);
                }
                break;
            }
        }
    }

    color[current_index] = DFS_BLACK;
}

int convert[100100];
bool visited[100100];
int target_node;

bool dfs(int current_node, int prev_direction)
{
    for (int direction : directions[prev_direction])
    {
        for (int next : graph[current_index])
        {
            if (direction == points[current_index].get_direction(points[next]))
            {
                if (next == target_node)
                {
                    return true;
                }
                if (dfs(next, direction))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int min_index, minimum = 2000000;

    int maxy = 0;

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        points[i].get(i);

    sort (points.begin(), points.end());

    for (int i = 0; i < points.size(); i++)
        convert[points[i].index] = i;

    scanf ("%d", &w);
    for (int i = 0; i < w; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        a--;
        b--;

        a = convert[a];
        b = convert[b];

        graph[a].push_back(b);
        graph[b].push_back(a);

        edges.push_back(edge(points[a], points[b]));
    }


    for (; target_node < points.size(); target_node++)
    {
        memset(visited, false, sizeof visited);

        dfs(target_node, )
    }

    int index = 1;

    vector <int> solution;

    for (edge e : edges)
    {
        if (!destroyed[e])
            solution.push_back(index);
        index++;
    }

    printf ("%d\n", solution.size());
    for (int i = 0; i < solution.size(); i++)
        printf ("%d\n", solution [i]);

    return 0;
}
/*
7
2 3
3 3
1 2
2 2
3 2
1 1
2 1
8
1 2
1 4
2 5
4 5
3 4
3 6
6 7
4 7





15
100 100
150 100
200 100
200 200
200 300
100 300
100 200
150 200
170 200
150 220
200 150
250 150
250 200
170 220
170 150
18
2 1
2 3
3 11
12 11
12 13
13 4
5 4
5 6
6 7
7 1
9 8
8 10
14 10
14 9
4 9
9 15
15 11
11 4






15
1 1
8 1
4 2
7 2
2 3
4 3
6 3
2 5
4 5
6 5
4 6
7 6
1 8
4 8
8 8
17
1 2
2 15
15 14
14 13
13 1
14 11
11 12
12 4
4 3
3 6
6 5
5 8
8 9
9 11
9 10
10 7
7 6
*/






















