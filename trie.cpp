#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Node
{
    char letter;
    Node *nodes [35];

    Node()
    {
        letter = '0';
        for (int i = 0; i < 35; i++) nodes [i] = NULL;
    }
    Node(char _letter)
    {
        letter = _letter;
        for (int i = 0; i < 35; i++) nodes [i] = NULL;
    }

    void add_letter(char _letter)
    {
        nodes [_letter - 'A'] = new Node(_letter);
    }
};

struct Trie
{
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void AddWord(string word)
    {
        Node *node = root;


        //TED
        for (int i = 0; i < word.length(); i++)
        {
            if (node->nodes [word [i] - 'A'] == NULL)
            {
                node->add_letter (word [i]);
                node = node->nodes [word [i] - 'A'];
            }
            else
            {
                node = node->nodes [word [i] - 'A'];
            }
        }
    }
};

Trie trie = Trie();

int main()
{
    Node *node = new Node();

    cout<<node->nodes [0]<<endl;

    return 0;
}
