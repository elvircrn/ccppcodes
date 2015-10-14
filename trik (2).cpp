#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
struct card {
    char sign;
    int ind;
    card () {}
    card (int _s, int _i) {sign = _s;  ind = _i;}
    bool operator < (const card & x) const
    {
        if (sign == x.sign) return ind < x.ind;
        else return sign < x.sign;
    }
} help, cards [1000000];
bool sada = false;
int k, n;
char a, input [2000002];
int main () {
    scanf ("%d %d", &n, &k);
    cin.getline (input, 2000000);
    for (int i = 0; i < sizeof (input); i++) {
        if (i == 0) {
            a = input [0];
        }
        if (input [i] == ' ') {
            a = '%';
        }
        else if (a == '%')
    }
    return 0;
}
