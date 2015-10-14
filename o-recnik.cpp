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
int cnt = 0;
bool found = 0;
int dfs (treenode *node, string val) {
    if (!node) return 0;
    if (node->value < val) {cnt++;}
    if (node->value == val) found = true;
    if (node->right) dfs (node->right, val);
    if (node->left) dfs (node->left, val);
}
int main () {
    //freopen ("reci.txt", "r", stdin);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        cin>>prvi>>unos;
        int len = unos.length();
        for (int j = 0; j < len; j++) {
            char c = tolower (unos [j]);
            unos [j] = (char) c;
        }
        if (prvi [0] == 'A') add (unos);
        else {found = 0; cnt = 0; dfs (root, unos); if (found) cout<<cnt<<endl; else printf ("no such word\n");}
    }
    return 0;
}
