#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <utility>

using namespace std;

int n, k;

struct contestant
{
    int p, e;

    contestant() { }
    contestant(int _p, int _e) { p = _p; e = _e; }

    void get()
    {
        scanf ("%d %d", &p, &e);
    }

    bool operator< (const contestant &B) const
    {
        return p > B.p;
    }
};

contestant contestants[20], cpy [20];

int main()
{
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        contestants [i].get();

    int exp = 1<<n, solution = 1<<30, limit = log2(n);

    for (int i = 0; i < exp; i++)
    {
        for (int asd = 0; asd < n; asd++)
            cpy [asd] = contestants [asd];
        int defeated = 0;
        int current = i;

        int points = 0, cnt = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1<<j))
            {
                cnt += cpy [j].e;
                points++;
            }
            else
                cpy [j].p++;
        }

        int found(0);

        for (int j = 0; j < n; j++)
            if (cpy [j].p > points || cpy [j].p == points && !((1<<j) & i))
                found++;

        if (found < k)
            solution = min (solution, cnt);
    }

    if (solution != 1<<30)
        printf ("%d\n", solution);
    else
        printf ("-1\n");

    return 0;
}




