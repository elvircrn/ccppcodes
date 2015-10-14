#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
vector <int> graf [500055];
int n, m;
char a, dd;
int plate [500055], niz [500055], bit [500055], range [500055], brojac;
void set (int ind, int val) {
    while (ind <= n + 5) {
        bit [ind] += val;
        ind += ind & (-ind);
    }
    return;
}
int sum (int ind) {
    int s = 0;
    while (ind) {
        s += bit [ind];
        ind -= ind & (-ind);
    }
    return s;
}
int rekdfs (int x, int def) {
    brojac++;
    niz [x] = brojac;
    for (int i = 0; i < graf [x].size(); i++) {
        /*range [x] += */rekdfs (graf [x] [i], def);
    }
    range [x] = brojac;
    return 1;
}
int main () {
    freopen ("unos.txt", "r", stdin);
    freopen ("izlaz.txt", "w", stdout);
    int x, y;
    scanf ("%d %d", &n, &m);
    scanf ("%d", &x);
    plate [1] = x;
    for (int i = 2; i <= n; i++) {
        scanf ("%d %d", &x, &y);
        graf [y].push_back (i);
        plate [i] = x;
    }
    rekdfs (1, 1);
    for (int i = 0; i < m; i++) {
        scanf ("%s", &a);
        if (a == 'p') {
            scanf ("%d %d", &x, &y);
            set (niz [x] + 1, y);
            set (range [x] + 1, -y);
        }
        else {
            scanf ("%d", &x);
            printf ("%d\n", sum (niz [x]) + plate [x]);
        }
    }
    return 0;
}
