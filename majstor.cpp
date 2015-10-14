#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, r, cnt;
string first, others [100];
//0 -> first wins 1 -> second wins
int fight (char a, char b) {
    //K P S
    if (a == b) return 1;
    if (a == 'K') {
        if (b == 'S') return 2;
        else return 0;
    }
    if (a == 'P') {
        if (b == 'K') return 2;
        else return 0;
    }
    if (a == 'S') {
        if (b == 'P') return 2;
        else return 0;
    }
}
int main () {
    int d1 = 0, d2 = 0, d3 = 0, maxwon = 0;
    cin>>n>>first>>r;
    for (int i = 0; i < r; i++) cin>>others [i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            cnt += fight (first [i], others [j] [i]);
            d1 += fight ('K', others [j] [i]);
            d2 += fight ('P', others [j] [i]);
            d3 += fight ('S', others [j] [i]);
        }
        maxwon += max (d1, max (d2, d3));
        d1 = d2 = d3 = 0;
    }
    cout<<cnt<<endl;
    cout<<maxwon<<endl;
    return 0;
}
