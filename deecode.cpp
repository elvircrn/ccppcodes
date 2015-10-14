#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int n, charsize;
struct element {
    char leftb [100], rightb [100];
    element () {}
    element (char _l[], char _r[]) {strcpy ( _l, leftb); strcpy (_r, rightb);}
    bool operator < (const element & xx) const
    {
        int DD = strcmp (rightb, xx.rightb);
        if (DD == -1) return true;
        else return false;
    }
    bool operator == (const element & xx) const
    {
        int DD = strcmp (rightb, xx.rightb);
        if (DD == 0) return true;
        else return false;
    }
};
struct treeNode {
    treeNode *left;
    treeNode *right;
    element val;
    treeNode () {left = right = NULL;}
    treeNode (element e) {val = e; left = right = NULL;}
} *root = NULL;
element elements [100];
char help [100], l [100], r [100], a;
void addNode (element e) {
    treeNode *node = root, *previous = NULL;
    if (root == NULL) {root = new treeNode (e); return;}
    while (node) {
        cout<<node->val.rightb<<endl;
        previous = node;
        if (e < node->val)
            node = node->right;
        else
            node = node->left;
    }
    if (e < previous->val) previous->left = new treeNode (e);
    else previous->right = new treeNode (e);
    return;
}
element binarysearch (element e) {
    treeNode *previous, *node = root;
    while (node) {
        if (node->val < e)
            node = node->left;
        else if (node->val == e)
            return node->val;
        else
            node = node->right;
    }
    return element ((char*)"asdasd", (char*)"asdasd");
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%s %d", &l, &r);
        elements [i] = element (l, r);
        addNode (elements [i]);
    }
    /*getchar();
    a = getchar();
    while (a != '\n') {
        help [charsize] = a;
        cout<<help<<endl;
        charsize++;
        help [charsize] = '\0';
        element find = binarysearch (element (help, "meme"));
        if (strcmp ("asdasd", find.leftb) != 0) {printf ("%s", find.leftb); charsize = 0; help [charsize] = '\0';}
        a = getchar();
    }*/
    return 0;
}















