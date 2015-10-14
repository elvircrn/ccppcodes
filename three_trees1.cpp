#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

int get(int n)
{
    return (n * (n + 1)) / 2;
}

vector <int> graph [4] [4000];
vector <int> final_graph [4] [4000];
vector <int> leafs [4];
vector <int> new_leafs;

pair <int, int> max_indices [4];
int max_depths [3], solution, size [4], roots [4];

bool visited [3110] [3110];

int global, solution_a;

void traverse (int tree_index, int parent_index, int current_index, int depth)
{
    printf ("%d\n", depth);
    if (!visited [global] [current_index])
    {
        visited [global] [current_index] = true;
        visited [current_index] [global] = true;
        solution_a += depth;
    }

    if (max_depths [tree_index] < depth)
    {
        max_depths [tree_index] = depth;
        max_indices [tree_index] = make_pair (global, current_index);
    }

    for (int i = 0; i < graph [tree_index] [current_index].size(); i++)
        if (parent_index != graph [tree_index] [current_index] [i])
            traverse (tree_index, current_index, graph [tree_index] [current_index] [i], depth + 1);

}

int main()
{
    int a, b;
    for (int i = 0; i < 3; i++)
        scanf ("%d", &size [i]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size [i] - 1; j++)
        {
            scanf ("%d %d", &a, &b);
            a += i * 1005;
            b += i * 1005;
            graph [i] [a].push_back (b);
            graph [i] [b].push_back (a);
        }
    }

    for (int i = 0; i < 3100; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (graph [j] [i].size())
            {
                global = i;
                traverse (j, i, i, 0);
            }
        }
    }

    printf ("%d\n", solution_a);



    return 0;
}
/*
5 0 0
1 2
2 5
3 4
4 2


6 0 0
1 2
2 5
3 4
4 2
3 6

6 0 0
1 2
2 5
3 4
4 2
1 6
*/
















