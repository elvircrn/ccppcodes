#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <cmath>
#include <cctype>

using namespace std;

int to_int(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    else if ('a' <= c && c <= 'z')
        return (c - 'a') + 26;
    else
        return 53;
}

vector <char> shit;

struct trie
{
    struct node
    {
        node *next[54];
        bool init, exists;

        node() { }
        node(bool a) { init = true; }

        void add(char c)
        {
            if (next[to_int(c)]->init == false)
                next[to_int(c)] = new node(true);
        }
    };

    trie() { root = new node(); }

    node *root;

    int flush()
    {
        node *current_node = root;
        for (int i = 0; i < shit.size(); i++)
        {
            current_node->add(shit[i]);
            current_node = current_node->next[to_int(shit[i])];
        }

        if (current_node->exists == false)
        {
            current_node->exists = true;
            return 1;
        }
        else
            return 0;
    }
};

int n;
trie _trie;


long long int sentence_count;

int main()
{
    freopen ("input.txt", "r", stdin);
    scanf ("%d", &n); getchar();

    bool new_sentence = false;

    while(n--)
    {
        char c = 0;
        do
        {
            c = getchar();

            if (c == EOF)
                break;
            else if (!isalnum(c) && new_sentence)
                continue;
            else if (c == '?')
            {
                new_sentence = true;
                //flush

                printf ("SHIT:\n");
                for (int i = 0; i < shit.size(); i++)
                    putchar (shit[i]); putchar('\n');

                sentence_count += _trie.flush();

                shit.clear();
            }
            else if (c == '.' || c == '!')
            {
                new_sentence = true;
            }
            else if (c != '\n')
            {
                shit.push_back(c);
            }
        } while (c != '\n');


        if (c == EOF)
            break;
    }

    printf ("sentence_count: %d\n", sentence_count);

    return 0;
}
/*
3
Adbs sdc? Dwds asd. Kgle?
Dvcmrkf vdekg. Kgle? Phkm
bfsmc. Kgle.
*/





























