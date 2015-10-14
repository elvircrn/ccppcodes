#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
int current = 0, pos [50000];
vector <int> Friend [50001];
bool visited [50001], touse [50001];
int parent [50001], n, m, maxa, SOLUTION, cnt, maxvisited, minvisited;
int main () {
    int a, b;
    scanf ("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        touse [a] = true;
        maxa = max (a, maxa);
        Friend [a].push_back (b);
    }
    for (int root = 1; root <= m; root++) {
        if (!touse [root]) continue;
        current = 0;
        for (int z = minvisited; z <= maxvisited; z++)
            visited [z] = false;
        current = 1;
        cnt = 1;
        pos [1] = root;
        parent [root] = 1;
        maxvisited = root;
        minvisited = root;
        cnt = 0;
        visited [root] = true;
        while (current) {
            int help = pos [current];
            current --;
            for (int i = 0; i < Friend [help].size(); i++) {
                if (!visited [Friend [help] [i]]) {
                    current++;
                    parent [Friend [help] [i]] = parent [help] + 1;
                    cout<<"Friend: "<<Friend [help] [i]<<" parent: "<<parent [Friend [help] [i]]<<endl;
                    SOLUTION = max (SOLUTION, parent [Friend [help] [i]]);
                    pos [current] = Friend [help] [i];
                    cnt = max (cnt, parent [Friend [help] [i]]);
                    maxvisited = max (maxvisited, Friend [help] [i]);
                    minvisited = min (minvisited, Friend [help] [i]);
                    visited [Friend [help] [i]] = true;
                }
            }
            if (current < 0) current = 0;
        }
        cout<<"root: "<<root<<" cnt: "<<cnt<<endl;
    }
    printf ("%d\n", SOLUTION);
    return 0;
}
/*
10 12
1 5
1 2
2 3
2 4
5 6
5 7
7 8
6 8
4 8
3 9
9 10
10 1
*/
