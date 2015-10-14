#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n, x, tree [100005], maxn, d, i, help = 0, sol, maximum;
bool updatee [100005];

void set (int ind, int val)
{
    while (ind <= 100000)
    {
        tree [ind] += 1;
        ind += ind & (-ind);
    }
    return;
}

int sum (int ind)
{
    int suma = 0;

    while (ind)
    {
        suma += tree [ind];
        ind -= ind & (-ind);
    }
    return suma;
}

int bs (int wanted)
{
    int leftb = 1, rightb = 100000, pivot;
    while(leftb < rightb)
    {
        pivot = (leftb + rightb) / 2;
        if (sum (pivot) < wanted) leftb = pivot + 1;
        else rightb = pivot;
    }
    return rightb;
}

int main ()
{
    int cnt = 0;
    //freopen ("unos.txt", "r", stdin);
    //freopen ("izlaz.txt", "w", stdout);

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf ("%d %d", &d, &x);
        maxn = max (x, maxn);

        if (d == 1)
        {
                cnt++;
                set (x + 1, 1);
        }

        else
        {
            printf ("%d\n", bs (x) - 1+);
        }
    }
    return 0;
}
