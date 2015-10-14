#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>

using namespace std;

int n, k, w, l, r;
char c;
int array [100100], tree [100100] [13];

void set_value(int x, int value, int tree_index)
{
    while (x <= n)
    {
        tree [x] [tree_index] += value;
        x += (x & -x);
    }
}

int get_sum(int x, int tree_index)
{
    if (x == 0)
        return 0;
    int sum = 0;
    while (x > 0)
    {
        sum += tree [x] [tree_index];
        x -= (x & (-x));
    }

    return sum;
}

int main()
{
    scanf ("%d %d %d", &n, &k, &w); getchar();

    int current_index = 1;
    while (isdigit (c = getchar()))
    {
        if (c == '1')
        {
            //array [current_index] = 1;
            if (current_index % k == 1)
                set_value (current_index, 1, 0);
        }

        current_index++;
    }

    printf ("%d\n", get_sum(6, 0));

    /*while (w--)
    {
        scanf ("%d %d", &l, &r);
        printf ("%d\n", get_sum (r, 0) - get_sum (l - 1, 0));
    }*/

    return 0;
}



