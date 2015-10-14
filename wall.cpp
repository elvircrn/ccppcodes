#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#define SIZE 2000000
#define ADD        1
#define REMOVE     2
#define SET        3

#define LEFT(x) 2 * (x)
#define RIGHT(x) 2 * (x) + 1

class segment_tree
{
public:

    int n;
    vector<int> tree;
    vector<int> code;
    vector<int> code_value;

    segment_tree() { }

    void make(int _n)
    {
        n = _n;
        tree.resize(4 * n);
        code.resize(4 * n);
        code_value.resize(4 * n);
    }

    void set_code(int node, int c, int value)
    {
        //printf("    set node: %d c: %d value: %d\n", node, c, value);
        if (c == ADD)
        {
            if (code_value[node] < value)
            {
                code[node] = SET;
                code_value[node] = value;
            }
        }
        else if (c == REMOVE)
        {
            if (code_value[node] > value)
            {
                code_value[node] = value;
                code[node] = SET;
            }
        }
        else if (c == SET)
            code_value[node] = value;
    }

    void propagate(int node, int left, int right)
    {
        //printf("    prop: %d left: %d right: %d\n", node, left, right);
        if (code[node] == SET)
        {
            tree[node] = (right - left + 1) * code_value[node];

            if (left < right)
            {
                set_code(LEFT(node), SET, code_value[node]);
                set_code(RIGHT(node), SET, code_value[node]);
            }

            code_value[node] = 0;
            code[node] = 0;
        }
    }

    void add(int l, int r, int h)
    {
        update(1, 0, n - 1, l, r, ADD, h);
    }

    void remove(int l, int r, int h)
    {
        update(1, 0, n - 1, l, r, REMOVE, h);
    }

    void update(int node, int cleft, int cright, int qleft, int qright, int code, int value)
    {
        //printf("node: %d left: %d right: %d\n", node, cleft, cright);

        if (qleft <= cleft && cright <= qright)
        {
            printf("set node: %d left: %d right: %d\n", node, cleft, cright);
            set_code(node, code, value);
        }

        propagate(node, cleft, cright);

        //system("pause");

        if (cleft == cright)
            return;

        if (!(qleft <= cleft && cright <= qright))
        {
            int pivot = (cleft + cright) / 2;

            update(LEFT(node), cleft, pivot, qleft, qright, code, value);
            update(RIGHT(node), pivot + 1, cright, qleft, qright, code, value);

            tree[node] = tree[LEFT(node)] + tree[RIGHT(node)];
        }

        return;
    }

    int get(int node, int index, int left, int right)
    {
        propagate(node, left, right);

        if (left == index && index == right)
            return tree[node];

        int pivot = (left + right) / 2;

        if (index <= pivot)
            return get(LEFT(node), index, left, pivot);
        else
            return get(RIGHT(node), index, pivot + 1, right);
    }

    int print_shape()
    {
        for (int i = 0; i < n; i++)
            printf("%d\n", get(1, i, 0, n - 1));
    }
};

segment_tree st;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    st.make(n);

    while(k--)
    {
        int op, l, r, h;
        scanf("%d %d %d %d", &op, &l, &r, &h);
        l--;
        r--;
        if (op == 1)
            st.add(l, r, h);
        else
            st.remove(l, r, h);
    }

    st.print_shape();

    return 0;
}
#define EPS 1e-10


bool same(float a, float b)
{
    return fabs(a - b) < EPS;
}







