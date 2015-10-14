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

vector <int> new_array;
vector <int> new_tree(400000);

vector <pair <int, pair <int, int> > > my_stack;

class segment_tree
{
public:
    int n;
    vector<int>  tree;
    vector<int>  code;

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
        if (code[node])
        {
            tree[node] |= code[node];

            set_code(LEFT(node), left, (left + right) / 2, code[node]);
            set_code(RIGHT(node), (left + right) / 2 + 1, right, code[node]);

            code[node] = 0;
        }
    }

    int get(int node, int cleft, int cright, int qleft, int qright)
    {
        if (cleft > cright || cright < qleft || qright < cleft)
            return ((1<<30) - 1);

        propagate(node, cleft, cright);

        if (qleft <= cleft && cright <= qright)
            return tree[node];

        int pivot = (cleft + cright) / 2;

        return get(LEFT(node), cleft, pivot, qleft, qright) &
               get(RIGHT(node), pivot + 1, cright, qleft, qright);
    }

    int get(int node, int cleft, int cright, int index)
    {
        if(cleft > cright)
            return -1;

        propagate(node, cleft, cright);

        if (cleft == cright)
            return tree[node];
        else
        {
            int pivot = (cleft + cright) / 2;

            if (index <= pivot)
                return get(LEFT(node), cleft, pivot, index);
            else
                return get(RIGHT(node), pivot + 1, cright, index);
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

        if (!(qleft <= cleft && cright <= qright) && cleft != cright)
        {
            update(LEFT(node), cleft, pivot, qleft, qright, q);
            update(RIGHT(node), pivot + 1, cright, qleft, qright, q);

            tree[node] = tree[LEFT(node)] & tree[RIGHT(node)];
        }
    }

    void build(int node, int left, int right)
    {
        if (left == right)
            tree[node] = new_array[left];
        else
        {
            int pivot = (left + right) / 2;

            build(LEFT(node), left, pivot);
            build(RIGHT(node), pivot + 1, right);

            tree[node] = tree[LEFT(node)] & tree[RIGHT(node)];
        }
    }

    void build_stack()
    {
        my_stack.push_back(make_pair(1, make_pair(0, n - 1)));


        while(!my_stack.empty())
        {
            int node  = my_stack.back().first;
            int left  = my_stack.back().second.first;
            int right = my_stack.back().second.second;
            system ("pause");

            printf ("left: %d right: %d\n", left, right);

            if (left == right)
            {
                tree[node] = new_array[left];
                my_stack.pop_back();
            }
            else
            {
                int pivot = (left + right) / 2;

                my_stack.push_back(make_pair(LEFT(node), make_pair(left, pivot)));
                continue;
                my_stack.pop_back();
                my_stack.push_back(make_pair(RIGHT(node), make_pair(pivot + 1, right)));
                continue;
                my_stack.pop_back();
                tree[node] = tree[LEFT(node)] & tree[RIGHT(node)];
            }
        }
    }

    void build()
    {
        tree = vector<int>(400000, 0);
        code = vector<int>(400000, 0);
        build(1, 0, n - 1);
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


    for (int i = 0; i < n; i++)
        new_array.push_back(st.get(1, 0, n - 1, i));

    st.build_stack();

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first;
        int r = queries[i].second.first;
        int q = queries[i].second.second;

        if (st.get(1, 0, n - 1, l, r) != q)
        {
            printf ("NO\n");
            return 0;
        }
    }

    printf ("YES\n");
    printf ("%d", new_array[0]);
    for (int i = 1; i < new_array.size(); i++)
        printf (" %d", new_array[i]);

    return 0;
}
/*
10 10
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
8 8 8
9 9 9
10 10 10
*/
