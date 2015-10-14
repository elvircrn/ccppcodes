#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define modulo 10007

typedef long long int ull;

ull array [40000], cnt, n;

int main () {

    scanf ("%lld", &n);

    for (ull i = 0; i < n; i++)
        scanf ("%lld", &array [i]);

    sort (array, array + n);

    for (ull i = 2; i < n; cnt %= modulo, i++)
        if (cnt + (array [i]) * (((i - 1) * (i)) / 2) > 0)
            cnt += ((array [i] % modulo) * (((i - 1) * (i)) / 2 % modulo)) % modulo;
        else
            cnt += array [i] * (((i - 1) * (i)) / 2);

    if (cnt >= 0)
        printf ("%lld\n", cnt % modulo);
    else
        printf ("%lld\n", cnt + modulo);

    return 0;

}
