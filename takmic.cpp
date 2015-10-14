#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int nizzapocetak [1000000], nizzakraj [1000000], d = 0, in, i, j, x, y, start;
int main () {
    //freopen ("tt.txt", "r", stdin);
    //freopen ("takmicari.txt", "w", stdout);
    while (1) {
        scanf ("%d", &in);
        if (in == 0) {
            scanf ("%d %d", &x, &start);
            d++;
        }
        if (in == 3) break;
        if (in == 1) {
            scanf ("%d %d", &x, &y);
            if (nizzapocetak [x] != d) {nizzapocetak [x] = d; nizzakraj [x] = start;}
            nizzakraj [x] += y;
        }
        if (in == 2) {
            scanf ("%d", &x);
            if (nizzapocetak [x] != d) {nizzapocetak [x] = d; nizzakraj [x] = start;}
            printf ("%d\n", nizzakraj [x]);
        }
    }
    return 0;
}
