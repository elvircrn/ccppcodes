#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int capacity [5];

struct state
{
    int l [3];

    state() { }
    state(int _x, int _y, int _z)
    {
        l [0] = _x;
        l [1] = _y;
        l [2] = _z;
    }

    bool operator< (const state &B) const
    {
        for (int i = 0; i < 2; i++)
            if (l [i] != B.l [i])
                return l [i] < B.l [i];
        return l [2] < B.l [2];
    }

    void get()
    {
        for (int i = 0; i < 3; i++)
            scanf ("%d", &l [i]);
    }

    bool transfer(int from, int to)
    {
        if (from == to || l [from] == 0 || l [to] == capacity [to])
            return false;

        int asd = l [to];

        l [to] += min (capacity [to] - asd, l [from]);;
        l [from] -= min (capacity [to] - asd, l [from]);;

        return true;
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
            printf ("%d ", l [i]); putchar ('\n');
    }

    void create(int x, int y, int z)
    {
        l [0] = x;
        l [1] = y;
        l [2] = z;
    }
};

map <state, bool> visited;

state cop, current_state;

void dfs (int x, int y, int z)
{
    visited [current_state] = true;

    current_state = state (x, y, z);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;

            current_state.l [0] = x;
            current_state.l [1] = y;
            current_state.l [2] = z;

            if (current_state.transfer(i, j) && !visited [current_state])
                dfs (current_state.l [0], current_state.l [1], current_state.l [2]);
        }
    }
}

int main()
{
    freopen ("in.txt", "r", stdin);
    int t;
    state start, test;

    for (int i = 0; i < 3; i++)
        scanf ("%d", &capacity [i]);

    start.get();
    dfs (start.l [0], start.l [1], start.l [2]);

    cout<<"kooados"<<endl;


    /*scanf ("%d", &t);

    while (t--)
    {
        test.get();
        if (visited [test])
            printf ("DA\n");
        else
            printf ("NE\n");
    }*/

    return 0;
}
/*
8 5 4
8 0 0
*/











