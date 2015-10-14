#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool prime = 1;
unsigned long long int cnt, sol, fin [100];
unsigned long long int help [5] = {2, 3, 5, 7};
int main () {
    unsigned long long int n, x;
    scanf ("%lld", &n);
    if (n == 0) {printf ("10\n"); return 0;}
    if (n == 1) {printf ("1\n");}
    x = n;
    for (int i = 0; i < 4; i++) {
        while (x % help [i] == 0) {
            fin [help [i]]++;
            x /= help [i];
        }
    }
    if (x != 1) {printf ("-1\n"); return 0;}
    int two = fin [2], three = fin [3];
    if (fin [3] > 1) {fin [9] = (fin [3] / 2); fin [3] -= (fin [9] * 2);}
    if (fin [2] > 2) {
        fin [8] += (fin [2] / 3);
        fin [2] = fin [2] % 3;
    }
    three = fin [3];
    two = fin [2];
    if (fin [2] && fin [3]) {
        fin [6] += min (fin [3], fin [2]);
        fin [2] -= min (two, three);
        fin [3] -= min (two, three);
    }
    int checker = 1;
    if (fin [2] == 2) {fin [4]++; fin [2] -= 2;}
    for (int i = 2; i < 10; i++) {
        if (!fin [i]) continue;
        for (int j = 1; j <= fin [i]; j++) {
            printf ("%d", i);
        }
    }
    return 0;
}
//1000000000000000000
//62208
