#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define TYPE long long int

TYPE n, b;

int main ()
{
    scanf ("%lld %lld", &n, &b);
    printf ("%lld\n", n - (b / 3 + (b - ((b / 3) * 3))));

    return 0;
}

