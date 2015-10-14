#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int array [10000], n;

#define INF 1<<27
#define RANGE_MIN 0
#define RANGE_MAX 1

struct segment_tree
{
    vector <int> M;

    int init(int N)
    {
        int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
        M.resize(length, 0);
        return length;
    }

    int build(int code, int node, int b, int e)
    {
        if (b == e)
            M [node] = b;
        else
        {
            build(code, 2 * node, b, (b + e) / 2);
            build(code, 2 * node + 1, (b + e) / 2 + 1, e);

            if (code == RANGE_MIN)
            {
                if (array [M [2 * node]] <= array [M[2 * node + 1]])
                    M [node] = M [2 * node];
                else
                    M [node] = M [2 * node + 1];
            }
            else if (code == RANGE_MAX)
            {
                if (array [M [2 * node]] >= array [M[2 * node + 1]])
                    M [node] = M [2 * node];
                else
                    M [node] = M [2 * node + 1];
            }
        }
    }

    int query(int code, int node, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return -1;

        if (b >= i && e <= j)
            return M[node];

        int p1 = query (code, 2 * node, b, (b + e) / 2, i, j);
        int p2 = query (code, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

        if (p1 == -1)
            return p2;
        else if (p2 == -1)
            return p1;

        if (code == RANGE_MIN)
            return min (p1, p2);
        else if (code == RANGE_MAX)
            return max (p1, p2);
        else
            return -1;
    }
};

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    segment_tree st;

    st.init (16);
    st.build (RANGE_MAX, 1, 0, 9);

    printf ("%d\n", st.query(RANGE_MAX, 1, 0, 9, 0, 9));

    return 0;
}
/*
10
2 4 3 1 6 7 8 9 1 7
*/












