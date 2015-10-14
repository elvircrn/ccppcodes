/*

4 5 2 4 0 1
0 1 1
1 2 0
2 3 0
2 0 0
3 1 1
1 0 0 1
2



4 5 2 7 0 1
0 1 1
1 2 0
2 3 0
2 0 0
3 1 1
1 0 0 1 0 0 1
4

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
struct edge {
    int x, token;
    edge () {}
    edge (int _x, int _token) {x = _x; token = _token;}
};
int x1, y2, z1, n, m, k, l, a, b, dp [1000] [1000], tokens [1000];
vector <edge> graph [1000];
int main () {
    cin>>n>>m>>k>>l>>a>>b;
    for (int i = 0; i < m; i++) {
        cin>>x1>>y2>>z1;
        graph [x1].push_back (edge (y2, z1));
    }
    for (int i = 1; i <= l; i++)
        cin>>tokens [i];
    dp [0] [a] = 1;
    for (int k = 1; k <= l; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < graph [i].size(); j++)
                if (graph [i] [j].token == tokens [k])
                    dp [k] [graph [i] [j].x] += dp [k - 1] [i];
    /*for (int i = 1; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            printf ("%d ", dp [i] [j]);
        }
        printf (" \n");
    }*/
    printf ("%d \n", dp [tokens [l]] [b]);
    return 0;
}
