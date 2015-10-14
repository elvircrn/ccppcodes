#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, cnt, ind;
char a, d, b [4], in [4];
short int magic [30] [30] [30] [30];
int main () {
    in [0] = getchar();
    in [1] = getchar();
    in [2] = getchar();
    in [3] = getchar();
    ind = 1;
    magic [int (in [0]) - 97] [int (in [1]) - 97] [int (in [2]) - 97] [int (in [3])- 97] = 1;
    a = getchar();
    while (a != '\n') {
        in [0] = in [1];
        in [1] = in [2];
        in [2] = in [3];
        in [3] = a;
        if (!magic [int (in [0]) - 97] [int (in [1]) - 97] [int (in [2]) - 97] [int (in [3])- 97])
            magic [int (in [0]) - 97] [int (in [1]) - 97] [int (in [2]) - 97] [int (in [3])- 97] = ind + 1;
        a = getchar();
        ind++;
    }
    scanf ("%d\n", &n);
    for (int i = 0; i < n; i++) {
        cnt = 0;
        b [0] = getchar();
        b [1] = getchar();
        b [2] = getchar();
        b [3] = getchar();
        cnt += magic [int (b [0]) - 97] [int (b [1]) - 97] [int (b [2]) - 97] [int (b [3])- 97];
        printf ("%d\n", cnt);
        a = getchar();
    }
    return 0;
}
