#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int a, n, maxn, cnt = 1, niz [2001];
struct b4sort {
    int ind, value;
    b4sort () {}
    b4sort (int _i, int _v) {ind = _i; value = _v;}
    bool operator < (const b4sort & xx) const
    {
        return value < xx.value;
    }
} b4, array [2000];
struct element {
    int combo, value, ind;
    element () {}
    element (int _c, int _v, int _i) {combo = _c; value = _v; ind = _i;}
    bool operator < (const element & xx) const
    {
        if (combo == xx.combo) return ind < xx.ind;
        else return combo > xx.combo;
    }
} help, elements [2001];
int main () {
    int ind = 0, j = 0;
    scanf ("%d %d", &n, &maxn);
    for (int i = 0; i < n; i++) {
        bool found = false;
        scanf ("%d", &niz [i]);
        for (j = 0; j <= i; j++) {
            if (niz [j] == niz [i]) {found = true; break;}
        }
        if (found) array [i] = b4sort (j, niz [i]);
        else array [i] = b4sort (i, niz [i]);
    }
    sort (array, array + n);
    for (int i = 0; i < n; i++) {
        if (array [i].value != array [i + 1].value) {
            elements [ind] = element (cnt, array [i].value, array [i].ind);
            ind++;
            cnt = 1;
        }
        else cnt++;
    }
    sort (elements, elements + ind);
    for (int i = 0; i < ind; i++)
        for (int j = 1; j <= elements [i].combo; j++)
            printf ("%d ", elements [i].value);
    printf ("\n");
    return 0;
}
