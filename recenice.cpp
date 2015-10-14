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

long long int fast_pow(long long int base, long long int power)
{
    if (power == 0)
        return 1LL;
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        long long int t = fast_pow(base, power / 2);
        return t * t;
    }
    else
        return fast_pow(base, power - 1) * base;
}

int to_int(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    else if ('a' <= c && c <= 'z')
        return (c - 'a') + 26;
    else if (c == ' ')
        return 54;
    else
        return 55;
}

vector <char> shit;

struct trie
{
    struct node
    {
        node *next[56];
        bool exists;

        node() { for (int i = 0; i < 56; i++) next [i] = NULL; }

        void add(char c)
        {
            if (next[to_int(c)] == NULL)
                next[to_int(c)] = new node();
        }
    };

    trie() { root = new node(); }

    node *root;

    bool flush()
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

    bool new_sentence = true;

    long long int what = n;

    while(n--)
    {
        char c = 'a';
        do
        {
            c = getchar();

            if (isalnum(c))
                new_sentence = false;

            if (c == EOF)
                break;
            else if (c == '?')
            {
                new_sentence = true;
                //flush

                sentence_count += _trie.flush();

                shit.clear();
            }
            else if (c == '.' || c == '!')
            {
                new_sentence = true;
                shit.clear();
            }
            else if (!new_sentence)
            {
                shit.push_back(c);
            }
        } while (c != '\n');
    }

    if (sentence_count > 0)
        cout<<fast_pow(2LL, sentence_count)<<endl;
    else
        cout<<0<<endl;

    return 0;
}
/*
3
Adbs sdc? Dwds asd. Kgle?
Dvcmrkf vdekg. Kgle? Phkm
bfsmc. Kgle.
*/





























