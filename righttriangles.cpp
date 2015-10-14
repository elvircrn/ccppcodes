#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char a;
int dp [1011] [1011], dp0 [1011] [1011], dp90 [1011] [1001], dp180 [1011] [1011], dp270 [1011] [1011], n, m, cnt;
int main () {
    scanf ("%d %d", &n, &m);
    a = getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a = getchar();
            //if (a == '.') dp0 [i] [j] = dp90 [i] [j] = dp180 [i] [j] = dp270 [i] [j] = 1;
            if (a == '.') dp [i] [j] = 1;
        }
        a = getchar();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp [i] [j]) continue;
            else {
                dp0 [i] [j] = min (dp0 [i - 1] [j - 1], dp0 [i] [j - 1]) + 1;
                dp90 [i] [j] = min (dp90 [i - 1] [j - 1], dp90 [i - 1] [j]) + 1;
                dp180 [i] [j] = min (dp180 [i - 1] [j + 1], dp180 [i - 1] [j]) + 1;
                dp270 [i] [j] = min (dp270 [i - 1] [(m + 1 - j) - 1], dp270 [i] [(m - j + 1) - 1]) + 1;
            }
            /*if (dp0 [i] [j] == 1 ||
                dp0 [i] [j] == 1 ||
                dp0 [i] [j] == 1 ||
                dp0 [i] [j] == 1) cnt++;*/
            //cnt += dp0 [i] [j] + dp90 [i] [j] + dp180 [i] [j] + dp270 [i] [(m - j) + 1];
            if (dp0 [i] [j] != 1) cnt += dp0 [i] [j];
            if (dp90 [i] [j] != 1) cnt += dp90 [i] [j];
            if (dp180 [i] [j] != 1) cnt += dp180 [i] [j];
            if (dp270 [i] [m - j + 1] != 1) cnt += dp270 [i] [m - j + 1];

        }
    }
    printf ("%d\n", cnt);
    return 0;
}
