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
        l [from] -= min (capacity [to] - asd, l [from]);

        return true;
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
            printf ("%d ", l [i]); putchar ('\n');
    }
};

map <state, bool> visited;

void dfs (int x, int y, int z)
{
    state cop (x, y, z), current_state(x, y, z);
    visited [current_state] = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cop = current_state;
            if (cop.transfer(i, j) && !visited [cop])
                dfs (cop.l [0], cop.l [1], cop.l [2]);
        }
    }
}

int main()
{
    int t;

    for (int i = 0; i < 3; i++)
        scanf ("%d", &capacity [i]);
    state start, test;
    start.get();

    scanf ("%d", &t);

    dfs (start.l [0], start.l [1], start.l [2]);

    while (t--)
    {
        test.get();
        if (visited [test])
            printf ("DA\n");
        else
            printf ("NE\n");
    }

    return 0;
}












