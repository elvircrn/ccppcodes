#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
struct edge {
    int p, n, w;
    edge () {}
    edge (int _p, int _n, int _w) {p = _p; n = _n; w = _w;}
    bool operator < (const edge & xx) const
    {
        return w > xx.w;
    }
} help;
priority_queue <edge> Q;
priority_queue <edge> QQ;
vector <edge> graph [40001];
bool rvisited [40001], jvisited [40001];
int rs, re, js, je, romeo [40001], juliette [40001], rparent [40001], jparent [40001];
int e, v, a, b, c;
int main () {
    scanf ("%d %d %d %d %d %d", &v, &e, &js, &je, &rs, &re);
    for (int i = 0; i < e; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph [a].push_back (edge (a, b, c));
        graph [b].push_back (edge (b, a, c));
    }
    Q.push  (edge (rs, rs, 0));
    while (!Q.empty()) {
        help = Q.top();
        Q.pop();
        if (!rvisited [help.n]) {
            rvisited [help.n] = 1;
            romeo [help.n] = help.w;
            rparent [help.p] = help.n;
            if (help.n == re) goto l1;
            for (int i = 0; i < graph [help.n].size(); i++) {
                if (!rvisited [graph [help.n] [i].n]) {
                    Q.push (edge (help.n, graph [help.n] [i].n, romeo [help.n] + graph [help.n] [i].w));
                }
            }
        }
    }
    l1:;
    QQ.push (edge (js, js, 0));
    while (!QQ.empty()) {
        help = QQ.top();
        QQ.pop();
        if (!jvisited [help.n]) {
            jvisited [help.n] = 1;
            juliette [help.n] = help.w;
            jparent [help.p] = help.n;
            if (help.n == je) goto l2;
            for (int i = 0; i < graph [help.n].size(); i++) {
                if (!jvisited [graph [help.n] [i].n]) {
                    QQ.push (edge (help.n, graph [help.n] [i].n, juliette [help.n] + graph [help.n] [i].w));
                }
            }
        }
    }
    l2:;
    bool found = 0;
    int cnt = 0;
    jparent [je] = -1;
    rparent [re] = -1;
    int man = rparent [rs], woman = jparent [js];
    while (man != -1 && woman != -1) {
        //printf ("%d %d\n", man, woman);
        cnt++;
        if (man == woman) {
            found = 1;
            break;
        }
        man = rparent [man];
        woman = jparent [woman];
    }
    if (found) printf ("%d\n", cnt);
    else if (not found) printf ("-1\n");
    return 0;
}
