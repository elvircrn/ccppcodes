#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define INF 1<<27
#define RANGE_MIN 0
#define RANGE_MAX 1
#define RANGE_SUM 2

//M1 -> MIN
//M2 -> MAX

struct segment_tree
{
    int values [1000100], M1 [2098152], M2 [2098152];
    int n, tree_size;

    segment_tree() { }
    segment_tree(int N)
    {
        n = N;
        tree_size = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    }

    void Create(int N)
    {
        n = N;
        tree_size = (int)(2 * pow (2.0, floor ((log ((double)N) / log(2.0)) + 1)));
    }

    void Initialize(int code)
    {
        initialize(code, 0, n - 1, 1);
    }

    int Query(int code, int left_range, int right_range)
    {
        return query (code, left_range, right_range, 0, n - 1, 1);
    }

    int query(int code, int query_left, int query_right, int left_range, int right_range, int current_node)
    {
        if (right_range < query_left || query_right < left_range)
        {
            return -1;
        }

        if (query_left <= left_range && right_range <= query_right)
        {
            return M1 [current_node];
        }

        int l = query (code, query_left, query_right, left_range, (left_range + right_range) / 2, 2 * current_node);
        int r = query (code, query_left, query_right, (left_range + right_range) / 2 + 1, right_range, 2 * current_node + 1);

        if (l == -1)
            return r;
        else if (r == -1)
            return l;

        if (code == RANGE_MAX)
        {
            if (values [l] < values [r])
                return r;
            else
                return l;
        }
        else if (code == RANGE_MIN)
        {
            if (values [l] < values [r])
                return l;
            else
                return r;
        }
    }

    void initialize(int code, int left_range, int right_range, int current_node)
    {
        if (left_range == right_range)
        {
            M1 [current_node] = left_range;
            M2 [current_node] = left_range;
            return;
        }

        int pivot = (left_range + right_range) / 2;

        initialize (code, left_range, pivot, 2 * current_node);
        initialize (code, pivot + 1, right_range, 2 * current_node + 1);

        int Left1  = values [M1 [2 * current_node]];
        int Right1 = values [M1 [2 * current_node + 1]];

        int Left2  = values [M2 [2 * current_node]];
        int Right2 = values [M2 [2 * current_node + 1]];

        if (Right2 < Left2)
            M2 [current_node] = M2 [2 * current_node];
        else
            M2 [current_node] = M2 [2 * current_node + 1];

        if (Left1 < Right1)
            M1 [current_node] = M1 [2 * current_node];
        else
            M1 [current_node] = M1 [2 * current_node + 1];

        return;
    }
};

struct number
{
    int index, value;
    bool used;

    number() { }
    number(int _index, int _value)
    {
        index = _index;
        value = _value;
    }

    bool operator < (const number &B) const
    {
        if (value != B.value)
            return value < B.value;
        else
            return index < B.index;
    }

    void get(int _index)
    {
        index = _index;
        used = false;
        scanf ("%d", &value);
    }

    void print()
    {
        printf ("index: %d value: %d\n", index, value);
    }

    bool operator == (const number &B) const
    {
        return value == B.value;
    }
};

number numbers [1000010];
segment_tree TREE;
int NN

int binary_search(int element)
{
    int Left = 0, Right = NN - 1, pivot;
    while (Left <= Right)
    {
        pivot = (Left + Right) / 2;
        if (numbers [])
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    NN = n;
    for (int i = 0; i < n; i++)
        numbers [i].get(i);

    sort (numbers, numbers + n);

    TREE.Create(n);

    for (int i = 0; i < n; i++)
    {

    }

    TREE.Initialize(237583);

    for (int i = 0; i < n; i++)
    {

    }

    return 0;
}








