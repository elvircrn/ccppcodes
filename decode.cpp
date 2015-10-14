#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int n;

struct Node
{
    Node *left, *right;
    char value;

    Node () { left = NULL; right = NULL; value = 0; }
    Node (char _value) { value = _value; left = NULL; right = NULL; }
};

Node *root = NULL;

void parse_input ()
{
    char character, c;
    character = getchar(); getchar();

    if (root == NULL)
        root = new Node();

    Node *current = root;

    while (isdigit (c = getchar()))
    {
        if (c == '0')
        {
            if (current->left == NULL)
                current->left = new Node();
            current = current->left;
        }
        else if (c == '1')
        {
            if (current->right == NULL)
                current->right = new Node();
            current = current->right;
        }
    }

    current->value = character;
}

int main ()
{
    char c;
    scanf ("%d", &n); getchar();

    while (n--)
        parse_input();

    Node *current = root;

    cout<<current->right->value<<endl;

    /*while (isdigit (c = getchar()))
    {
        if (c == '0')
            current = current->left;
        else
            current = current->right;

        if (current->value)
        {
            putchar (root->value);
            current = root;
        }
    }*/

    return 0;
}
