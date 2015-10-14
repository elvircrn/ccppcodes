#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, dp [1000] [1000], numbers [1000], maxn;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &numbers [i]);
    }
