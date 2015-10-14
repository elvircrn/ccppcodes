#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n, m, word_index;
vector <int> words;

int R_count [500100], lengths [500100];
int finished [500100];
int turns_into [500100];

struct bit
{
    int BIT;

    bit() { BIT = 0; }
    bit(int _BIT) { BIT = _BIT; }

    bool bit_at(int index)
    {
        return BIT & (1<<index);
    }

    void turn_on(int index)
    {
        if (!bit_at(index))
            BIT += (1<<index);
    }

    void turn_off(int index)
    {
        if (bit_at(index))
            BIT += (1<<index);
    }

    void flip(int index)
    {
        if (bit_at(index))
            turn_off(index);
        else
            turn_on(index);
    }
};

struct trie
{
    struct node
    {
        bit bits;
        bool word;
        node *next[29];
        int index, depth, length, r_count;

        node() { word = false; bits = bit(); index = -1; }

        void add(char c)
        {
            if (!bits.bit_at(c - '0'))
            {
                bits.turn_on(c - '0');
                next[c - '0'] = new node();
            }
        }
    };

    node *root;

    trie()
    {
        root = new node();
    }

    int parse_input()
    {
        node *current_node = root;
        char c;
        int len = 0, r = 0;

        while (isalpha(c = getchar()))
        {
            len++;
            c = tolower(c);
            r += (c == 'R' || c == 'r');
            current_node->add(c);
            current_node = current_node->next [c - '0'];
        }

        if (!current_node->word)
        {
            current_node->word = true;
            current_node->index = word_index;
            current_node->length = len;
            current_node->r_count = r;

            words.push_back(word_index);

            R_count [current_node->index] = r;
            lengths [current_node->index] = len;

            word_index++;

            return current_node->index;
        }
        else
        {
            R_count [current_node->index] = current_node->r_count;
            lengths [current_node->index] = current_node->length;

            words.push_back(current_node->index);

            return current_node->index;
        }
    }
};

trie _trie;

int main()
{
    _trie = trie();

    for (int i = 0; i < 500100; i++)
        turns_into [i] = -1;

    scanf ("%d", &n); getchar();
    for (int i = 0; i < n; i++)
        _trie.parse_input();

    for (int i = 0; i < words.size(); i++)
        printf ("%d ", words [i]); printf ("\n");

    /*for (int i = 0; i < 3; i++)
    {
        printf ("L: %d R: %d\n", lengths [i], R_count [i]);
    }*/

    /*scanf ("%d", &m); getchar();

    for (int i = 0; i < m; i++)
    {
        int X = _trie.parse_input();
        int Y = _trie.parse_input();


        printf ("%d %d", X, Y);
        turns_into[X] = Y;
    }*/



    return 0;
}


/*
5
AbRb r Zz Zz Zz
*/
















































