#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define width  first
#define height second
#define MAX_N  20
#define INF    2000000000

int n, dp [MAX_N] [MAX_N], parent [MAX_N] [MAX_N];
pair <int, int> matrices [MAX_N];

int f (int left, int right)
{
    int min_index;

    if (left == right)
        return 0;
    else if (dp [left] [right] != INF)
        return dp [left] [right];

    for (int i = left; i < right; i++)
    {
        int val = matrices [left].height * matrices [i].width * matrices [right].width + f (left, i) + f (i + 1, right);

        if (val < dp [left] [right])
        {
            dp [left] [right] = val;
            min_index = i;
        }
    }

    parent [left] [right] = min_index;

    return dp [left] [right];
}

void reconstruct (int left, int right)
{
    //printf ("left: %d right: %d\n", left, right);

    if (left == parent [left] [right] && parent [left] [right] == right - 1)
        printf ("A%d x A%d", left + 1, left + 2);
    else if (parent [left] [right] == left)
    {
        printf ("A%d x (", left + 1); reconstruct(parent [left] [right] + 1, right); printf (")");
    }
    else if (parent [left] [right] == right - 1)
    {
        printf ("("); reconstruct(left, parent [left] [right]);
        printf (") x A%d", right + 1);
    }
    else
    {
        printf ("("); reconstruct (left, parent [left] [right]); printf (") x ("); reconstruct (parent [left] [right] + 1, right); printf (")");
    }

    return;
}

//((A1 x (A2 x A3)) x ((A4 x A5) x A6))
int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);

    int test_id = 1;

    while (scanf ("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp [i] [j] = INF;

        for (int i = 0; i < n; i++)
            scanf ("%d %d", &matrices [i].height, &matrices [i].width);

        /*printf ("%d\n", f (0, n - 1));

        printf ("parent: %d\n", parent [0] [2]);*/

        f (0, n - 1);

        printf ("Case %d: ", test_id++); printf ("("); reconstruct(0, n - 1); printf (")\n");
    }

    return 0;
}
/*
6
30 35
35 15
15 5
5 10
10 20
20 25

2
10 20
20 30

4
10 20
20 30
30 40
40 30


2
10 10
10 10

4
40 20
20 30
30 10
10 30
*/







