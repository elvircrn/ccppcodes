#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, placinke [6000], hash [6000], start;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {scanf ("%d", &array [i]); hash [array [i]] = i;}
    start = hash [n] + 1;
    printf ("%d\n", start - 1);
    while (start) {
        bool nasao = false;
        for (int i = 1; i <= n; i++)
            if (hash [i] != i + 1) {nasao = true; break;}
        if (!nasao) break;
        while (hash [start] != start - 1) start--;
    }
    return 0;
}

/*
2
5
1
3
4

5
2
1
3
4

4
3
1
2
5

2
1
3
4
5

1
2
3
4
5
*/
