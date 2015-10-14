#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

const int tree_size = 400100;

char q_str [5], str [100100];
int n, t, len, q_len, beginning [100100], els, word_index [100100];

int min_tree [tree_size], ret [tree_size], max_tree [tree_size], value [100100];
bool is_word [100100], is_hit [100100], is_start [100100], inverted [tree_size], mark [tree_size];

struct element
{
    short black, white, bitmask;

    element() { black = 0; white = 0; bitmask = 0; }
    element(int offset)
    {
        black = 0;
        white = 0;
        bitmask = 0;
        for (int i = 0; i < q_len; i++)
        {
            beginning [offset + i] = offset;
            word_index [offset + i] = els;
            if (q_str [i] != str [offset + i])
            {
                black++;
                bitmask += (1<<i);
            }
            else
                white++;
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
    void build_tree(int current_node, int left, int right)
    {
        if (right - left + 1 < q_len)
        {
            max_tree [current_node] = min_tree [current_node] = ret [current_node] = -1;
            return;
        }
        else if (left == right)
        {
            max_tree [current_node] = min_tree [current_node] = ret [current_node] = (is_word [left] ? 1 : -1);
        }
        else
        {
            int pivot = (left + right) / 2;

            build_tree(LEFT(current_node), left, pivot);
            build_tree(RIGHT(current_node), pivot + 1, right);

            int max_ret = 0, min_ret = 10;

            for (int i = max (left, pivot - q_len); i <= min (right, pivot + q_len); i++)
            {
                if (is_start [i] && i + q_len - 1 <= right)
                {
                    max_ret = max (max_ret, value [i]);
                    min_ret = min (min_ret, value [i]);
                }
            }

            int max_L = max_tree [LEFT(current_node)];
            int max_R = max_tree [RIGHT(current_node)];

            int min_L = min_tree [LEFT(current_node)];
            int min_R = min_tree [RIGHT(current_node)];

            max_tree [current_node] = max (max (max_L, max_R), max_ret);
            min_tree [current_node] = min (min (min_L, min_R), min_ret);

            ret [current_node] = max_tree [current_node];
        }
    }

    void update(int current_node, int left, int right, int index)
    {
    }

    void invert(int current_node, int left, int right)
    {
    }

    void propagate(int current_node, int left, int right)
    {
    }

    int query(int current_node, int left, int right, int qleft, int qright)
    {
    }

    void update(int current_node, int left, int right, int qleft, int qright)
    {
    }
};

segment_tree st;

bool check(int index)
{
    if (index + q_len - 1 >= len)
        return false;

    for (int j = 0; j < q_len; j++)
        if (tolower (str [index + j]) != tolower (q_str [j]))
            return false;

    return true;
}

FILE *in;

int main()
{
    //freopen ("in.txt", "r", stdin);

    in = fopen ("in.txt", "r");

    while (fscanf (in, "%d %s", &t, &q_str) == 2)
    {
        memset (inverted, false, sizeof inverted);
        memset (word_index, -1, sizeof word_index);

        //scanf ("%s", &str);
        fscanf (in, "%s", &str);

        len = strlen (str);
        q_len = strlen (q_str);

        for (int i = 0; i < len; i++)
        {
            if (check (i))
            {
                int counter = 0;
                for (int j = 0; j < q_len; j++)
                {
                    is_hit [i + j] = true;
                    counter += (q_str [j] != str [i + j]);
                }

                is_start [i] = true;
                value [i] = counter;
            }
        }

        n = len - 1;

        st.build_tree(1, 0, n - 1);

        while(t--)
        {
            int a, b;
            fscanf (in, "%d %d", &a, &b);
            //scanf ("%d %d", &a, &b);

            a--;
            b--;


        }

    }

    fclose (in);


    return 0;
}






/*
3 gR
PrOgRAMmINgiSgrEAt
1 10

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










