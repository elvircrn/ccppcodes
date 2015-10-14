#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ull;

ull array [50000], n, maximum, cnt, p, j, olimpijada [50000], d;
ull SOLUTION;

int main () {

    scanf ("%lld", &n); scanf ("%lld", &array [0]);
    for (int i = 1; i < n; i++) scanf ("%lld", &array [i]);

    sort (array, array + n);

    olimpijada [0] = array [0];

    for (int i = 1; i < n; i++) olimpijada [i] = array [i] + olimpijada [i - 1];

    for (int i = n - 1; i > 1; i--) {

        if (olimpijada [i - 1] > array [i]) {
            printf ("%d\n", i + 1);
            return 0;
        }

    }

    printf ("0\n");

    return 0;

}
/*
1 1 4 4 10
*/
