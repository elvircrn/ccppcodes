#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
bool notprime [1299710];
int Q, cnt, l, r;
void sieve () {
    int SQRT = sqrt (1299710);
    for (int i = 2; i <= SQRT; i++)
        if (!notprime [i])
            for (int j = i * i; j <= 1299710; j += i)
                notprime [j] = true;
}
int main () {
    sieve ();
    while (true) {
        scanf ("%d", &Q);
        if (!Q) break;
        cnt = 0;
        int cc = Q;
        while (notprime [cc]) {cc--; cnt++;}
        cc = Q;
        while (notprime [cc]) {cc++; cnt++;}
        printf ("%d\n", cnt);
    }
    return 0;
}
