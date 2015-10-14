#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int triangle [101] [101];
int dpup [101] [101];
int dpdown [101] [101];
int dp [101] [101];
char a;
int jj, n, field [101] [101];

int main ()
{
    //freopen ("unos.txt", "r", stdin);
    //freopen ("izlaz.txt", "w", stdout);
    cin>>n; a = getchar();
    int cnt = 0;
    while (n) {
        cnt++;
        for (int i = 1; i <= n; i++) {
            a = getchar();
            jj = 1;
            while (a != '\n') {
                if (a == '#') triangle [i] [jj] = 0;
                else if (a == '-') triangle [i] [jj] = 1;
                a = getchar();
                jj++;
            }
        }
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j < 2 * n - i + 1; j++) {
                dp [i] [j] = 0;
                if (i == 1) dp [i] [j] = triangle [i] [j];
                else {
                    if (!triangle [i] [j]) continue;
                    dp [i] [j] = min (dp [i - 1] [j], min (dp [i - 1] [j - 1], dp [i - 1] [j + 1])) + 1;
                    maxn = max (maxn, dp [i] [j]);
                }
            }
        }
        printf ("Triangle #%d\nThe largest traingle area is %d.\n\n", cnt, (((2 * maxn) - 1) * ((2 * maxn) - 2)) / 2 - 1);
        //cout<<(((2 * maxn) - 1) * ((2 * maxn) - 2)) / 2 - 1<<endl;
        cin>>n;
        a = getchar();
    }
    return 0;
}












