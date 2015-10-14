#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

vector <int> graph [1000];
typedef long long int ull;
int start, n, m;
ull cnt;

bool visited [110];

int dfs (int prev, int current)
{
    visited [current] = true;
    cnt++;
    int ret = 0;
    for (int i = 0; i < graph [current].size(); i++)
        if (!visited [graph [current] [i]] && graph [current] [i] != prev)
            ret = max (ret, dfs (current, graph [current] [i]));


    return ret + 1;
}

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        graph [a].push_back (b);
        graph [b].push_back (a);
    }

    if (m == 0)
    {
        printf ("1\n");
        return 0;
    }

    ull maximum = 0LL, solution = 1LL;

    for (int i = 1; i <= n; i++)
    {
        if (visited [i])
            continue;
        cnt = 0;
        start = i;

        dfs (i, i);

        if (cnt == 1)
            continue;

        ull ret = 1;

        for (ull j = 0; j < cnt - 1; j++)
            solution *= 2LL;

    }

    cout<<solution<<endl;

    return 0;
}
/*
5 5
5 1
1 4
4 2
2 4
2 3
*/



