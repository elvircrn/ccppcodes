#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct edge {
    int n, w;
    edge () {}
    edge (int _n, int _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;
int asd, array [5000000];
struct edge2 {
    int m, n, w;
    edge2 () {}
    edge2 (int _m, int _n, int _w) {m = _m; n = _n; w = _w;}
    bool operator < (const edge2 & x) const
    {
        if (w == x.w) return n > x.n;
        return w > x.w;
    }
} help2;
priority_queue <edge2> Q;
vector <edge> graf [500000];
int d [5000000], e, v, a, parent [500000], b, c, start, end;
bool visited [5000000];
void dijkstra () {
    Q.push (edge2 (start, start, 0));
    while (!Q.empty()) {
        help2 = Q.top();
        Q.pop();
        if (!visited [help2.n]) {
            visited [help2.n] = 1;
            d [help2.n] = help2.w;
            parent [help2.n] = help2.m;
            if (help.n == end) break;
            for (int i = 0; i < graf [help2.n].size(); i++)
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));
        }
   }
   if (d [end] == 0) {
       cout<<"-1"<<endl;
       exit (0);
   }
   else {
       int h = end;
        while (h != 1) {
            array [asd] = parent [h];
            asd++;//printf ("%d ", parent [h]);
            h = parent [h];
        }
        for (int i = asd - 1; i >= 0; i--) printf ("%d ", array [i]);
        cout<<end<<endl;
   }
   //return d [end];
}
int main () {
    /*freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);*/
    cin>>v>>e;
    start = 1;
    end = v;
    for (int i = 0; i < e; i++) {
        cin>>a>>b>>c;
        graf [a].push_back (edge (b, c));
        graf [b].push_back (edge (a, c));
    }
    dijkstra ();
    return 0;
}
