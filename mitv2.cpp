#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ull;
ull A, B, C, D, as, sa;
struct edge {
    ull n, w;
    edge () {}
    edge (ull _n, ull _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;
struct edge2 {
    ull m, n, w;
    edge2 () {}
    edge2 (ull _m, ull _n, ull _w) {m = _m; n = _n; w = _w;}
    bool operator < (const edge2 & x) const
    {
        return w > x.w;
    }
} help2;
priority_queue <edge2> Q;
vector <edge> graf [90000];
ull d [100000], e, v, a, parent [10000], b, c, start, end;
bool visited [100000];
ull dijkstra () {
    Q.push (edge2 (start, start, 0));
    while (!Q.empty()) {
        help2 = Q.top();
        Q.pop();
        if (!visited [help2.n]) {
            visited [help2.n] = 1;
            d [help2.n] = help2.w;
            parent [help2.n] = help2.m;
            if (help.n == end) break;
            for (ull i = 0; i < graf [help2.n].size(); i++)
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));
        }
   }
   if (d [end] == 0) {
       cout<<"-1"<<endl;
       exit (0);
   }
   return d [end];
}
int main () {
    /*freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);*/
    cin>>start>>end;
    while (cin>>C)
    {
        cin>>D;
        as = C + 1000001;
        sa = D + 1000001;
        graf [as].push_back (edge2 (sa, ()))
    }
    cout<<dijkstra ()<<endl;
    return 0;
}
