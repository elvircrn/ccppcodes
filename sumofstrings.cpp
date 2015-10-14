#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string a, b;
struct matrica {
    unsigned long long int height, width, m [4] [4];
    matrica () {}
    matrica (unsigned long long int _h, unsigned long long int _w) {
        height = _h;
        width = _w;
        for (unsigned long long int i = 0; i < height; i++)
            for (unsigned long long int j = 0; j < width; j++)
                m [i] [j] = 0;
    }
    matrica (unsigned long long int _h, unsigned long long int _w, bool sth) {
        for (unsigned long long int i = 0; i < height; i++)
            for (unsigned long long int j = 0; j < width; j++)
                m [i] [j] = 0;
        for (unsigned long long int i = 0; i < height; i++) m [i] [i] = 1;
    }
    matrica (unsigned long long int h, unsigned long long int w, bool s, bool ss) {
        height = h;
        width = w;
        m [0] [0] = 1;
        m [1] [0] = 0;
    }
} solution = matrica (2, 1), start = matrica (2, 2),
one = matrica (2, 2, 1),
help2 = matrica (2, 2), jedinicna_matrica = matrica (2, 2, true), desno = matrica (2, 1, true ,true);

matrica multiplication (matrica x, matrica y)
{
    matrica help = matrica (x.height, y.width);
    for (unsigned long long int i = 0; i < x.height; i++)
        for (unsigned long long int j = 0; j < y.width; j++)
            for (unsigned long long int k = 0; k < x.width; k++)
                help.m [i] [j] += ((x.m [i] [k]) * (y.m [k] [j]));
    return help;
}

matrica fast_pow (matrica x, unsigned long long int m1) {
    matrica r = jedinicna_matrica;
    if (m1 % 2) r = x;
    while (m1 >>= 1) {
        x = multiplication (x, x);
        if (m1 % 2) r = multiplication (r, x);
    }
    return r;
}
int main () {
    int t, x, y, n;
    string a, b;
    //scanf ("%d", &t);
    //while (t--) {
        scanf ("%d", &n);
        cin>>a>>b;
        start = matrica (2, 2);
        start.m [0] [0] = start.m [0] [1] = start.m [1] [0] = 1;
        start.m [1] [1] = 0;
        help2 = fast_pow (start, n - 1);
        matrica nesto = matrica (2, 1, true, true);
    //}
    unsigned long long int gg = a.length() * help2.m [0] [0], gore = a.length() * help2.m [0] [0] + b.length() * help2.m [0] [1], dole = a.length() * help2.m [1] [0];
    gore--;
    dole--;
    cout<<gore<<" "<<dole<<endl;
    return 0;
}
