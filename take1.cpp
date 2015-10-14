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

int n, array [1000100];

#define INF 1<<27
#define RANGE_MIN 0
#define RANGE_MAX 1
#define RANGE_SUM 2

struct number
{
    int index, value;

    number() { }
    number(int _index, int _value) { index = _index; value = _value; }

    bool operator < (const number &B) const
    {
        return value < B.value;
    }

    void get(int _index)
    {
        index = _index;
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

template <class T>
struct segment_tree
{
    vector <int> M;
    int n, tree_size;

    segment_tree() { }
    segment_tree(int N)
    {
        n = N;
        tree_size = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
        M.resize(tree_size);
    }

    void Create(int N)
    {
        n = N;
        tree_size = (int)(2 * pow (2.0, floor ((log ((double)N) / log(2.0)) + 1)));
        M.resize(tree_size);
    }

    void Initialize(int code)
    {
        initialize(code, 0, n - 1, 1);
    }

    int Query(int code, int left_range, int right_range)
    {
        return query (code, left_range, right_range, 0, n - 1, 1);
    }

    void Update(int code, int index, int value)
    {
        numbers [index].index = value;
        update(code, index, value, 0, n - 1, 1);
    }

    void update(int code, int index, int value, int left_range, int right_range, int current_node)
    {
        if (index < left_range || right_range < index)
            return;

        if (left_range == right_range)
        {
            M [current_node] = left_range;
            return;
        }

        int pivot = (left_range + right_range) / 2;

        update (code, index, value, left_range, pivot, 2 * current_node);
        update (code, index, value, pivot + 1, right_range, 2 * current_node + 1);

        T Left  = numbers [M [2 * current_node]].index;
        T Right = numbers [M [2 * current_node + 1]].index;

        if (code == RANGE_MAX)
        {
            if (Right < Left)
                M [current_node] = M [2 * current_node];
            else
                M [current_node] = M [2 * current_node + 1];
        }
        else if (code == RANGE_MIN)
        {
            if (Left < Right)
                M [current_node] = M [2 * current_node];
            else
                M [current_node] = M [2 * current_node + 1];
        }

        return;
    }

    int query(int code, int query_left, int query_right, int left_range, int right_range, int current_node)
    {
        printf ("left_range: %d right_range: %d M: %d\n", left_range, right_range, M [current_node]);
        if (right_range < query_left || query_right < left_range)
        {
            printf ("nope\n");
            return -1;
        }

        if (query_left <= left_range && right_range <= query_right)
        {
            printf ("inbound\n");
            return M [current_node];
        }

        int l = query (code, query_left, query_right, left_range, (left_range + right_range) / 2, 2 * current_node);
        int r = query (code, query_left, query_right, (left_range + right_range) / 2 + 1, right_range, 2 * current_node + 1);

        if (l == -1)
            return r;
        else if (r == -1)
            return l;

        if (code == RANGE_MAX)
        {
            if (numbers [l] < numbers [r])
                return r;
            else
                return l;
        }
        else if (code == RANGE_MIN)
        {
            if (numbers [l] < numbers [r])
                return l;
            else
                return r;
        }
    }

    void initialize(int code, int left_range, int right_range, int current_node)
    {
        if (left_range == right_range)
        {
            M [current_node] = left_range;
            return;
        }

        int pivot = (left_range + right_range) / 2;

        initialize (code, left_range, pivot, 2 * current_node);
        initialize (code, pivot + 1, right_range, 2 * current_node + 1);

        T Left  = numbers [M [2 * current_node]].index;
        T Right = numbers [M [2 * current_node + 1]].index;

        if (code == RANGE_MAX)
        {
            if (Right < Left)
                M [current_node] = M [2 * current_node];
            else
                M [current_node] = M [2 * current_node + 1];
        }
        else if (code == RANGE_MIN)
        {
            if (Left < Right)
                M [current_node] = M [2 * current_node];
            else
                M [current_node] = M [2 * current_node + 1];
        }

        return;
    }
};

segment_tree<int> tree_max, tree_min;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        numbers [i].get(i);
        array [i] = numbers [i].value;
    }

    sort (numbers, numbers + n);

    tree_max.Create(n);

    tree_min.Create(n);

    for (int i = 0; i < n; i++)
    {

    }

    return 0;
}









