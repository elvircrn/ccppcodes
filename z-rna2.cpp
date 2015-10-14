#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define vect vector<int>

vect A;
vect U;
vect G;
vect C;
int n;
char a;
bool can [200] [200], usedA [200], usedU [200], usedG [200], usedC [200];

int rek (bool uA, bool uU, bool uG, ) {

}

int main () {

    can ['A'] ['U'] = true;
    can ['U'] ['A'] = true;
    can ['C'] ['G'] = true;
    can ['G'] ['C'] = true;
    can ['G'] ['U'] = true;
    can ['U'] ['G'] = true;

    scanf ("%d", &n); getchar();
    for (int i = 0; i < n; i++) {
        a = getchar();
        if (a == 'A') A.push_back (i);
        else if (a == 'U') U.push_back (i);
        else if (a == 'G') G.push_back (i);
        else if (a == 'C') C.push_back (i);
    }



    return 0;
}
/*
A - U
C – G
U – G
*/
