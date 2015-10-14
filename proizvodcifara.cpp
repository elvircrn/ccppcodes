#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool prime = 1;
unsigned long long int cnt, sol;
int fin [10];
long long int fast_pow (long long int x, long long int m) {
        long long int r = 1;
        if (m % 2) r = x;
        while (m >>= 1) {
            x *= x;
            if (m % 2) r *= x;
        }
        return r;
}
unsigned long long int f (unsigned long long int n) {
    if (n == 1) {
        unsigned long long int a, help = 0, cnt = 0;
        return 0;
    }
    for (int i = 2; i < 10; i++) {
        if (n % i == 0) {
            fin [i]++;
            return f (n / i);
            fin [i]--;
        }
    }
    return 0;
}
int main () {
    unsigned long long int n;
    scanf ("%lld", &n);
    for (int i = 2; i < 10; i++)
        if (n % i == 0)
            prime = false;
    if (prime) {printf ("-1\n"); return 0;}
    f (n);
    cnt = 1;
    for (int i = 2; i < 10; i++) {
        printf ("%d: %d\n", i, fin [i]);
    }
    return 0;
}
        /*for (int i = 2; i <= 9; i++) {
            //printf ("%d: %d\n", i, fin [i]);
            while (a--) {
                //printf ("%d\n", a);
                cnt += fast_pow (10, help) * i;
                help++;
            }
        }*/
        //sol = min (sol)
