#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define RANGE_MIN 0
#define RANGE_MAX 1

//#define DEBUG

int solution, n, values [1001000], M1 [2098152], M2 [2098152];

class segment_tree
{
public:

    segment_tree() { }

    void Initialize()
    {
        initialize(0, n - 1, 1);
    }

    int Query(int code, int left_bound, int right_bound)
    {
        query(code, left_bound, right_bound, 0, n - 1, 1);
    }

private:

    int query(int code, int left_bound, int right_bound, int current_left, int current_right, int node)
    {
        //printf ("current_left: %d current_right: %d\n", current_left, current_right);
        if (current_right < left_bound || current_left > right_bound)
            return -1;

        if (left_bound <= current_left && current_right <= right_bound)
        {
            if (code == RANGE_MIN)
                return M1 [node];
            else
                return M2 [node];
        }

        int pivot = (current_left + current_right) / 2;

        int l = query(code, left_bound, right_bound, current_left, pivot, 2 * node);
        int r = query(code, left_bound, right_bound, pivot + 1, current_right, 2 * node + 1);

        if (l == -1)
            return r;
        if (r == -1)
            return l;

        if (code == RANGE_MIN)
        {
            if (values [l] < values [r])
                return l;
            else
                return r;
        }
        else if (code == RANGE_MAX)
        {
            if (values [l] < values [r])
                return r;
            else
                return l;
        }
    }

    void initialize(int left_bound, int right_bound, int node)
    {
        if (left_bound == right_bound)
        {
            M1 [node] = left_bound;
            M2 [node] = left_bound;

            return;
        }

        initialize(left_bound, (left_bound + right_bound) / 2, 2 * node);
        initialize((left_bound + right_bound) / 2 + 1, right_bound, 2 * node + 1);

        int Left1  = values [M1 [2 * node]];
        int Right1 = values [M1 [2 * node + 1]];

        int Left2  = values [M2 [2 * node]];
        int Right2 = values [M2 [2 * node + 1]];

        if (Left1 < Right1)
            M1 [node] = M1 [2 * node];
        else
            M1 [node] = M1 [2 * node + 1];

        if (Left2 < Right2)
            M2 [node] = M2 [2 * node + 1];
        else
            M2 [node] = M2 [2 * node];

        return;
    }
};

segment_tree st;

void binary_search(int index)
{
    int prev_pick, min_segment, max_segment, max_pivot = 0, pivot, Left = index, Right = n - 1;

    while (Left <= Right)
    {
        #ifdef DEBUG
        printf ("   Left: %d Right: %d\n", Left, Right);
        #endif

        pivot = (Left + Right) / 2;

        if (prev_pick == -1)
            min_segment = values [st.Query(RANGE_MIN, index, pivot)];
        else
        {
            min_segment = min (values [prev_pick], values [st.Query(RANGE_MIN, prev_pick + 1, pivot)]);
        }
        #ifdef DEBUG
        printf ("   min_segment: %d\n", min_segment);
        #endif

        if (values [index] <= min_segment)
        {
            max_pivot = max (pivot, max_pivot);
            Left = pivot + 1;
            prev_pick = min_segment;
        }
        else
        {
            Right = pivot - 1;
            prev_pick = -1;
        }
    }

    int max_ind = st.Query(RANGE_MAX, index, max_pivot);
    //int max_ind = 0;
    if (values [index] > values [max_ind])
        return;
    else
        solution = max (solution, (max_ind - index) + 1);

    return;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &values [i]);

    #ifdef DEBUG
    for (int i = 0; i < n; i++)
        printf ("values [%d]: %d\n", i, values [i]);
    #endif

    st.Initialize();

    for (int i = 0; i < n; i++)
    {
        //if ((n - 1) - i + 1 < solution)
        //    break;
        #ifdef DEBUG
        printf ("current_index: %d\n", i);
        #endif
        binary_search (i);
    }

    printf ("%d\n", solution);

    return 0;
}












