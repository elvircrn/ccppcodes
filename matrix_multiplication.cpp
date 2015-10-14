/*
3
1 3
3 5
5 4

35
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int inf = 1<<28;
int dp [1000] [1000], a [1000], b [1000], n;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < 999; i++)
        for (int j = 0; j < 999; j++)
            if (i == j) continue;
            else dp [i] [j] = inf;
    for (int i = 0; i < n; i++) cin>>a [i]>>b [i];
    cout<<endl;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            for (int k = j; k < j + i; k++) {
                dp [j] [j + i - 1] = min (dp [j] [j + i - 1], dp [j] [k] + dp [k + 1] [j + i - 1] + a [j] * b [k] * b [j + i - 1]);
            }
        }
    }
    printf ("%d \n", dp [0] [n - 1]);
    return 0;
}
