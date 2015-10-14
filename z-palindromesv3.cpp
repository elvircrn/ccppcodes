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
char unos [3000000];
string lijevo, desno;
int cnt;

int main () {

    for (int i = 0; i < sizeof (unos); i++) {
        if (!isalnum (unos [i])) {
            if (lijevo == desno && lijevo != "" && desno != "") cnt++;
            lijevo = desno = "";
        }

        else {
            lijevo = lijevo + low (unos [i]);
            desno = low (unos [i]) + desno;
        }
    }

    if (lijevo == desno && lijevo != "" && desno != "") cnt++;

    printf ("%d\n", cnt);

    return 0;
}
