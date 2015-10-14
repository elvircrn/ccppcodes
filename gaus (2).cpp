#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef unsigned long long int ull;
ull sum (ull x) {
    ull cpy = x;
    ull sol = 0;
    while (x) {
        sol += x % 10;
        x /= 10;
    }
    return (sol - (cpy % 10));
}
ull f (ull n) {
    if (n == 0) return 1;
    else if (sum (n) % 2 == 0) return (n / 2 + 1);
    else if (n % 2 == 0) return (n / 2);
    else return (n / 2 + 1);
}
int g (int a, int b) {
    return f (b) - f (a - 1);
}
int main () {
    ull a, b;
    cin>>a>>b;
    cout<<g (a, b);
    return 0;
}
