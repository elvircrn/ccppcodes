#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool visited [1000] [1000];
int students [1001], maxn, n, maxind;
int cnt = 0;
int dfs (int ind, int std) {
    if (!visited [ind] [std]) {
        cnt++;
        visited [ind] [std] = 1;
        return dfs (ind, students [std]);
    }
    else return 0;
}
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &students [i]);
    }
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        dfs (i, i);
        if (cnt > maxn) {
            maxn = cnt;
            maxind = i;
        }
    }
    printf ("%d\n", maxind);
    return 0;
}
