#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <class key, class val> class BST {

    public:

    class node {

        public:

        node *left, *right, *prev;
        val Val;
        key Key;

        node () {}
        node (key KEY, val VAL) {Key = KEY; Val = VAL; left = right = prev = NULL;}
    };

    node *root;

    BST () {root = NULL;}

    void Add (key Key, val Val) {

        if (root == NULL) {
            root = new node (Key, Val);
            return;
        }

        node *current = root, *previous;

        while (current) {

            previous = current;

            if (current->Val == Val) {
                puts ("The value already exists.");
                return;
            }
            else if (current->Key == Key) {
                current->Val = Val;
                return;
            }

            else if (current->Key > Key)
                current = current->left;
            else if (current->Key < Key)
                current = current->right;
        }

        if (previous->Key > Key)
            previous->left = new node (Key, Val);
        else
            previous->right = new node (Key, Val);

        return;
    }

    void traverse (node *current) {

        if (current == NULL)
            return;

        traverse (current->left);
        traverse (current->right);

    }

};

BST <int, int> bst;
myArray <int> A (10);

int main () {



    return 0;
}
