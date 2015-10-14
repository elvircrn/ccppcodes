#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
queue <int> Q2;
int he, n, cnt, maximum, current, d, dist [50000];
vector <int> graph [50000];
int find_pathv2 (int start) {
    bool visited2 [50000];
    int maximum = 0;
    int maxpath = 0;
    Q2.push (start);
    dist [start] = 0;
    visited2 [start] = true;
    while (!Q2.empty()) {
        he = Q2.front();
        Q2.pop();
        for (int i = 0; i < graph [he].size(); i++) {
            if (!visited2 [graph [he] [i]]) {
                visited2 [graph [he] [i]] = true;
                Q2.push (graph [he] [i]);
                dist [graph [he] [i]] = dist [he] + 1;
                maximum = max (dist [graph [he] [i]], maximum);
            }
        }
    }
    return maximum;
}
int main () {
    int MAXD = 0, MAXSOL = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &d);
        MAXD = max (MAXD, d);
        if (i + 1 != d) {graph [d].push_back (i + 1); /*graph [i + 1].push_back (d);*/}
    }
    for (int i = 1; i <= MAXD; i++)
        MAXSOL = max (find_pathv2 (i), MAXSOL);
    printf ("%d\n", MAXSOL + 1);
    return 0;
}
