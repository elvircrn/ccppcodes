#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define line contacts [contact_index]

char input[50], contacts[100100] [50];
int n, m;

int convert(char c) {
    c = tolower(c);
    if (c >= 'a' && c <= 'c')
        return 2;
    else if (c >= 'd' && c <= 'f')
        return 3;
    else if (c >= 'g' && c <= 'i')
        return 4;
    else if (c >= 'j' && c <= 'l')
        return 5;
    else if (c >= 'm' && c <= 'o')
        return 6;
    else if (c >= 'p' && c <= 's')
        return 7;
    else if (c >= 't' && c <= 'v')
        return 8;
    else if (c >= 'w' && c <= 'z')
        return 9;
    else
        return 1;
}

int line_len;

class trie
{
public:

    struct node
    {
        node *next [11];
        vector <int> values;

        node()
        {
            for (int i = 0; i < 10; i++)
                next [i] = NULL;
        }

        void print()
        {
            for (int i = 0; i < values.size(); i++)
                printf ("%s", contacts [values [i]]);
        }

        void add(int value)
        {
            if (values.empty() || values [values.size() - 1] != value)
                values.push_back(value);
        }
    };

    node *root;

    trie() { root = new node(); }

    void parse(int contact_index)
    {
        int counter(0);

        node *current_node = root;

        int i(0);

        for (;; i++)
        {
            line [i] = getchar();
            if (line [i] == '\n' || line [i] == EOF)
                break;

            if (line [i] == ' ')
            {
                current_node = root;
                counter = 0;
            }
            else
            {
                counter++;
                if (counter > 11)
                    continue;

                if (current_node->next [convert (line [i])] == NULL)
                    current_node->next [convert (line [i])] = new node();

                current_node = current_node->next [convert (line [i])];

                current_node->add (contact_index);
            }
        }
    }

    void get_index(const char *key)
    {
        int len = strlen(key);
        node *current_node = root;

        for (int i = 0; i < len; i++)
        {
            if (current_node->next [key [i] - '0'] != NULL)
                current_node = current_node->next [key [i] - '0'];
            else
                return;
        }

        current_node->print();

        return;
    }

    void out()
    {
        node *current_node = root;
        bool not_found(false);
        char c;

        while (isdigit (c = getchar()))
        {
            putchar (c);
            if (current_node->next [c - '0'] != NULL)
                current_node = current_node->next [c - '0'];
            else
                not_found = true;
        }

        printf (":\n");

        if (not_found)
            return;

        current_node->print();
    }
};

trie _trie;
int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);

    scanf ("%d %d", &n, &m); getchar();
    for (int i = 0; i < n; i++)
    {
        //fgets(contacts[i], 300, stdin);
        _trie.parse(i);
    }

    for (int i = 0; i < m; i++)
        _trie.out();

    return 0;
}

/*
4 5
099/123-456 Imenko Prezimenko
098/000-001 Mujo Suljic
097/000-001 Stjepan Ivic
096/000-001 Nenad Neno Dragic
*/


















