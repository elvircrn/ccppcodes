#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n;

int sign [4 * 1024000], tree [4 * 1024000];
int values [1024000];

struct segment_tree
{
    segment_tree() { build_tree(1, 0, n - 1); }

    void build_tree(int current_node, int left, int right)
    {
        if (left == right)
        {
            sign [current_node] = 'N';
            tree [current_node] = values [left];
            return;
        }
        if (left > right)
            return;

        sign [current_node] = 'N';

        int pivot = (left + right) / 2;

        build_tree(2 * current_node, left, pivot);
        build_tree(2 * current_node + 1, pivot + 1, right);

        tree [current_node] = tree [2 * current_node] + tree [2 * current_node + 1];
    }

    void propagate(int current_node, int left, int right)
    {
        if (sign [current_node] == 'F')
            tree [current_node] = right - left + 1;
        else if (sign [current_node] == 'E')
            tree [current_node] = 0;
        else if (sign [current_node] == 'I')
            tree [current_node] = (right - left + 1) - tree [current_node];

        if (left < right)
        {
            int pivot = (left + right) / 2;
            set_node(2 * current_node, sign [current_node]);
            set_node(2 * current_node + 1, sign [current_node]);
        }

        sign [current_node] = 'N';
    }

    int query(int current_node, int left, int right, int qleft, int qright)
    {
        propagate(current_node, left, right);
        if (right < qleft || qright < left || left > right)
            return 0;

        if (qleft <= left && right <= qright)
            return tree [current_node];

        int pivot = (left + right) / 2;

        return query(2 * current_node, left, pivot, qleft, qright) + query(2 * current_node + 1, pivot + 1, right, qleft, qright);
    }

    void set_node(int current_node, char new_command)
    {
        char current_command = sign [current_node];
        if (current_command == 'N' || new_command == 'F' || new_command == 'E')
            sign [current_node] = new_command;
        else if (new_command == 'I')
        {
            if (current_command == 'F')
                sign [current_node] = 'E';
            if (current_command == 'E')
                sign [current_node] = 'F';
            else if (current_command == 'I')
                sign [current_node] = 'N';
        }
    }


    void update(int current_node, int left, int right, int qleft, int qright, char command)
    {
        int pivot = (left + right) / 2;

        if (qleft <= left && right <= qright)
            set_node(current_node, command);

        propagate(current_node, left, right);

        if (right < qleft || qright < left)
            return;
        else if (!(qleft <= left && right <= qright))
        {
            update(2 * current_node, left, pivot, qleft, qright, command);
            update(2 * current_node + 1, pivot + 1, right, qleft, qright, command);

            tree [current_node] = tree [2 * current_node] + tree [2 * current_node + 1];
        }

        return;
    }

    //turn on
    void Fmutate(int a, int b)
    {
        update(1, 0, n - 1, a, b, 'F');
    }

    //turn off
    void Emumtate(int a, int b)
    {
        update(1, 0, n - 1, a, b, 'E');
    }

    void Inverse(int a, int b)
    {
        update(1, 0, n - 1, a, b, 'I');
    }

    int Sum(int a, int b)
    {
        return query(1, 0, n - 1, a, b);
    }
};


segment_tree st;

int main()
{
    char str [101];
    int t, m, q;
    scanf ("%d", &t);

    for (int case_id = 1; case_id <= t; case_id++)
    {
        printf ("Case %d:\n", case_id);

        scanf ("%d", &m);

        int current_pointer = 0, query_id = 0;

        //Input
        for (int i = 0; i < m; i++)
        {
            int T;
            scanf ("%d", &T);

            scanf ("%s", &str);
            int len = strlen (str);

            for (int j = 0; j < T; j++)
            {
                for (int k = 0; k < len; k++)
                {
                    values [current_pointer] = str [k] - '0';
                    current_pointer++;
                }
            }
        }

        n = current_pointer;

        segment_tree st = segment_tree();

        char query;
        int a, b;

        scanf ("%d", &q);
        while (q--)
        {
            cin>>query; scanf ("%d %d", &a, &b);
            if (query == 'F')
                st.Fmutate(a, b);
            else if (query == 'E')
                st.Emumtate(a, b);
            else if (query == 'I')
                st.Inverse(a, b);
            else
                printf ("Q%d: %d\n", ++query_id, st.Sum(a, b));
        }
    }


    return 0;
}

/*

2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8
*/










































