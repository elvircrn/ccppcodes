#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define LEFT(x) 2 * (x)
#define RIGHT(x) 2 * (x) + 1

const int tree_size = 400100;

bool mark [100100];
char q_str [5], str [100100];
int n, t, len, q_len, beginning [100100], els, word_index [100100];

int min_tree [tree_size], ret [tree_size], max_tree [tree_size];
bool inverted [tree_size];

struct element
{
    short black, white, bitmask;

    element() { black = 0; white = 0; bitmask = 0; }
    element(int offset)
    {
        bitmask = 0;
        white = 0;
        black = 0;
        for (int i = 0; i < q_len; i++)
        {
            beginning [offset + i] = offset;
            word_index [offset + i] = els;
            if (q_str [i] != str [offset + i])
            {
                black++;
                bitmask += (1<<i);
            }
        }
    }

    int bit_at(int index)
    {
        return bitmask & (1<<index);
    }

    void flip_bit(int index)
    {
        if (bit_at(index))
        {
            black--;
            white++;
            bitmask -= (1<<index);
        }
        else
        {
            black++;
            white--;
            bitmask += (1<<index);
        }
    }

    void flip(int x, int y)
    {
        for (int i = x; i <= y; i++)
            flip_bit(i);
    }
};

vector <element> elements;

struct segment_tree
{
    segment_tree() { n = elements.size(); build_tree(1, 0, n - 1); }

    void build_tree(int current_node, int left, int right)
    {
        int pivot = (left + right) / 2;
        if (left == right)
        {
            max_tree [current_node] = min_tree [current_node] = elements [left].black;
            ret [current_node] = max_tree [current_node];
        }
        else if (left < right)
        {
            build_tree(LEFT(current_node), left, pivot);
            build_tree(RIGHT(current_node), pivot + 1, right);

            max_tree [current_node] = max (max_tree [LEFT(current_node)], max_tree [RIGHT(current_node)]);
            min_tree [current_node] = min (min_tree [LEFT(current_node)], min_tree [RIGHT(current_node)]);

            ret [current_node] = max_tree [current_node];
        }
    }

    void update(int node, int left, int right, int index)
    {
        /**

        if (left <= index && index <= right)
        {
            max_tree [current_node] = max (max_tree)
        }

        */
    }

    void propagate(int current_node, int left, int right)
    {
        if (left == right)
        {
            if (inverted [current_node])
                ret [current_node] = q_len - min_tree [current_node];
            else
                ret [current_node] = max_tree [current_node];
        }
        else if (left < right)
        {
            if (inverted [current_node])
            {
                ret [current_node] = q_len - min_tree [current_node];

                inverted [2 * current_node] = !inverted [2 * current_node];
                inverted [2 * current_node + 1] = !inverted [2 * current_node + 1];
            }
        }
        else
            return;


        inverted [current_node] = false;
    }

    int query(int current_node, int left, int right, int qleft, int qright)
    {
        propagate(current_node, left, right);

        if (right < qleft || qright < left || left > right)
            return 0;

        if (qleft <= left && right <= qright)
        {
            return ret [current_node];
        }

        int pivot = (left + right) / 2;

        return max (query (2 * current_node, left, pivot, qleft, qright), query (2 * current_node + 1, pivot + 1, right, qleft, qright));
    }

    void update(int current_node, int left, int right, int qleft, int qright)
    {
        if (qleft <= left && right <= qright)
            inverted [current_node];


    }

    bool bleeds(int a)
    {
        return (beginning [a] != -1 && beginning [a] <= a && a < beginning [a] + q_len);
    }

    int hit_index(int a)
    {
        return word_index [a];
    }

    int change(int a, int b)
    {
        if (!bleeds (a) && !bleeds (b))
        {
            update(1, 0, n - 1, hit_index (a) + 1, hit_index(b));
            return query(1, 0, n - 1, 0, n - 1);
        }
        else
        {
            if (bleeds(a))
            {
                for (int i = a - beginning [a]; i < q_len; i++)
                    elements [hit_index (a)].flip_bit(i);
            }

            if (bleeds(b))
            {
                for (int i = 0; i < b - beginning [b]; i++)
                    elements [hit_index (b)].flip_bit(i);
            }
        }
    }

};

segment_tree st;

int main()
{
    freopen ("in.txt", "r", stdin);

    while (scanf ("%d %s", &t, &q_str) == 2)
    {
        memset (inverted, false, sizeof inverted);
        memset (word_index, -1, sizeof word_index);
        elements.clear();
        scanf ("%s", &str);

        len = strlen (str);
        q_len = strlen (q_str);

        int hit_index = -1, start = -1;

        for (int i = 0; i < len; i++)
        {
            bool equal = true;
            beginning [i] = start;
            word_index [i] = hit_index;

            for (int j = 0; j < q_len; j++)
            {
                if (i + j == q_len || tolower (str [i + j]) != tolower (q_str [j]))
                {
                    equal = false;
                    break;
                }
            }

            if (equal)
            {
                hit_index++;
                start = i;
                for (int j = 0; j < q_len; j++)
                {
                    word_index [i + j] = hit_index;
                    beginning [i + j] = start;
                }
                elements.push_back (element (i)); els++;
            }
        }

        st = segment_tree();

        printf ("elements\n");
        for (int i = 0; i < elements.size(); i++)
            printf ("%d %d %d\n", elements [i].black, elements [i].white, elements [i].bitmask);

        printf ("\n\n\n");

        for (int i = 0; i < len; i++)
        {
            printf ("%3d", i);
        } printf ("\n");

        for (int i = 0; i < len; i++)
        {
            printf ("%3c", str [i]);
        } printf ("\n");

        for (int i = 0; i < len; i++)
        {
            printf ("%3d", beginning [i]);
        } printf ("\n");

        for (int i = 0; i < len; i++)
        {
            printf ("%3d", word_index [i]);
        } printf ("\n\n\n");

        while(t--)
        {
            int a, b;
            scanf ("%d %d", &a, &b); a--; b--;

            printf ("%d\n", st.change(a, b));
        }
    }


    return 0;
}






/*
3 gR
PrOgRAMmINgiSgrEAt
1 7
4 18
6 14
9 abCAb
aBcAbCAbaBCAb
1 13
1 13
4 8
5 11
3 11
4 10
1 13
8 8
1 13
*/








































