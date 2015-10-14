#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define INF -1000

int x, k, q, a, b;

struct competition
{
    int num2, num1;

    competition() { }
    competition(int _num2, int _num1) { num2 = _num2; num1 = _num1; }

    bool operator< (const competition & B) const
    {
        return num2 < B.num2;
    }

    void get()
    {
        scanf ("%d %d", &num2, &num1);
    }

    void print()
    {
        printf ("num2: %d num1: %d\n", num2, num1);
    }

    bool div2_only()
    {
        if (num1 == INF)
            return true;
        else
            return false;
    }

    int GET()
    {
        if (num1 == INF)
            return num2;
        else
            return num1;
    }
};

competition competitions[4005];

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d %d", &x, &k);
    for (int i = 0; i < k; i++)
    {
        scanf ("%d", &q);
        if (q == 1)
        {
            scanf ("%d %d", &a, &b);
            competitions [i] = competition(a, b);
        }
        else
        {
            scanf ("%d", &a);
            competitions [i] = competition(a, INF);
        }
    }

    sort (competitions, competitions + k);

    int minimum(0), maximum(0);
    int current_index = 0;

    competitions [k] = competition(x, INF);

    k++;

    for (int i = 0; i < k; i++)
    {
        maximum += competitions[i].num2 - current_index - 1;
        int dif = competitions[i].num2 - current_index - 1;
        if (dif >= 1)
        {
            if (dif % 2 == 0)
                minimum += dif / 2;
            else
                minimum += ((dif / 2) + 1);

        }
        current_index = competitions[i].GET();
    }

    printf ("%d %d\n", minimum, maximum);

    return 0;
}

