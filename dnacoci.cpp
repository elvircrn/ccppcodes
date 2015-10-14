#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char a;
int n, f [1000011], g [1011001], x = 1;

int main () {

    scanf ("%d", &n); getchar();

    while (n--) {

        a = getchar();

        if (a == 'A') {
            f [x] = f [x - 1];
            g [x] = min (g [x - 1], f [x - 1]) + 1;
        }
        else {
            g [x] = g [x - 1];
            f [x] = min (f [x - 1], g [x - 1]) + 1;
        }


        x++;
    }

    printf ("%d\n", f [x - 3]);

    return 0;
}
