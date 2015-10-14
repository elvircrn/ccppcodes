#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define DFS_WHITE 0
#define DFS_GREY  1
#define DFS_BLACK 2

#define DEBUG

void turn_on(int &bitmask, int index)
{
    bitmask += (1<<index);
}

int get_int(char character)
{
    return character - 'a';
}

bool get_bit(int bitmask, int index)
{
    return bitmask & (1<<index);
}

string strings [30001];

vector <string> solution;
vector <char> words [30001];
bool mark [30001] [26], vis [26] [26];
int n, shade [27];
vector <int> graph [26];

struct trie
{
    struct node
    {
        int counter, bitmask, index;
        node *next [26];

        node() { index = -1; counter = 0; bitmask = 0; }

        node* add(char character)
        {
            if (!get_bit(bitmask, get_int (character)))
            {
                turn_on (bitmask, get_int (character));
                return (next [get_int (character)] = new node());
            }
            else
                return next [get_int (character)];
        }

        bool has(char character)
        {
            return get_bit(bitmask, get_int (character));
        }
    };

    trie() { root = new node(); }

    node *root;

    void add_word(int index)
    {
        node *current_node = root;

        int i = 0;

        char c;
        while (!isalpha(c = getchar()));

        do
        {
            strings [index] += c;
            current_node = current_node->add(c);
            current_node->counter++;

            if (!mark [i] [get_int (c)])
            {
                mark [i] [get_int (c)] = true;
                words [i].push_back (c);
            }

            i++;
        } while (isalpha (c = getchar()));

        current_node->index = index;
    }

    bool generate_graph(int index)
    {
        for (int i = 0; i < 26; i++)
        {
            graph [i].clear();
            for (int j = 0; j < 26; j++)
                vis [i] [j] = false;
        }
        node *current_node = root;

        for (int i = 0; i < strings [index].length(); i++)
        {


            char A = strings [index] [i];

            for (int j = 0; j < 26; j++)
            {
                char B = j + 'a';
                if (A != B && !vis [A] [B] && current_node->has(B))
                {
                    graph [get_int (A)].push_back (get_int (B));
                    vis [get_int (A)] [get_int (B)] = true;
                }
            }

            current_node = current_node->next [get_int (A)];
            if (current_node->index != -1 && current_node->index != index)
                return false;
        }

        return true;
    }
};

trie _trie;
bool global;

void cycle_check(int current_node)
{
    if (shade [current_node] == DFS_BLACK)
        return;

    if (shade [current_node] == DFS_GREY)
    {
        global = true;
        return;
    }

    shade [current_node] = DFS_GREY;

    for (int i = 0; i < (int)graph [current_node].size(); i++)
    {
        cycle_check (graph [current_node] [i]);
        if (global)
            return;
    }

    shade [current_node] = DFS_BLACK;

    return;
}

bool solve(int index)
{
    global = false;

    if (!_trie.generate_graph(index))
        return false;

    for (int i = 0; i < 26; i++)
        shade [i] = 0;

    for (int i = 0; i < 26; i++)
    {
        cycle_check (i);

        if (global)
            return false;
    }

    return true;
}

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        _trie.add_word(i);

    for (int i = 0; i < n; i++)
        if (solve (i))
            solution.push_back (strings [i]);

    printf ("%d\n", solution.size());
    for (int i = 0; i < solution.size(); i++)
        cout<<solution [i]<<endl;

    return 0;
}

/*
4
kxo
omo
omm
moo


4
omm
moo
mom
ommnom
*/





































