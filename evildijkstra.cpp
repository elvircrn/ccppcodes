#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector <int> DQ;

int SOLUTION;

string mini (int x) {
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

string convert (int x) {
    if (x == 0) return "0";
    string ret = "";
    while (x) {
        ret = mini (x % 10) + ret;
        x /= 10;
    }
    return ret;
}

struct newint {
    int val, w;
    newint () {}
    newint (int a, int _w) {val = a; w = _w;}
    bool operator < (const newint & xx) const {
        return convert (val) > convert (xx.val);
        //return val >= xx.val;
    }
};

priority_queue <newint> A [50000];

struct edge {
    int n, w;
    edge () {}
    edge (int _n, int _w) {n = _n; w = _w;}
    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;

int asd, array [50000];

struct edge2 {
    int m, n, w;
    edge2 () {}
    edge2 (int _m, int _n, int _w) {m = _m; n = _n; w = _w;}
    bool operator < (const edge2 & x) const
    {
        return w > x.w;
    }
} help2;

priority_queue <edge2> Q;
vector <edge> graf [50001];
int d [500000], e, v, a, parent [50000], b, c, start, end;
bool visited [500000], visited2 [50001];

int dijkstra () {
    Q.push (edge2 (start, start, 0));
    while (!Q.empty()) {
        help2 = Q.top();
        Q.pop();
        if (!visited [help2.n]) {
            visited [help2.n] = 1;
            d [help2.n] = help2.w;
            if (help.n == end) break;
            for (int i = 0; i < graf [help2.n].size(); i++)
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));
        }
   }
   return d [end];
}

bool dfs (int edgeind, int progress) {
    if (edgeind == 1 && progress == SOLUTION) return true;
    if (edgeind == 1) return false;
    visited2 [edgeind] = true;
    for (int i = 0; i < graf [edgeind].size(); i++)
        if (!visited2 [graf [edgeind] [i].n]) {
            A [edgeind].push (newint (graf [edgeind] [i].n, graf [edgeind] [i].w + progress));
        }
    while (!A [edgeind].empty()) {
        if (dfs ((A [edgeind].top()).val, (A [edgeind].top()).w)) {
            DQ.push_back ((A [edgeind].top()).val);
            return true;
        }
        A [edgeind].pop();
    }
    //visited2 [edgeind] = false;
    return false;
}

int main () {
    cin>>e;

    start = 0;
    end = 1;

    for (int i = 0; i < e; i++) {
        cin>>a>>b>>c;
        graf [a].push_back (edge (b, c));
    }

    SOLUTION = dijkstra();
    dfs (0, 0);
    printf ("0 ");
    for (int i = DQ.size() - 1; i > -1; i--) printf ("%d ", DQ [i]);
    printf ("\n");
    return 0;
}
/*
15
0 9 1
0 2 1
2 9 1
9 3 1
2 3 1
3 4 1
2 4 1
2 7 1
4 7 1
7 8 1
4 10 1
4 8 1
4 1 1
8 1 1
3 1 1

4
0 2 1
0 22 1
2 1 1
22 1 1
*/


