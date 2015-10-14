#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
struct solution {
    unsigned long long int b, e;
    bool find;
    solution () {b = 18446744073709551615; find = 0;}
} help;
solution asd;
unsigned long long int a, b, leftb, rightb;

unsigned long long int fast_pow (unsigned long long int base, unsigned long long int exp) {
    unsigned long long int solution2 = 1, d = base, t = 1;
    for (unsigned long long int i = 1; i <= exp; i++) {
            t = solution2;
            solution2 *= base;
            if (t > solution2) return 18446744073709551615;
    }
    return solution2;
}

solution solve (unsigned long long int x) {
        cout<<endl;
    unsigned long long int lef = 2, rig = 1000000000, pivot, k, p, kk;
    solution asd;
    while (lef <= rig) {
        pivot = (lef + rig) / 2;
        k = fast_pow (pivot, x);
        if (k == -1) rig = pivot - 1;
        else if (a <= k && k <= b && fast_pow (pivot, x + 1) >= k) {
            asd.find = 1;
            asd.e = x;
            asd.b = min (asd.b, pivot);
            rig = pivot - 1;
        }
        else if (k < a) lef = pivot + 1;
        else rig = pivot - 1;
    }
    return asd;
}
int main () {
    cin>>a>>b;
    leftb = sqrt (a);
    rightb = sqrt (b);
    //if (b >= 9223372036854775808) {cout<<"2 63"<<endl; return 0;    }
    for (unsigned long long int i = 63; i >= 1; i--) {
        if (i == 1) cout<<a<<" 1\n";
        else {
            solution dd = solve (i);
            if (dd.find) {cout<<dd.b<<" "<<dd.e<<endl; return 0;}
        }
    }
    return 0;
}
//2 9223372036854775807
