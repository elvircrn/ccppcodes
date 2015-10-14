#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;



class trie
{
public:
    struct node
    {
        node *next[30];
        int value;

        node()
        {
            for (int i = 0; i < 30; i++)
                next [i] = NULL;
            value = 0;
        }
    };

    node *root;

    trie()
    {
        root = new node();
    }

    void add_word(const char *word)
    {
        node *current_node = root;

        int len = strlen (word);
        for (int i = 0; i < len; i++)
        {
            char character = word [i] - 'a';
            if (current_node->next [character] == NULL)
            {
                current_node->next [character] = new node();
                current_node = current_node->next [character];
            }
            else
                current_node = current_node->next [character];
        }

        current_node->value = 10;
    }

    int find_value(const char *word)
    {
        node *current_node = root;
        int len = strlen (word);

        for (int i = 0; i < len; i++)
        {
            char character = word [i] - 'a';
            if (current_node->next [character] == NULL)
                return -1;
            else
                current_node = current_node->next [character];
        }

        return current_node->value;
    }
};

trie t;

int n, m;

int main()
{
    scanf ("%d %d", &n, &m);


    return 0;
}




