#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double dp[105][105];
pair<int, int> dparg[105][105];
int main() {

    freopen ("in.txt", "r", stdin);

    int n, b1, b2, cases = 0;
    int i, j, k;
    double x[105], y[105];
    while(scanf("%d %d %d", &n, &b1, &b2) == 3) {
        if(n == 0)  break;
        for(i = 0; i < n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        double ret = 1e+60;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                dp[i][j] = 1e+60;
        }
        dp[0][0] = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                k = max(i, j)+1;
                if(k != b2) {
                    if(dp[i][k] > dp[i][j] + hypot(x[k]-x[j], y[k]-y[j])) {
                        dp[i][k] = dp[i][j] + hypot(x[k]-x[j], y[k]-y[j]);
                        dparg[i][k] = make_pair(i, j);
                    }
                }
                if(k != b1) {
                    if(dp[k][j] > dp[i][j] + hypot(x[k]-x[i], y[k]-y[i])) {
                        dp[k][j] = dp[i][j] + hypot(x[k]-x[i], y[k]-y[i]);
                        dparg[k][j] = make_pair(i, j);
                    }
                }
            }
        }
        for(i = 0; i < n; i++) {
            ret = min(ret, dp[i][n-1] + hypot(x[n-1]-x[i], y[n-1]-y[i]));
            ret = min(ret, dp[n-1][i] + hypot(x[n-1]-x[i], y[n-1]-y[i]));
        }
        printf("Case %d: %.2lf\n", ++cases, ret);
        pair<int, int> pre;
        for(i = 0; i < n; i++) {
            if(fabs(dp[i][n-1] + hypot(x[n-1]-x[i], y[n-1]-y[i])-ret) < 1e-8) {
                pre = make_pair(i, n-1);
                break;
            }
            if(fabs(dp[n-1][i] + hypot(x[n-1]-x[i], y[n-1]-y[i])-ret) < 1e-8) {
                pre = make_pair(n-1, i);
                break;
            }
        }
        int path1[105], path2[105], p1 = 0, p2 = 0;
        while(true) {
            i = pre.first, j = pre.second;
            pre = dparg[i][j];
            if(i != pre.first)
                path1[p1++] = i;
            else
                path2[p2++] = j;
            if(pre.first == 0 && pre.second == 0) {
                break;
            }
        }
        printf("0 ");
        if(path2[p2-1] == 1) {
            for(i = p2-1; i >= 0; i--)
                printf("%d ", path2[i]);
            for(i = 0; i < p1; i++)
                printf("%d ", path1[i]);
        } else {
            for(i = p1-1; i >= 0; i--)
                printf("%d ", path1[i]);
            for(i = 0; i < p2; i++)
                printf("%d ", path2[i]);
        }
        puts("0");
    }
    return 0;
}



