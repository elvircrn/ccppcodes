#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int go_back [3100000], start_index [310000], lens [210000], visited [200010], dot_count [200010], q_len, m, RA [200010], SA [200010], pos [200010], n, power, len, global = 1;
char Q [200010], S [900010];

vector <int> SOLUTION;

bool cmp (int A, int B)
{
    if (pos [A] != pos [B])
        return pos [A] < pos [B];
    else if (A + power >= len || B + power >= len)
        return A > B;
    else
        return pos [A + power] < pos [B + power];
}

bool compare2(int A, int B)
{
    if (lens [dot_count [A]] != lens [dot_count [B]])
        return lens [dot_count [A]] < lens [dot_count [B]];

    return SA [start_index [A]] < SA [start_index [B]];
}

vector<int> range [6000000];

//dot_count [SA [i]]

void merge(int node_index, int left_node, int right_node)
{
    int left_index(0), right_index(0);

    while ((left_index < range [left_node].size() || right_index < range [right_node].size()) && range [node_index].size() < 10)
    {
        if (compare2 (range [left_node] [left_index], range [right_node] [right_index]))
        {
            range [node_index].push_back (range [left_node] [left_index]);
            left_index++;
        }
        else
        {
            if (range [node_index] [current_index] != range [left_node] [left_index])
                range [node_index].push_back (range [left_node] [left_index]);
            right_index++;
        }
    }

    return;
}

class SegmentTree
{
public:

    int Query(int b, int e)
    {
        return query(b, e, 0, n - 1, 1);
    }

    int query(int leftQ, int rightQ, int b, int e, int node)
    {
        if (b == e)
            return b;
        else if (e < leftQ || rightQ < b || b > e)
            return -1;
        else if (leftQ <= b && e <= rightQ)
            return range [node];

        int left_range  = query(leftQ, rightQ, b, (b + e) / 2, 2 * node);
        int right_range = query(leftQ, rightQ, (b + e) / 2 + 1, e, 2 * node + 1);

        //dot_product [SA [i]]

        if (left_range == -1)
            return right_range;
        else
            return left_range;

        if (compare2 (dot_count [SA [left_range]], dot_count [SA [right_range]]))
            return range [node] = left_range;
        else
            return range [node] = right_range;
    }

    void BuilSegmentTree()
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
        int right_range = buildSegmentTree((b + e) / 2, e, 2 * node + 1);

        if (left_range == -1)
            return range [node] = right_range;
        else
            return range [node] = left_range;

        if (compare2 (SA [left_range], SA [right_range]))
            return range [node] = left_range;
        else
            return range [node] = right_range;
    }
};

SegmentTree segment_tree;

int main()
{
    freopen ("in.txt", "r", stdin);

    char c;
    scanf ("%d", &n);
    while (!isalpha (c = getchar()));
    S [0] = c;
    pos [0] = c;
    dot_count [0] = 1;
    lens [1] = 1;
    start_index [0] = 0;

    int word_index = 1;

    bool pass = false;

    for (int i = 0; i < n; i++)
    {
        start_index [global - 1] = i;
        if (i != 0)
            lens [i + 1] = 1;
        while (true)
        {
            if (!pass)
            {
                if (!isalpha (c = getchar()))
                    break;
            }

            start_index [global - 1] = i;

            S [global]   = c;
            SA [global]  = global;
            pos [global] = c;
            lens [i + 1]++;
            dot_count [global] = i + 1;
            global++;

            word_index++;

            pass = false;
        }

        word_index = 0;

        S [global] = '.';
        pos [global] = '.';
        dot_count [global] = i + 1;
        SA [global] = global;
        global++;


        if (i == n - 1)
            break;

        while (!isalpha (c = getchar()));
        pass = true;
    }

    start_index [1] = 0;

    //for (int i = 1; i <= n; i++)
    //    printf ("start_index: %d\n", start_index [i]);

    len = global;

    for (power = 1; power <= len; power *= 2)
    {
        sort (SA, SA + len, cmp);

        for (int i = 0; i < len - 1; i++)
            RA [i + 1] = RA [i] + cmp (SA [i], SA [i + 1]);
        for (int i = 0; i < len; i++)
            pos [SA [i]] = RA [i];
    }

    int left_start = 0;

    //for (int i = 0; i < len; i++)
    //    printf ("%s\n", S + SA [i]);

    scanf ("%d", &m);

    int test_id = 1;

    //segment_tree.BuilSegmentTree();

    printf ("len: %d\n", len);

    printf ("S: %s\n", S);

    for (int i = 0; i < len; i++)
        printf ("%3d", i); printf ("\n");
    for (int i = 0; i < len; i++)
        printf ("%3c", S [i]); printf ("\n");

    printf ("%d\n", compare2 (5, 8));

    for (int i = 0; i < len; i++)
    {
        printf ("%-20s dot_count [%2d]: %d\n", S + SA [i], SA [i], dot_count [SA [i]]);
    }

    /*while (m--)
    {
        SOLUTION.clear();

        scanf ("%s", &Q);
        q_len = strlen (Q);

        int pivot, left = n - 1, top_index = -1, bottom_index = -1, right = len - 1;

        while (left <= right)
        {
            pivot = (left + right) / 2;

            int comp = strncmp (Q, S + SA [pivot], q_len);

            if (comp <= 0)
                right = pivot - 1;
            else
                left = pivot + 1;

            if (comp == 0)
                top_index = pivot;
        }

        left  = n - 1;
        right = len - 1;

        while (left <= right)
        {
            pivot = (left + right) / 2;

            int comp = strncmp (Q, S + SA [pivot], q_len);

            if (comp >= 0)
                left = pivot + 1;
            else
                right = pivot - 1;

            if (comp == 0)
                bottom_index = pivot;
        }

        if (top_index == -1 || bottom_index == -1)
        {
            printf ("-1\n");
            continue;
        }

        for (int i = 0; i < SOLUTION.size() && i < 10; i++)
            printf ("%d ",  SOLUTION [i]); printf ("\n");

        test_id++;
    }*/

    return 0;
}
/*
17
acm
icpc
regional
asia
jakarta
two
thousand
and
nine
arranged
by
universitas
bina
nusantara
especially
for
you
5
a
an
win
b
z


*/




