#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n;

struct Friend
{
    int fun;
    bool isFriend [20];

    Friend () { }
    Friend (int _fun) { fun = _fun; }

    void get()
    {
        scanf ("%d", &fun);
        for (int i = 0; i < n; i++)
            scanf ("%d", &isFriend [i]);
    }

    void print()
    {
        printf ("%d ", fun);
        for (int i = 0; i < n; i++)
            printf ("%d ", isFriend [i]); printf ("\n");
    }
};

int cnt, solution;
Friend friends [100];
bool can [20];

void Subsets (int current_index, bool visited [])
{
    if (current_index == n)
    {
        memset (can, false, sizeof can);
        cnt = 0;
        for (int i = 0; i < n; i++)
            if (visited [i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!friends [i].isFriend [j] && visited [j])
                    {
                        cnt = 0;
                        goto l1;
                    }
                }
                cnt += friends [i].fun;
            }

        l1:;

        solution = max (solution, cnt);
    }
    else
    {
        visited [current_index] = true;
        Subsets (current_index + 1, visited);
        visited [current_index] = false;
        Subsets (current_index + 1, visited);
    }
}

bool VISITED [20];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        friends [i].get();

    Subsets (0, VISITED);

    printf ("%d\n", solution);

    return 0;
}
