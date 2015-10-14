#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
struct city {
    int x, y, population;
    city () {}
    city (int _x, int _y, int _p) {x = _x; y = _y; population = _p;}
};
vector <city> cities;
int maxsol, maxleft, n, d, sol, cnt, tree [1000000], solution, mod = 100000;
int main () {
    int a, b, c;
    scanf ("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        cities.push_back (city (a, b, c));
        a += 100000;
        b += 100000;
        tree [a - d] += c;
        tree [a + d + 1] -= c;
        maxleft = max (maxleft, a + d + 2);
    }
    for (int i = 0; i <= maxleft; i++) {
        solution += tree [i];
        maxsol = max (solution, maxsol);
        //printf ("i: %d tree [i]: %d solution: %d\n", i, tree [i], solution);
    }
    printf ("%d\n", maxsol);
    return 0;
}
