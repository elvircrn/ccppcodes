#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int matrix [500] [500], n, sum [500] [500], maximum, cnt, lijevo, desno;
int main () {
    //freopen ("unos.txt", "r", stdin);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf ("%d", &matrix [i] [j]);
            sum [i] [j] = matrix [i] [j] + sum [i - 1] [j + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            lijevo = 0;
            for (int k = 0; k <= n; k++) {
                if (i + k > n || j + k > n) break;
                else {
                    desno = sum [i + k] [j] - sum [i - 1] [j + k + 1];
                    lijevo += matrix [i + k] [j + k];
                    maximum = max (maximum, lijevo - desno);
                }
            }
        }
    }
    printf ("%d\n", maximum);
    return 0;
}
