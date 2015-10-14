#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int boxes [1000] [5], n, cnt, sum [1000], minimum [1000], solution;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%d", &boxes [i] [j]);
            sum [j] += boxes [i] [j];
            minimum [j] = max (minimum [j], boxes [i] [j]);
        }
    }

    for (int i = 0; i < n; i++) solution += sum [i] - minimum [i];

    printf ("%d\n", solution);

    return 0;
}
