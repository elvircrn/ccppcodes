#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct part
{
    int pq, ind;
    bool me;

    part () {}
    part (int a, int b, bool tf) {pq = a; ind = b; me = tf;}

    bool operator < (const part & xx) const
    {
        if (pq == xx.pq) return ind > xx.ind;
        else return pq < xx.pq;
    }
};

int n, m, a, b, t, A;

priority_queue <part> PQ;

int main ()
{
    scanf ("%d", &t);

    while (t--)
    {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &A);
            PQ.push (part (A, i, (i == m)));
        }

        int sol = 1;

        while (PQ.size())
        {
            if ((PQ.top()).me) printf ("%d\n", sol);
            PQ.pop();
            sol++;
        }
    }

    return 0;
}
