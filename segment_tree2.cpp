#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int values [100000], range [100000], n;

class SegmentTree
{
public:

    int query(int leftQ, int rightQ, int b, int e, int node)
    {
        if (leftQ <= b && e <= rightQ)
            return range [node];
        else if (e < leftQ || rightQ < b || b > e)
            return -1;

        int left_range  = query (leftQ, rightQ, b, (b + e) / 2, 2 * node);
        int right_range = query (leftQ, rightQ, (b + e) / 2 + 1, e, 2 * node + 1);

        if (left_range == -1)
            return right_range;
        else if (right_range == -1)
            return left_range;

        if (values [left_range] <= values [right_range])
            return left_range;
        else
            return right_range;
    }

    int BuildSegmentTree()
    {
        buildSegmentTree(0, n - 1, 1);
    }

    int buildSegmentTree(int b, int e, int node)
    {
        if (b == e)
            return range [node] = b;
        else if (b > e)
            return -1;

        int left_range  = buildSegmentTree(b, (b + e) / 2, 2 * node);
        int right_range = buildSegmentTree((b + e) / 2 + 1, e, 2 * node + 1);

        if (left_range == -1)
            return range [node] = right_range;
        else if (right_range == -1)
            return range [node] = left_range;

        if (values [left_range] <= values [right_range])
            return range [node] = left_range;
        else
            return range [node] = right_range;
    }

};

SegmentTree segment_tree;

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &values [i]);

    segment_tree.buildSegmentTree(0, n - 1, 1);

    printf ("%d\n", values [segment_tree.query(0, n - 1, 0, 1, 1)]);

    return 0;
}
