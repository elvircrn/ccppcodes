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
vector <int> graf [500000];
int n, m, plate [500000];
char a, dd;
int dfs (int x, int change) {
    queue <int> Q;
    Q.push (x);
    while (!Q.empty()) {
        int help = Q.front();
        Q.pop();
        if (help != x) plate [help] += change;
        for (int i = 0; i < graf [help].size(); i++) {
            Q.push (graf [help] [i]);
        }
    }
}
int main () {
    int x, y;
    scanf ("%d %d", &n, &m);
    scanf ("%d", &x);
    plate [1] = x;
    for (int i = 2; i <= n; i++) {
        scanf ("%d %d", &x, &y);
        graf [y].push_back (i);
        plate [i] = x;
    }
    for (int i = 0; i < m; i++) {
        scanf ("%s", &a);
        if (a == 'p') {
            scanf ("%d %d", &x, &y);
            dfs (x, y);
        }
        else {
            scanf ("%d", &x);
            printf ("%d\n", plate [x]);
        }
    }
    return 0;
}
