#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef int ull;

string mini (ull x) {
         if (x == 0) return "0";
    else if (x == 1) return "1";
    else if (x == 2) return "2";
    else if (x == 3) return "3";
    else if (x == 4) return "4";
    else if (x == 5) return "5";
    else if (x == 6) return "6";
    else if (x == 7) return "7";
    else if (x == 8) return "8";
    else if (x == 9) return "9";

}

string convert (ull x) {
    if (x == 0) return "0";
    string ret = "";
    while (x) {
        ret = mini (x % 10) + ret;
        x /= 10;
    }
    return ret;
}

struct edge {
    ull n, w;
    edge () {}
    edge (ull _n, ull _w) {n = _n; w = _w;}
    bool operator < (const edge & xx) const
    {
        if (w != xx.w) return w > xx.w;
        else return n < xx.n;
    }
} help;
ull asd, array [25000];
struct edge2 {
    ull m, n, w;
    edge2 () {}
    edge2 (ull _m, ull _n, ull _w) {m = _m; n = _n; w = _w;}
    bool operator < (const edge2 & xx) const
    {
        if (w != xx.w) return w > xx.w;
        else return n < xx.n;
    }
} help2;
priority_queue <edge2> Q;
vector <edge> graf [25000];
ull d [25000], e, v, a, parent [25000], b, c, start, end;
bool visited [25000];
void dijkstra () {
    start = 1;
    end = 0;
    Q.push (edge2 (start, start, 0));
    while (!Q.empty()) {
        help2 = Q.top();
        Q.pop();
        if (!visited [help2.n]) {
            visited [help2.n] = true;
            d [help2.n] = help2.w;
            parent [help2.n] = help2.m;
            if (help2.n == end) break;
            for (ull i = 0; i < graf [help2.n].size(); i++) {
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));
            }
        }
   }
   if (d [end] == -1) {
       printf ("No path\n");
       return;
   }
   else {
        ull h = end;
        while (h != start) {
            array [asd] = parent [h];
            asd++;
            h = parent [h];
        }
        //cout<<end<<" ";
        //for (ull i = 0; i < asd; i++) printf ("%lld ", array [i]);
        for (ull i = asd - 1; i > -1; i--) printf ("%lld ", array [i]);
   }
   return;
}
int main () {
    memset (d, -1, sizeof d);
    scanf ("%d", &e);
    for (int i = 0; i < e; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        graf [b].push_back (edge (a, c));
    }
    dijkstra ();
    return 0;
}
