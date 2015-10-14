#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n, m, matrix [2000] [2000], MINMAX, MIN, MAX;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &matrix [i] [j]);
    for (int i = 0; i < n; i++) {
        MIN = 100000, MAX;
        for (int j = 0; j < m; j++) {
            MIN = min (matrix [j] [i], MIN);
        }
        MINMAX = max (MIN, MINMAX);
    }
    printf ("%d\n", MINMAX);
    return 0;
}
