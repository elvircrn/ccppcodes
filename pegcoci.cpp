#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
char peg [100] [100], dd;
int cnt;
int main () {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            dd = getchar();
            if (dd == '\n') goto l1;
            peg [i] [j] = dd;
        }
        getchar();
        l1:;
    }
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i - 2 < 0 || j - 2 < 0 || i + 1 > 7 || j + 1 > 7) continue;
            if (peg [i] [j] == 'o') {
            if (i - 2 > 0 && peg [i - 1] [j] == 'o' && peg [i - 2] [j] == '.') cnt++;
            if (peg [i] [j + 1] == 'o' && peg [i] [j + 2] == '.') cnt++;
            if (peg [i + 1] [j] == 'o' && peg [i + 2] [j] == '.') cnt++;
            if (j - 2 > 0 && peg [i] [j - 1] == 'o' && peg [i] [j - 2] == '.') cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
  ooo
  ooo
ooooooo
ooo.ooo
ooooooo
  ooo
  ooo
*/
