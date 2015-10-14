#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dp [100001], n, a, b, c;
struct movie {
    int p, k, o;
    movie () {}
    movie (int _p, int _k, int _o) {p = _p; k = _k; o = _o;}
    bool operator < (const movie & x) const
    {
        return p < x.p;
    }
} array [100001];
int bs (int ind, int progress) {
    movie past = array [ind];
    int leftb = ind, rightb = n - 1, pivot;
    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        movie help = array [pivot];
        if (help.p > past.)
        if (dp [pivot] = max (dp [pivot], progress + help.o);
    }
}
void dostuff (int ind) {

}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        array [i] = movie (a, b, c);
    }
    sort (array, array + n);
    for (int i = 0; i < n; i++) {
        movie help = array [i];
        dostuff (i);
    }
    return 0;
}
