#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
struct point {
    ll x, y;
    point () {}
    point (int _x, int _y) {x = _x; y = _y;}
} help;
ll input [1001] [1001], n, m, in0, maxn, dirind;
ll gore [1001] [1001];
ll lijevo [1001] [1001];
ll gorelijevo [1001] [1001];
ll goredesno [1001] [1001];
int main () {
    scanf ("%lld %lld", &n, &m);
    for (int i = 0; i <= n + 1; i++) {
        if (i == 0) continue;
        for (int j = 0; j <= m + 1; j++) {
            if (i && j && i <= n && j <= m) scanf ("%lld", &input [i] [j]);
            //input [i] [j] *= (-1);
            gore [i] [j] = gore [i - 1] [j] + input [i] [j];
            lijevo [i] [j] = lijevo [i] [j - 1] + input [i] [j - 1];
            gorelijevo [i] [j] = gorelijevo [i - 1] [j - 1] + input [i - 1] [j - 1];
            goredesno [i] [j] = goredesno [i - 1] [j + 1] + input [i - 1] [j + 1];
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (!input [i] [j]) {
            //gore
            if (maxn < gore [i] [j]) {
                dirind = 1;
                maxn = gore [i] [j];
                help = point (i, j);
            }
            //goredesno
            if (maxn < goredesno [i] [j]) {
                maxn = goredesno [i] [j];
                dirind = 2;
                help = point (i, j);
            }
            //desno
            if (maxn < lijevo [n] [m] - lijevo [i] [j - 1]) {
                maxn = lijevo [n] [m] - lijevo [i] [j - 1];
                dirind = 3;
                help = point (i, j);
            }
            //doledesno
            /*if (maxn < gorelijevo [n] [m] - gorelijevo [i - 1] [j - 1]) {
                maxn = gorelijevo [n] [m] - gorelijevo [i - 1] [j - 1];
                dirind = 4;
                help = point (i, j);
            }*/
            //dole
            if (maxn < gore [i] [j]) {
                maxn = gore [i] [j];
                dirind = 5;
                help = point (i, j);
            }
            //dolelijevo
            ll d = i + j;
            if (d > n) d = n;
            if (maxn < goredesno [d] [0] - goredesno [i - 1] [j + 1]) {
                maxn = goredesno [d] [0] - goredesno [i - 1] [j + 1];
                dirind = 6;
                help = point (i, j);
            }
            //lijevo
            if (maxn < lijevo [i] [j]) {
                maxn = lijevo [i] [j];
                dirind = 7;
                help = point (i, j);
            }
            //gorelijevo
            if (maxn < gorelijevo [i] [j]) {
                maxn = gorelijevo [i] [j];
                dirind = 8;
                help = point (i, j);
            }
            }
        }
    }
    printf ("%lld %lld\n", help.x, help.y);
    /*if (dirind == 1) {
        printf ("gore");
    }
    else if (dirind == 2) {
        printf ("gore-desno\n");
    }
    else if (dirind == 3) {
        printf ("desno\n");
    }
    else if (dirind == 4) {
        printf ("dole-desno\n");
    }
    else if (dirind == 5) {
        printf ("dole\n");
    }*/
    /*else if (dirind == 6) {*/
        printf ("dole-levo\n");
    /*}*/
    /*else if (dirind == 7) {
        printf ("levo\n");
    }
    else if (dirind == 8) {
        printf ("gore-levo\n");
    }*/
    return 0;
}
/*
1 - gore
2 - goredesno
3 - desno
4 - doledesno
5 - dole
6 - dolelijevo
7 - lijevo
8 - lijevogore
*/
