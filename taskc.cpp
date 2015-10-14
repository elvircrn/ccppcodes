#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define LEFT  1
#define RIGHT 2

int n;

cow cows [200010];
int tree1 [200010], tree2 [200010];

void update (int o, int index, int value)
{
    while (index <= value)
    {
        if (o == 1)
        {
            tree1 [index] += value;
            index += index & (-index);
        }
        else if (o == 2)
        {
            tree2 [index] += value;
            index += index & (-index);
        }
    }
}
int get(int o, int index)
{
    int sum = 0;
    while (index)
    {
        if (o == 1)
        {
            sum += tree1 [index];
            index -= index & (-index);
        }
        else if (o == 2)
        {
            sum += tree2 [index];
            index -= index & (-index);
        }
    }
    return sum;
}
int main()
{
    int x;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &x);
        if (x == RIGHT)
        {
            update(1, i, 1);
        }
        else
        {
            update(2, i, 1))
        }
    }



    return 0;
}
