#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

char rijeci [10000000], aa;
int ind, cnt;

int main () {

    while (true) {

        aa = getchar();

        if (!isalnum (aa)) {
            if (ind) {
                for (int i = 0; i < ind / 2; i++) {
                    if (rijeci [i] != rijeci [ind - i - 1] || !isalnum (rijeci [i]) || !isalnum (rijeci [ind - i - 1])) goto l1;
                } cnt++;
            }
            l1:; ind = 0;
        }

        else {rijeci [ind] = (tolower (aa)); ind++;}

        if (aa == '\n' || aa == EOF) break;

    }

    printf ("%d\n", cnt);

    return 0;
}
