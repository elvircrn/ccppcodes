#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

//#define INF 2147483647
#define INF 10e8

int matrix [1011] [1011], dp2 [1011] [1011], dp5 [1011] [1011], N;

int main () {

    scanf ("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf ("%d", &matrix [i] [j]);
            int M = matrix [i] [j];
            while (M % 2 == 0 && M > 0) {
                dp2 [i] [j]++;
                M /= 2;
            }
            M = matrix [i] [j];
            while (M % 5 == 0 && M > 0) {
                dp5 [i] [j]++;
                M /= 5;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        dp2 [0] [i] = dp2 [i] [0] = dp5 [0] [i] = dp5 [i] [0] = INF;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix [i] [j] == 0)
                dp2 [i] [j] = dp5 [i] [j] = INF;
            else if (i != 1 || j != 1) {
                dp2 [i] [j] = min (dp2 [i - 1] [j], dp2 [i] [j - 1]) + dp2 [i] [j];
                dp5 [i] [j] = min (dp5 [i - 1] [j], dp5 [i] [j - 1]) + dp5 [i] [j];
            }
        }
    }

    /*for (int i = 0; i <= N; i++, printf ("\n"))
        for (int j = 0; j <= N; j++)
            printf ("%d ", dp2 [i] [j]);*/

    printf ("%d\n", min (dp2 [N] [N], dp5 [N] [N]));

    return 0;
}
/*
3
5 2 2
2 2 2
2 2 2

2
2 2
5 5
*/
