#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int n, array [100100], cnt;
bool visited [101010];

void dfs (int current_node)
{
    cnt++;
    if (visited [current_node])
        return;
    visited [current_node] = true;
    dfs (array [current_node]);
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &array [i]);

    for (int i = 1; i <= n; i++)
    {
        cnt = -1;
        dfs (i);
        printf ("%d\n", cnt);
    }

    return 0;
}
