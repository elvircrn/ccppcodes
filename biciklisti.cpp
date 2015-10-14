#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
vector <int> solution;
int Size, a, b, c, parent [100001], maximum, d [100000];
struct myedge {
    int n, w;
    myedge () {}
    myedge (int _n, int _w) {n = _n; w = _w;}
} help;
queue <myedge> Q;
vector <myedge> graph [100000];
//bool visited [100000];
int solve () {
    int maxIND, maximum = 0, maxdepth;
    Q.push (myedge (1, 0));
    while (!Q.empty ()) {
        help = Q.front();
        Q.pop();
        for (int i = 0; i < graph [help.n].size(); i++) {
            if (parent [help.n] != graph [help.n] [i].n) {
                parent [graph [help.n] [i].n] = help.n;
                d [graph [help.n] [i].n] = d [help.n] + graph [help.n] [i].w;
                if (d [graph [help.n] [i].n] > maximum) {
                    maximum = d [graph [help.n] [i].n];
                    maxIND = graph [help.n] [i].n;
                }
                Q.push (myedge (graph [help.n] [i].n, graph [help.n] [i].w));
            }
        }
    }
    return maxIND;
}
int main () {
    int maxIND;
    scanf ("%d", &Size);
    for (int i = 0; i < Size - 1; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (myedge (b, c));
        graph [b].push_back (myedge (a, c));
    }
    maxIND = solve ();
    parent [1] = 0;
    printf ("%d \n", d [maxIND]);
    solution.push_back (maxIND);
    while (parent [maxIND]) {
        maxIND = parent [maxIND];
        solution.push_back (maxIND);
    }
    for (int i = solution.size() - 1; i >= 0; i--) printf ("%d \n", solution [i]);
    return 0;
}
