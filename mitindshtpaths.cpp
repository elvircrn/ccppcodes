#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ull;
const ull inf = 1<<30;
ull cnt;
struct edge {
    ull n, w;
    edge () {}
    edge (ull _n, ull _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;
ull asd;
struct edge2 {
    ull m, n, w;
    edge2 () {}
    edge2 (ull _m, ull _n, ull _w) {m = _m; n = _n; w = _w;}
    bool operator < (const edge2 & x) const
    {
        return w > x.w;
    }
} help2;
vector <ull> verticelist;
vector <edge> graf [9000000];
ull d [9000000], e, v, a, b, c, start, end;
bool hash [9000000];
ull bellmanford () {
    ull cntt = 0;
    bool change = 1;
    while (change) {
        cntt++;
        change = 0;
        for (ull ii = 0; ii < verticelist.size(); ii++) {
            ull i = verticelist [ii];
            for (ull j = 0; j < graf [i].size(); i++) {
                if (d [i] > graf [i] [j].w + d [graf [i] [j].n]) {
                    change = 1;
                    d [i] = graf [i] [j].w + d [graf [i] [j].n];
                }
            }
        }
        /*if (cntt > cnt) {
            printf ("No path\n");
            exit (0);
        }*/
    }
    return d [end];
}
int main () {
    for (ull i = 0; i < 9000000; i++) d [i] = inf;
    ull C, D;
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    cin>>start>>end;
    start += 1000000;
    end += 1000000;
    d [start] = 0;
    ull as, sa;
    while (cin>>C) {
        cnt++;
        cin>>D;
        //cout<<C<<" "<<D<<endl;
        as = C + 1000000;
        sa = D + 1000000;
        graf [as].push_back (edge (sa, (C + D) * D));
        graf [sa].push_back (edge (as, (C + D) * D));
        if (!hash [as]) {hash [as] = 1; verticelist.push_back (as);}
        if (!hash [sa]) {hash [sa] = 1; verticelist.push_back (sa);}
    }
    cout<<bellmanford ()<<endl;
    return 0;
}

