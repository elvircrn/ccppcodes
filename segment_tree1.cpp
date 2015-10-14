#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<27

int values [1000000], n, range [10000000];

//MIN_TREE

class SegmentTree
{
public:

    void BuildSegmentTree()
    {
        buildSegmentTree(0, n - 1, 1);
    }

    int Get(int b, int e)
    {
        return query (b, e, 0, n - 1, 1);
    }

    int query(int leftQ, int rightQ, int b, int e, int node)
    {
        if (leftQ <= b && e <= rightQ)
            return range [node];
        else if (b > e || e < leftQ || rightQ < b)
            return -1;
        else if (leftQ <= b && e <= rightQ)
            return range [node];

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

    int buildSegmentTree(int b, int e, int node)
    {
        if (b == e)
        {
            range [node] = b;
            return b;
        }
        else if (b > e)
            return -1;

        int left_side  = buildSegmentTree (b, (b + e) / 2, 2 * node);
        int right_side = buildSegmentTree ((b + e) / 2 + 1, e, 2 * node + 1);

        if (left_side == -1)
            return right_side;
        else if (right_side == -1)
            return left_side;

        if (values [left_side] <= values [right_side])
            return range [node] = left_side;
        else
            return range [node] = right_side;
    }
};

SegmentTree segment_tree;

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &values [i]);

    segment_tree.BuildSegmentTree();

    printf ("%d\n", values [segment_tree.Get(4, 4)]);

    return 0;
}
















