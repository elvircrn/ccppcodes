#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
char a [900];
int n, dp [901] [901];
int diamond [901] [901];
int matrix [901] [901], maxn;
int main () {

    scanf ("%d", &n);
    char aa;
    aa = getchar();
    aa = '0';
    for (int i = 1; i <= n; i++) {
        //gets (a);
        aa = getchar();
        int d = 0;
        while (aa != '\n') {a [d] = aa; d++; aa = getchar();}
        for (int j = 1; j <= n; j++) {
            if (a [j] == toupper (a [j])) {
                dp [i] [j] = 1;
                diamond [i] [j] = 1;
            }
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j <= n - 1; j++) {
            if (dp [i] [j] == 0) {
                continue;
            }
            else if (dp [i] [j] == 1) {
                dp [i] [j] = min (min (dp [i - 1] [j], dp [i - 2] [j]), min (dp [i - 1] [j - 1], dp [i - 1] [j + 1])) + 1;
                maxn = max (dp [i] [j], maxn);
            }
        }
    }
    maxn = 2 * maxn - 1;
    int dva = maxn - 2;
    dva = (dva + 1) / 2;
    dva *= dva;
    maxn = (maxn + 1) / 2;
    maxn *= maxn;
    cout<<maxn + dva<<endl;
    return 0;
}
