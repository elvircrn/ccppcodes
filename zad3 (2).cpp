#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int parent [100100], n, m;

int find_parent(int x)
{
    if (parent [x] == x)
        return x;
    else
        return parent [x] = find (parent [x]);
}

int team_union (int )

int main()
{
    int a, b;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &a, &b);
    }


    return 0;
}
