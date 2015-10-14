#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

#define MAX 200100


int tree [201000];

void Set (int index, int value)
{
    while (index <= MAX)
    {
        tree [index] += value;
        index += (index & -index);
    }
}

void Remove (int index, int value)
{
    while (index <= MAX)
    {
        tree [index] -= value;
        index += index & -index;
    }
}

int Sum (int index)
{
    int sum = 0;

    while (index)
    {
        sum += tree [index];
        index -= index & -index;
    }

    return sum;
}

int GetRange (int start, int end)
{
    return Sum (end) - Sum (start - 1);
}

int GetElement (int index)
{
    return Sum (index) - Sum (index - 1);
}

int t, q, size = 1, a, SUM;

int main ()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &q);
        if (q == 1)
        {
            int ind, val;
            scanf ("%d %d", &ind, &val);
            SUM += ind * val;
            Set (1, val);
            Set (ind + 1, -val);
        }
        else if (q == 2)
        {
            scanf ("%d", &a);
            size++;
            Set (size, a);
            SUM += a;
            Set (size + 1, -a);
        }
        else
        {
            if (size > 1)
            {
                SUM -= Sum (size);
                size--;
            }
        }
        printf ("%.6lf\n", float (float (SUM) / float (size)));
        int k = 3;
    }

    return 0;
}
/*
63
2 1
1 2 20
2 2
1 2 -3
3
3

5
2 1
3
2 3
2 1
3
*/
