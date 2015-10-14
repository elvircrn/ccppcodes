#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const char offset = 'A';
int solution, name_index;

class trie
{
public:
    struct node
    {
        node *next [59];
        int value;

        node() { for (int i = 0; i < 59; i++) next [i] = NULL; value = -1; }

        node* proceed(char character)
        {
            if (next [character - offset] != NULL)
                return next [character - offset];
            else if (next [character - offset] == NULL)
                return (next [character - offset] = new node());
        }
    };

    node *root;

    trie() { root = new node(); root->value = -1; }

    int parse_word(const char *word)
    {
        node *prev = root, *current_node = root;

        int len = strlen (word);

        for (int i = 0; i < len; i++)
            current_node = current_node->proceed(word [i]);

        if (current_node->value == -1)
        {
            current_node->value = name_index;
            name_index++;
        }

        return current_node->value;
    }

    int check_word(const char *name)
    {
        int len = strlen (name);

        node *prev = root, *current_node = root;

        for (int i = 0; i < len; i++)
        {
            prev = current_node;
            current_node = current_node->next [name [i] - offset];
        }

        return current_node->value;
    }
};

int parent [210], v, dp [211] [3];
vector <int> graph [210];
bool uq;
int take [211] [3];
trie _trie;

int solve(int current_index, bool prev_taken)
{
    if (graph [current_index].size() == 0)
        return !prev_taken;

    if (dp [current_index] [prev_taken] != -1)
        return dp [current_index] [prev_taken];

    int count_all = 0, to_take = 0, to_discard = 0, sol = 0;

    for (int i = 0; i < graph [current_index].size(); i++)
    {
        if (!prev_taken)
            to_take += solve (graph [current_index] [i], 1);
        to_discard += solve (graph [current_index] [i], 0);
    }

    if (prev_taken)
        return dp [current_index] [prev_taken] = to_discard;
    else
    {
        if (to_take + 1 > to_discard)
        {
            take [current_index] [prev_taken] = true;
            return dp [current_index] [prev_taken] = max (to_take + 1, to_discard);
        }
        else
        {
            take [current_index] [prev_taken] = false;
            return dp [current_index] [prev_taken] = max (to_take + 1, to_discard);
        }
    }
}

bool check(int current_index)
{
    printf ("dp [%d] [0]: %d dp [%d] [1]: %d\n", current_index, dp [current_index] [0], current_index, dp [current_index] [1]);

    if (dp [current_index] [0] == solution && dp [current_index] [1] == solution)
    {
        printf ("0: %d 1: %d", dp [current_index] [0], dp [current_index] [1]);
        return true;
    }
    for (int i = 0; i < graph [current_index].size(); i++)
        if (check (graph [current_index] [i]))
            return true;

    return false;
}

int main()
{
    char buffer [600];

    freopen ("in.txt", "r", stdin);

    while (scanf ("%d", &v) == 1 && v)
    {
        scanf ("%s", &buffer);
        _trie = trie();
        _trie.parse_word(buffer);

        for (int i = 0; i <= v + 2; i++)
            graph [i].clear();

        uq = false;
        name_index = 1;

        memset (dp, -1, sizeof dp);

        for (int i = 0; i < v - 1; i++)
        {
            scanf ("%s", &buffer);
            int a = _trie.parse_word(buffer);
            scanf ("%s", &buffer);
            int b = _trie.parse_word(buffer);

            graph [b].push_back (a);
        }

        solution = -123;

        dp [0] [1] = -123;

        solution = solve (0, 0);

        printf ("%d %s\n", solution, check (0) ? "Yes" : "No");
    }

    return 0;
}


//A -> B -> C

/*
B = 40
N = 10

if (B - N * 10 >= 0)
{
    N--;
}

N = 10

FOR i =

55


printf ("%d\n", B);
*/


























