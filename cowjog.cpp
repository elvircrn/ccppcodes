#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;
vector <int> S;

int main()
{
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d", &a, &b);

        if (S.empty())
            S.push_back(b);
        else
        {
            while (S [S.size() - 1] > b)
                S.pop_back();
            S.push_back(b);
        }
    }

    printf ("%d\n", S.size());

    return 0;
}
/*
3 2 1 2 3
1 2 3 2 1
*/
