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

int R_count [1200100], lengths [1200100];
int finished [1200100];
int turns_into [1200100];
bool cool [1200100];
int query_index [1200100];

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
            if (!bits.bit_at(c - 'a'))
            {
                bits.turn_on(c - 'a');
                next[c - 'a'] = new node();
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
            current_node = current_node->next [c - 'a'];
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

int metamorhposis(int index)
{
   if (finished [index] != -1)
   {
        return turns_into [index];
   }
}

vector <int> stacks;

int QMAX;

int main()
{
	cout<<"KOAKSODKASdokasdo\n";
	
    _trie = trie();

    for (int i = 0; i < 500100; i++)
        finished [i] = turns_into [i] = -1;

    scanf ("%d", &n); getchar();
    for (int i = 0; i < n; i++)
        _trie.parse_input();

    for (int i = 0; i < words.size(); i++)
        printf ("%d ", words [i]); printf ("\n");


    scanf ("%d", &m); getchar();

    for (int i = 0; i < m; i++)
    {
        int X = _trie.parse_input();
        int Y = _trie.parse_input();

        printf ("%d %d\n", X, Y);
        turns_into[X] = Y;
        cool [X] = true;

        QMAX = max (X, Y);
    }

    QMAX = max (QMAX, word_index);

    int R = 0, L = 0;

    for (int i = 0; i < words.size(); i)
    {
        if (turns_into [words [i]] == -1)
        {
            R += R_count [words [i]];
            L += lengths [words [i]];
        }
        else if (finished [words [i]])
        {
            R += R_count [words [i]];
            L += lengths [words [i]];
        }
        else
        {
            stacks.clear();
            int current_index = words [i];
            int q = i - 1;

            while (finished [current_index] != -1)
            {
                stacks.push_back(current_index);
                finished[current_index] = 1;
                current_index = turns_into [current_index];
            }
            stacks.push_back(current_index);

            int MAXR = R_count[current_index];
            int MAXL = lengths[current_index];

            for (int j = stacks.size() - 2; j > -1; j--)
            {
                if (R_count [stacks [j]] == R_count [stacks [j - 1]])
                {
                    R_count[stacks [j]] = R_count[stacks [j + 1]];
                }
            }
        }
    }

    return 0;
}


/*
7
AbRb r xR xR xR abrb abrb
*/
















































