#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

int leftb, rightb, rightleft [100001], leftright [100001], n, cnt, maxsol, maximum, hill [100001], area;

int main ()
{
    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &hill [i]);
        leftright [i] = max (leftright [i], hill [i]);
    }


    for (int i = n - 1; i > -1; i--)
    {
        rightleft [i] = max (rightleft [i], hill [i]);
    }

    for (int i = n - 2; i > 0; i--)
    {
        //1
        if (hiil [i] < rightleft [i])
        {

        }
    }
    return 0;
}
