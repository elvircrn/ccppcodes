#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
using namespace std;
queue <int> H;
queue <int> Q;
vector <int> tree [1000000];
int help, n, m, parent [5000000], d [5000000];
bool visited [2000000], visited1 [1000000];
void assign1 () {
    H.push (1);
    parent [1] = -1;
    while (!H.empty()) {
        help = H.front();
        H.pop();
        for (int i = 0; i < tree [help].size(); i++) {
            if (!visited [tree [help] [i]] /*&& parent [help] != tree [help] [i]*/) {
                parent [tree [help] [i]] = help;
                visited [tree [help] [i]] = 1;
                H.push (tree [help] [i]);
            }
        }
    }
    parent [1] = 0;
}
int bfs () {
    Q.push (1);
    d [0] = -1;
    while (!Q.empty()) {
        help = Q.front ();
        d [help] = d [parent [help]] + 1;
        Q.pop();
        for (int i = 0; i < tree [help].size(); i++) {
            if (!visited1 [tree [help] [i]]) {
                visited1 [tree [help] [i]] = 1;
                Q.push (tree [help] [i]);
            }
        }
    }
}
int solve (int a, int b) {
    int cnt = 0;
    while (d [a] > d [b]) {a = parent [a]; cnt++;}
    while (d [a] < d [b]) {b = parent [b]; cnt++;}
    if (a == b) return a;
    while (parent [a] != parent [b]) {
        cnt++;
        a = parent [a];
        b = parent [b];
    }
    return parent [a];
}
int main () {
    int a, b;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &a, &b);
        tree [a].push_back (b);
        tree [b].push_back (a);
    }
    assign1 ();
    bfs ();
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        printf ("%d \n", solve (a, b));
    }
    return 0;
}


/*
9 1
3 1
2 1
3 4
3 5
5 6
6 7
2 8
8 9
2 7


7 3
3 1
2 1
3 4
3 5
5 6
6 7
7 4
6 2
6 7
*/
