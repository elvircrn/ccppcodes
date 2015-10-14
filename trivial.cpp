#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int x, y, n, cnt, sol;
double find (int a) {
    int sum = 0;
    for (int i = 1; i <= a / 2; i++)
        if (!(a % i))
            sum += i;
    return (double (sum / a));
}
int main () {
    scanf ("%d %d", &x, &y);
    for (int i = x; i <= y; i++) {
        }
