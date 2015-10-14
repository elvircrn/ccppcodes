#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int offset = 100000;

int beginning [4000000], n, q, tree [4 * 100000 + 5], numbers [400000], counter [400000];

struct segment_tree
{
    int n;

    segment_tree() { }
    segment_tree(int _n) { n = _n; build_tree (1, 0, n - 1); }

    int build_tree(int node, int left, int right)
    {
        if (left == right)
            return tree [node] = counter [numbers [left]];
        else if (left > right)
            return 0;

        int pivot = (left + right) / 2;

        int l = build_tree(2 * node, left, pivot);
        int r = build_tree(2 * node + 1, pivot + 1, right);

        return tree [node] = max (l, r);
    }

    int query(int node, int left, int right, int qleft, int qright)
    {
        if (right < qleft || qright < left)
            return 0;

        if (left == right)
            return counter [numbers [left]];

        if (qleft <= left && right <= qright)
            return tree [node];

        int pivot = (left + right) / 2;

        int l = query (2 * node, left, pivot, qleft, qright);
        int r = query (2 * node + 1, pivot + 1, right, qleft, qright);

        return max (l, r);
    }
};

segment_tree st;

int main()
{
    while (scanf ("%d", &n) == 1 && n)
    {
        scanf ("%d", &q);

        memset (counter, 0, sizeof counter);
        memset (numbers, 0, sizeof numbers);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &numbers [i]);
            numbers [i] += offset;
            if (i && numbers [i - 1] != numbers [i])
                beginning [i] = i;
            else if (i)
                beginning [i] = beginning [i - 1];
            counter [numbers [i]]++;
        }

        st = segment_tree(n);

        while (q--)
        {
            int l, r;

            scanf ("%d %d", &l, &r);
            l--;
            r--;

            if (numbers [l] == numbers [r])
                printf ("%d\n", r - l + 1);
            else
            {
                int left = l, right = beginning [l] + counter [numbers [l]] - 1, cnt1 = right - left + 1, left1, right1;

                left1 = right + 1;

                left  = beginning [r];

                right1 = left - 1;
                right = r;

                int cnt2 = right - left + 1;

                printf ("%d\n", max (max (cnt1, cnt2), st.query(1, 0, n - 1, left1, right1)));
            }
        }
    }


    return 0;
}
/*
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10

7 1
1 2 2 2 2 2 3
3 5
0
*/




































