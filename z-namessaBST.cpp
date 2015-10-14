#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string unos;
int n, lijevo = 0, desno = 0;
struct treeNode {
    treeNode *left, *right;
    string val;
    int key;
    treeNode () {key = 0; left = right = NULL;}
    treeNode (string v, int k) {val = v; left = right = NULL; key = k;}
} *root = NULL;
void addVal (string value) {
    if (root == NULL) {root = new treeNode (value, 0); return;}
    treeNode *node = new treeNode (), *past = NULL;
    node = root;
    while (node != NULL) {
        past = node;
        node->key++;
        if (value < node -> val) {
            if (node -> left) lijevo += node -> key;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    if (past -> val < value) past -> left = new treeNode (value, 0);
    else past -> right = new treeNode (value, 0);
    return;
}
int main () {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>unos;
        lijevo = desno = 0;
        addVal (unos);
        cout<<lijevo<<endl;
    }
    return 0;
}
