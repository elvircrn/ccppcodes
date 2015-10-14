#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
bool l, r;
int n, m, indleft, indright;
char rijeci [1001] [100], unos [100];
bool checkleft (char a [], char b []) {
    if (strlen (a) <= strlen (b)) return 0;
    else
        for (int i = 0; i < strlen (b); i++)
            if (a [i] != b [i])
                return 0;
    return 1;
}
bool checkright (char a [], char b []) {
    if (strlen (a) <= strlen (b)) return 0;
    for (int i = 0; i < strlen (b); i++) {
        if (b [strlen (b) - i - 1] != a [strlen (a) - i - 1]) {
            return 0;
        }
    }
    return 1;
}
int main () {
    char leftsolution [100], rightsolution [100], dd;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%s", &rijeci [i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%s", &unos);
        l = r = false;
        for (int j = 0; j < n; j++) {
            if (!l) {
                if (checkleft (unos, rijeci [j])) {
                    indleft = j;
                    l = true;
                }
            }
            if (!r) {
                if (checkright (unos, rijeci [j])) {
                    indright = j;
                    r = true;
                }
            }
        }
        if (!l) printf ("ne postoji ");
        else if (l == true) printf ("%s ", rijeci [indleft]);
        if (!r) puts ("ne postoji");
        else if (r == true) puts (rijeci [indright]);
    }
    //cout<<checkright ("bababa", "baba")<<endl;
    return 0;
}
/*
( · _ ·)--⌐■-■
( · _ ·)⌐■-■
(⌐■-■)
YEEEEEEEEEEEEEAH!
*/
