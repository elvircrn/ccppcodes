#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, dp [1000] [1000], numbers [1000], maxn;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &numbers [i]);
    }

    for (int i = 1; i <= n; i++)
        dp [i] [i] = numbers [i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i <= n; j++) {
            int leftind = j, rightind = i + j;
            if (i == 2) {dp [leftind] [rightind] = max (numbers [leftind], numbers [rightind]); continue;}
            printf ("%d %d\n", leftind, rightind);
            dp [leftind] [rightind] = max (numbers [leftind] + dp [leftind + 1] [rightind], numbers [rightind] + dp [leftind] [rightind - 1]);
            /*if (numbers [leftind] + dp [leftind + 1] [rightind] <= numbers [rightind] + dp [leftind] [rightind - 1]) {
                dp [i] [j] = min ()
            }*/
            maxn = max (maxn, dp [leftind] [rightind]);
        }
    }
    printf ("%d\n", dp [1] [n]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf ("%d ", dp [i] [j]);
        }
        printf ("\n");
    }
    return 0;
}
/*
4
10 20 1 5
*/

