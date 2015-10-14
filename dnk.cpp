#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int size [301], dp [301] [301], n, maxi, maxj, cnt, sol, maximum;
char a, dnk [301] [301];
int lcs (int x, int y) {
    if (size [x] < maximum || size [y] < maximum) return 0;
    for (int i = 1; i <= size [x]; i++) {
        for (int j = 1; j <= size [y]; j++) {
            dp [i] [j] = 0;
            if (dnk [x] [i - 1] == dnk [y] [j - 1]) dp [i] [j] = dp [i - 1] [j - 1] + 1;
            else dp [i] [j] = max (dp [i - 1] [j], dp [i] [j - 1]);
        }
    }
    return dp [size [x]] [size [y]];
}
int main () {
    scanf ("%d\n", &n);
    for (int i = 0; i < n; i++) {
        int ind = -1;
        a = getchar();
        ind++;
        while (a != '\n') {
            dnk [i] [ind] = a;
            ind++;
            a = getchar();
        }
        size [i] = ind;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt = lcs (i, j);
            if (cnt > maximum) {
                maxi = i;
                maxj = j;
                maximum = cnt;
            }
            if (cnt == maximum && maxi > i || cnt == maximum && maxi == i && maxj > j) {
                maxi = i;
                maxj = j;
            }
        }
    }
    cout<<dnk [min (maxi, maxj)]<<endl<<dnk [max (maxi, maxj)]<<endl;
    return 0;
}
