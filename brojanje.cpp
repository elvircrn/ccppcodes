#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n, x, tree [100005], d, i, help = 0, sol, maximum;
bool updatee [100005];

void set (int ind, int val)
{
    while (ind <= 100001)
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

int bs (int wanted, int dp)
{
    int leftb = 1, rightb = 100001, pivot, minsol = 1000000, now;

    while (leftb <= rightb)
    {
        pivot = (leftb + rightb) / 2;
        now = sum (pivot);

        if (now == wanted)
        {
            minsol = min (minsol, pivot);
            rightb = pivot - 1;
        }

        else if (now > wanted)
        {
            rightb = pivot - 1;
        }

        else if (now < wanted)
        {
            leftb = pivot + 1;
        }
    }

    /*if (minsol + 1 == 1000000) */printf ("%d %d\n", wanted, dp);
    return minsol;
}

int main ()
{
    //freopen ("unos.txt", "r", stdin);
    //freopen ("izlaz.txt", "w", stdout);

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf ("%d %d", &d, &x);

        if (d == 1)
        {
            if (!updatee [x + 1])
            {
                set (x + 1, 1);
                updatee [x + 1] = 1;
            }
        }

        else
        {
            printf ("%d\n", bs (x, i) - 1);
        }
    }
    return 0;
}
