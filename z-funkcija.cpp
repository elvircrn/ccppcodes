#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
unsigned long long int a, b, c, f1, f2, f3, x1;
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
} start = matrica (3, 3), one = matrica (3, 3), solution = matrica (3, 3), help2 = matrica (3, 3);
matrica multiplication (matrica x, matrica y)
{
    matrica help = matrica (x.height, y.width);
    for (unsigned long long int i = 0; i < x.height; i++)
        for (unsigned long long int j = 0; j < y.width; j++)
            for (unsigned long long int k = 0; k < x.width; k++)
                help.m [i] [j] += ((x.m [i] [k] % 10000) * (y.m [k] [j] % 10000)) % 10000;
    return help;
}
matrica fast_pow (matrica x, unsigned long long int m1) {
        matrica r = one;
        if (m1 % 2) r = x;
        while (m1 >>= 1) {
            x = multiplication (x, x);
            if (m1 % 2) r = multiplication (r, x);
        }
        return r;
}
void set_it (unsigned long long int h, unsigned long long int g) {
    start.m [h] [g] = 1;
}
int main () {
    matrica asd = matrica (3, 1);
    cin>>f1>>f2>>f3>>c>>b>>a>>x1;
    for (unsigned long long int i = 0; i < 3; i++)
        one.m [i] [i] = 1;
    asd.m [0] [0] = f3;
    asd.m [1] [0] = f2;
    asd.m [2] [0] = f1;
    start.m [0] [0] = a;
    start.m [0] [1] = b;
    start.m [0] [2] = c;
    set_it (1, 0);
    set_it (2, 1);
    help2 = fast_pow (start, x1 - 1);
    solution = multiplication (help2, asd);
    printf ("%d \n", solution.m [2] [0] % 10000);
    return 0;
}
