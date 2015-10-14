#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int DFS_WHITE = 0, DFS_GREY = 1, DFS_BLACK = 2;

class oasis
{
public:
    bool f, w, p;

    oasis() { }
    oasis(bool _f, bool _w, bool _p) { f = _f; w = _w, p = _p; }
};

int N, M, H, S, E, MF, MW;
oasis oases [11];

vector <int> graph [11];
vector <int> st;

int solution, color [100] [100] [10] [10];

void dfs (int current_node, int time_left, int water_left, int food_left)
{
    st.push_back (current_node);
    color [current_node] [time_left] [water_left] [food_left] = DFS_GREY;

    if (oases [current_node].f)
        food_left = MF;
    if (oases [current_node].w)
        water_left = MW;

    //printf ("current_node: %d time_left: %d water_left: %d food_left: %d\n", current_node, time_left, water_left, food_left);

    if (time_left < 0 || water_left <= 0 || food_left <= 0)
    {
        st.pop_back();
        return;
    }

    if (current_node == E)
    {
        for (int s : st)
            printf ("%d ", s);
        printf ("\n");
        solution++;
    }
    for (int i = 0; i < graph [current_node].size(); i++)
        if (color [graph [current_node] [i]] [time_left - 1] [water_left - 1] [food_left - 1] == DFS_WHITE)
            dfs (graph [current_node] [i], time_left - 1, water_left - 1, food_left - 1);

    st.pop_back();
    color [current_node] [time_left] [water_left] [food_left] = DFS_BLACK;

    return;
}


int main()
{
    scanf ("%d %d %d %d %d %d %d", &N, &M, &H, &S, &E, &MF, &MW);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        scanf ("%d %d %d", &a, &b, &c);
        oases [i + 1] = oasis(a, b, c);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        graph [a].push_back (b);
        graph [b].push_back (a);
    }

    printf ("\npaths:\n\n");

    dfs (S, H, MW, MF);

    printf ("%d\n", solution);

    return 0;
}
/*
5 5 10 3 2 3 2
1 0 0
1 1 1
1 1 1
0 0 1
0 1 0
1 2
1 3
1 4
3 4
4 2

3 1 2
3 1 2 1 2
3 1 2 1 2 1 2
3 1 2 1 2 1 2 1 2
3 1 2 1 2 1 2 1 2 1 2
3 1 2 1 2 1 2 1 2 4 2
3 1 2 1 2 1 2 4 2
3 1 2 1 2 4 2
3 1 2 4 2
3 4 2



3 1 2
3 4 2











5 5 30 3 2 3 2
1 0 0
1 1 1
1 1 1
0 0 1
0 1 0
1 2
1 3
1 4
3 4
4 2
*/
