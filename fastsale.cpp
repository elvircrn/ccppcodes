#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>

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

    bool operator == (const item &B) const
    {
        return (value == B.value && deadline == B.deadline);
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

set <item> items;

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        item input = item();
        input.get();
        items.add (input);

        maxn = max (maxn, input.deadline);
    }

    for (int i = maxn; i >= 1; i--)
    {
        int index = 0;
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (i > items [j].deadline)
                break;

            if (i <= items [j].deadline && !visited [j])
            {
                if (array [i] < items [j].value)
                {
                    array [i] = items [j].value;
                    index = j;
                    found = true;
                }
            }
        }

        if (found) visited [index] = true;
    }

    for (int i = 0; i <= maxn; i++)
        solution += array [i];

    printf ("%d\n", solution);

    return 0;
}
/*
4
50 2
10 1
20 2
30 2
*/





