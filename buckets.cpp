#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int capacities [3], n;
bool found;

struct state
{
    int buckets [3];

    state () { }
    state (int a, int b, int c) { buckets [0] = a; buckets [1] = b; buckets [2] = c; }

    bool operator < (const state &B) const
    {
        for (int i = 0; i < 3; i++)
            if (buckets [i] != B.buckets [i])
                return buckets [i] < B.buckets [i];
    }

    void cut()
    {
        for (int i = 0; i < 3; i++)
            if (buckets [i] > capacities [i])
                buckets [i] = capacities [i];
            else if (buckets [i] < 0)
                buckets [i] = 0;
    }

    void get()
    {
        for (int i = 0; i < 3; i++)
            scanf ("%d", &buckets [i]);
    }

    bool operator == (const state &B) const
    {
        for (int i = 0; i < 3; i++)
            if (buckets [i] != B.buckets [i])
                return false;

        return true;
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
            printf ("%d ", buckets [i]);
        printf ("\n");
    }
};

state default_state, querry;
set <state> visited;

void dfs (state &current_state)
{
    //current_state.print();

    visited.insert (current_state);

    if (found)
        return;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (current_state.buckets [i] == 0 || i == j || current_state.buckets [j] == capacities [j])
                continue;

            state new_state = current_state;

            int a = current_state.buckets [i], b = current_state.buckets [j];

            new_state.buckets [j] += a;

            if (new_state.buckets [j] > capacities [j])
                new_state.buckets [j] = capacities [j];

            new_state.buckets [i] -= (new_state.buckets [j] - b);

            if (new_state.buckets [i] < 0)
                new_state.buckets [i] = 0;

            if (visited.find (new_state) == visited.end())
                dfs (new_state);

            if (found)
                return;
        }
    }
}

int sum;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    default_state = state();
    querry = state();

    for (int i = 0; i < 3; i++)
    {
        scanf ("%d", &capacities [i]);
        sum += capacities [i];
    }

    default_state.get();

    dfs (default_state);

    scanf ("%d", &n);

    while (n--)
    {
        querry.get();
        found = false;

        if (visited.find (querry) != visited.end())
            printf ("DA\n");
        else
            printf ("NE\n");
    }

    return 0;
}
/*
8 5 4
8 0 0
3
3 1 4
3 4 1
*/

