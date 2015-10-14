#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
long long int n, k;
int main () {
    cin>>n>>k;
    /*int c = n;
    while (c) {
        if (c == c % 10 && c != 1) goto l1;
        if (c % 10 != 0 ) {goto l1;}
        c /= 10;
    }
    cout<<((floor (k * log10 (n))) + 1) - 1<<endl;
    return 0;
    l1:;*/
    cout<<(long long int)(k * log10(n) + 1)<<endl;
    return 0;
}
