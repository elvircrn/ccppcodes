#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int v, vertices [1000], root, selected [1000], not_selected [1000];
bool used [1000];
vector <int> graph [1000];

int solve (int current_node, int previous_node, bool previous_selected)
{
    if (previous_selected == true)
    {
        if (graph [current_node].size() == 1 && current_node != 0)
            return 0;

        int cnt = 0;
        for (int i = 0; i < graph [current_node].size(); i++)
            if (graph [current_node] [i] != previous_node)
                cnt += solve (graph [current_node] [i], current_node, false);

        return cnt;
    }
    else if (previous_selected == false)
    {
        if (graph [current_node].size() == 1 && current_node != 0)
            return vertices [current_node];

        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < graph [current_node].size(); i++)
        {
            if (graph [current_node] [i] != previous_node)
            {
                cnt1 += solve (graph [current_node] [i], current_node, true);
                cnt2 += solve (graph [current_node] [i], current_node, false);
            }
        }

        return max (vertices [current_node] + cnt1, cnt2);
    }
}

int main()
{
    int A, B;

    scanf ("%d", &v);
    for (int i = 1; i <= v; i++)
        scanf ("%d", &vertices [i]);

    root = 1;

    for (int i = 0; i < v - 1; i++)
    {
        scanf ("%d %d", &A, &B);
        graph [A].push_back (B);
        graph [B].push_back (A);
    }

    graph [0].push_back (root);

    printf ("%d\n", solve (root, 0, false));

    return 0;
}
/*
10
7
1
8
9
3
4
6
2
1
17
1 2
1 3
2 4
2 5
3 6
3 7
3 8
5 9
8 10
*/
