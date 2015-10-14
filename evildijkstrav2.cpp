#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ull;

vector <ull> DQ;

ull SOLUTION;

struct newint {
    ull val, w;
    newint () {}
    newint (ull a, ull _w) {val = a; w = _w;}
    bool operator < (const newint & xx) const {
        return val >= xx.val;
    }
};

priority_queue <newint> A [50000];

struct edge {
    ull n, w;
    edge () {}
    edge (ull _n, ull _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;

ull asd, array [50000];

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
vector <edge> graf [50001];
ull d [50000], e, v, a, parent [50000], b, c, start, end;
bool visited [50000], visited2 [50001];

ull dijkstra () {
    Q.push (edge2 (start, start, 0));
    while (!Q.empty()) {
        help2 = Q.top();
        Q.pop();
        if (!visited [help2.n]) {
            visited [help2.n] = 1;
            d [help2.n] = help2.w;
            //if (help.n == end) break;
            for (ull i = 0; i < graf [help2.n].size(); i++)
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));
        }
   }
   if (d [end] == 0) {
       cout<<"No path\n";
       exit (0);
   }
   return d [end];
}

bool dfs (ull edgeind, ull progress) {
    if (edgeind == 1 && progress == SOLUTION) return true;
    if (edgeind == 1) return false;
    visited2 [edgeind] = true;
    for (ull i = 0; i < graf [edgeind].size(); i++)
        if (!visited2 [graf [edgeind] [i].n]) {
            A [edgeind].push (newint (graf [edgeind] [i].n, graf [edgeind] [i].w + progress));
        }
    while (!A [edgeind].empty()) {
        if (dfs ((A [edgeind].top()).val, (A [edgeind].top()).w)) {
            DQ.push_back ((A [edgeind].top()).val - 1);
            cout<<(A [edgeind].top()).val - 1<<" ";
            return true;
        }
        A [edgeind].pop();
    }
    //visited2 [edgeind] = false;
    return false;
}

int main () {
    cin>>e;

    start = 2;
    end = 1;

    for (ull i = 0; i < e; i++) {
        cin>>a>>b>>c;
        //graf [a + 1].push_back (edge (b + 1, c));
        graf [b + 1].push_back (edge (a + 1, c));
    }

    SOLUTION = dijkstra();
    visited2 [2] = true;
    visited2 [0] = true;
    dfs (2, 0);
    //cout<<"0 ";
    //for (ull i = DQ.size() - 1; i > -1; i--) cout<<DQ [i]<<" ";
    cout<<"1 ";
    cout<<endl;
    return 0;
}
