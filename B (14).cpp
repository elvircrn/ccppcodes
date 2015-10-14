#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int cnt1, cnt2, x, y;

int main()
{
    scanf ("%d %d %d %d", &cnt1, &cnt2, &x, &y);

    int left = 0, right = 1000000100, pivot;

    int res1 = (x * cnt1) / (x - 1);

    cnt2 -= (res1 / (x * y));

    if (cnt2 <= 0)
    {
        printf ("%d\n", res1);
        return 0;
    }

    int current = res1 + 1;

    while (left <= right)
    {
        pivot = (left + right) / 2;


        pivot = 5;


        int r = cnt1 + cnt2 + (pivot / x) + (pivot / y) - (pivot / (x * y));
        printf ("pivot: %d r: %d\n", pivot, r);
        system ("pause");

        if (pivot == r)
        {
            printf ("%d\n", pivot);
            return 0;
        }
        else if (pivot > r)
        {
            right = pivot - 1;
        }
        else
        {
            left = pivot + 1;
        }
    }

    printf ("%d\n", pivot);

    return 0;

    int v1 = (x * cnt1 + cnt1) / x;

    int current_element = v1 + 1;


    if (current_element % y == 0)
    {
        current_element++;
        printf ("%d\n", current_element + (y * cnt2 + cnt2) / y);
    }
    else
    {
        int cpy = cnt2;

        cpy -= (current_element % y);

        if (cpy <= 0)
        {
            printf ("%d\n", current_element + cnt2);
            return 0;
        }

        current_element += (current_element % y);

        current_element++;

        printf ("%d\n", current_element + (y * cpy + cpy) / y);
    }

    return 0;
}



/*
░░░░░░░░░░░░▄▐
░░░░░░▄▄▄░░▄██▄
░░░░░▐▀█▀▌░░░░▀█▄
░░░░░▐█▄█▌░░░░░░▀█▄
░░░░░░▀▄▀░░░▄▄▄▄▄▀▀     you have been spooked by the spooky skeleton
░░░░▄▄▄██▀▀▀▀
░░░█▀▄▄▄█░▀▀
░░░▌░▄▄▄▐▌▀▀▀
*/
