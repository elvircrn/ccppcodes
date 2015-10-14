#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
struct matrica {
    unsigned long long int height, width, m [60] [60];
    matrica () {}
    matrica (unsigned long long int _h, unsigned long long int _w) {
        height = _h;
        width = _w;
        for (unsigned long long int i = 0; i < height; i++)
            for (unsigned long long int j = 0; j < width; j++)
                m [i] [j] = 0;
    }
} start, end, empty, total, jedinicna_matrica;
matrica multiplication (matrica x, matrica y)
{
    matrica help = matrica (x.height, y.width);
    for (unsigned long long int i = 0; i < x.height; i++)
        for (unsigned long long int j = 0; j < y.width; j++)
            for (unsigned long long int k = 0; k < x.width; k++)
                help.m [i] [j] += ((x.m [i] [k]  % 321555123) * (y.m [k] [j] % 321555123));
    return help;
}
unsigned long long int n, k, width;
matrica fast_pow (matrica x, unsigned long long int m) {
        matrica r = jedinicna_matrica;
        if (m%2) r = x;
        while (m >>= 1) {
                x = multiplication(x, x);
                if (m%2) r = multiplication(r, x);
        }

        return r;
}
int main () {
    cin>>n>>k;
    width = 2 * k + 1;
    start = matrica (width, width);
    matrica a1 = matrica (1, width); a1.m [0] [k] = a1.m [0] [k - 1] = a1.m [0] [k + 1] = 1;
    jedinicna_matrica = matrica (width, width);
    for (unsigned long long int i = 0; i < width; i++) {jedinicna_matrica.m [i] [i] = 1; start.m [i + 1] [i] = 1; start.m [i] [i] = 1; start.m [i] [i + 1] = 1;}
    matrica nesto = fast_pow (start, n - 1);
    total = multiplication (a1, nesto);
    unsigned long long int sol = 0;
    for (int i = 0; i < width; i++) sol = (sol + total.m [0] [i]) % 321555123;
    cout<<sol<<endl;
    return 0;
}
