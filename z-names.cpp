#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;
int n;
string unos, prvi;
char a;
struct treenode {
    treenode *left, *right;
    int bonus;
    string value;
    treenode () {left = right = NULL; bonus = 0;}
    treenode (string v, int b) {value = v; left = right = NULL; bonus += b;}
} *root = NULL;
void add (string val) {
    treenode *past = new treenode(), *current = root;
    if (!current) {root = new treenode (val, 1); return;}
    while (current) {
        past = current;
        if (val < past->value) {
            current = current->left;
        }
        else if (val > past->value) {
            current = current->right;
        }
        else if (val == past->value) {
            current->bonus++;
            return;
        }
    }
    if (val < past->value) {
        past->left = new treenode (val, 1);
    }
    else if (val > past->value) {
        past->right = new treenode (val, 1);
    }
    else if (val == past->value) {
        return;
    }
    return;
}
