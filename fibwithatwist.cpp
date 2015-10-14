#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int dp [2000000], a, b, c, f1, f2, f3, x;

int f (int n) {
    if (n == 1)
        return f1;
    else if (n == 2)
        return f2;
    else if (dp [n])
        return dp [n];
    else
        dp [n] = a * f (n - 1) + b * f (n - 2);
}

int main () {

    scanf ("%d %d %d %d", &f1, &f2, &b, &a);

    for (int i = 1; i <= 10; i++)
        printf ("%d %d \n", i, f (i));

    return 0;

}
/*
1 2
4 3
*/
