#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <queue>

using namespace std;

struct item
{
    int value, deadline;

    item () { }
    item (int _value, int _deadline) { value = _value; deadline = _deadline; }

    bool operator < (const item &B) const
    {
        return deadline > B.deadline;
    }

    void get()
    {
        scanf ("%d %d", &value, &deadline);
    }

    void print()
    {
        printf ("%d %d\n", value, deadline);
    }
};

int n, array [201001], solution, maxn;
bool visited [201001];
priority_queue <item> Q;

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        item input = item();
        input.get();
        items.add (input);

        Q.push (input);

        maxn = max (maxn, input.deadline);
    }

    while (!Q.empty())
    {
        if (array [])
    }

    return 0;
}
/*
4
50 2
10 1
20 2
30 2
*/






