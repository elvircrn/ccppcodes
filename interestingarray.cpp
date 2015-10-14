#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

#define LEFT(x) 2 * (x)
#define RIGHT(x) 2 * (x) + 1

class segment_tree
{
public:
    int n;
    vector<int> tree;
    vector<int> code;

    segment_tree() { }
    segment_tree(int _n)
    {
        n = _n;
        tree = vector<int>(400000);
        code = vector<int>(400000);
    }

    void set_code(int node, int left, int right, int q)
    {
        if (left <= right)
            code[node] |= q;
    }

    void propagate(int node, int left, int right)
    {
        if (left <= right && code[node])
        {
            tree[node] |= code[node];

            set_code(LEFT(node), left, (left + right) / 2, code[node]);
            set_code(RIGHT(node), (left + right) / 2 + 1, right, code[node]);

            code[node] = 0;
        }
    }

    int get(int node, int cleft, int cright, int pos)
    {
        propagate(node, cleft, cright);

        if (cleft == cright)
            return tree[node];
        else if (cleft <= pos && pos <= cright)
        {
            int pivot = (cleft + cright) / 2;
            if (pos <= pivot)
                return get(LEFT(node), cleft, pivot, pos);
            else
                return get(RIGHT(node), pivot + 1, cright, pos);
        }
    }

    int get(int node, int cleft, int cright, int qleft, int qright)
    {
        propagate(node, cleft, cright);
        if (cleft > cright)
            return (1<<30) - 1;
        else if (cleft <= qleft && qright <= cright)
            return tree[node];
        else
        {
            int pivot = (cleft + cright) / 2;
            return get(2 * node, cleft, pivot, qleft, qright) &
                   get(2 * node + 1, pivot + 1, cright, qleft, qright);
        }
    }

    void update(int node, int cleft, int cright, int qleft, int qright, int q)
    {
        if (cleft > cright || cright < qleft || qright < cleft)
            return;

        if (qleft <= cleft && cright <= qright)
            set_code(node, cleft, cright, q);

        propagate(node, cleft, cright);

        int pivot = (cleft + cright) / 2;

        if (!(qleft <= cleft && cright <= qright) && cleft < cright)
        {
            update(LEFT(node), cleft, pivot, qleft, qright, q);
            update(RIGHT(node), pivot + 1, cright, qleft, qright, q);

            tree[node] = tree[LEFT(node)] & tree[RIGHT(node)];
        }
    }
};

segment_tree st;
int solution[100100];
vector <pair<int, pair <int, int> > > queries;

int main()
{
    int n, m;
    scanf ("%d %d", &n, &m);

    for (int i = 0; i < 30; i++)
        st = segment_tree(n);

    while(m--)
    {
        int l, r, q;
        scanf ("%d %d %d", &l, &r, &q);
        l--; r--;

        st.update(1, 0, n - 1, l, r, q);

        queries.push_back(make_pair(l, make_pair(r, q)));

        int power = 1, number = 0;
    }


    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first;
        int r = queries[i].second.first;
        int q = queries[i].second.second;

        if (st.get(1, 0, n - 1, l, r) != q)
        {
            printf ("ASD: %d\n", st.get(1, 0, n - 1, l, r));
            printf ("NO\n");
            return 0;
        }
    }

    printf ("YES\n");
    printf ("%d", st.get(1, 0, n - 1, 0));
    for (int i = 1; i < n; i++)
        printf (" %d", st.get(1, 0, n - 1, i));
    printf("\n");

    return 0;
}
/*
10 3
2 5 1
1 2 2
4 7 2

10 2
2 5 1
1 2 2
*/









































