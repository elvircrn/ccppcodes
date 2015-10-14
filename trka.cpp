#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
unsigned long long int SOLUTION;
bool visited [100010], visited2 [100010];
int parent [100010], dist [100010], h, he, i, cp2, dd, tmp, gg, DISTANCE, distancee;
queue <int> Q;
vector <int> graph [100010];
int a, b, n, p1, p2;
void find_path () {
    Q.push (p1);
    visited [p1] = true;
    parent [p1] = p1;
    while (!Q.empty()) {
        h = Q.front();
        Q.pop();
        for (i = 0; i < graph [h].size(); i++) {
            if (!visited [graph [h] [i]]) {
                visited [graph [h] [i]] = true;
                Q.push (graph [h] [i]);
                    dist [graph [h] [i]] = dist [h] + 1;
                    parent [graph [h] [i]]  = h;
                if (graph [h] [i] == p2) {
                    p1 = h;
                    return;
                }
            }
        }
    }
}
queue <int> Q2;
int find_pathv2 () {
    int maxpath = 0;
    Q2.push (p1);
    dist [p1] = 0;
    visited2 [p1] = true;
    while (!Q2.empty()) {
        he = Q2.front();
        Q2.pop();
        for (int i = 0; i < graph [he].size(); i++) {
            if (graph [he] [i] != gg && !visited2 [graph [he] [i]]) {
                visited2 [graph [he] [i]] = true;
                Q2.push (graph [he] [i]);
                dist [graph [he] [i]] = 0;
                dist [graph [he] [i]] = dist [he] + 1;
            }
        }
    }
}
int main () {
    scanf ("%d %d %d", &n, &p1, &p2);
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &a, &b);
        graph [a].push_back (b);
        graph [b].push_back (a);
    }
    int cp1 = p1;
    find_path ();
    DISTANCE = dist [p1];
    distancee = DISTANCE;
    DISTANCE /= 2;
    while (DISTANCE--) {
        gg = p1;
        p1 = parent [p1];
    }
    if (distancee % 2 == 1) {gg = p1; p1 = parent [p1];}
    if (distancee == 0) {gg = p2;}
    SOLUTION += dist [p1];
    find_pathv2 ();
    SOLUTION = dist [he] + 1 + SOLUTION;
    if (distancee % 2 == 1) SOLUTION++;
    cout<<SOLUTION<<endl;
    return 0;
}
/*
8 8 6
1 2
1 3
4 1
4 5
6 4
6 7
2 8
*/








