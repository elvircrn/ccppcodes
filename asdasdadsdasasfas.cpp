#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <stack>
#include <queue>
#include <map>
const int inf = 1<<20;
using namespace std;
struct coin {
    char denomination;
    int value, index;
    coin () {}
    coin (char _d, int _v, int _idx) {denomination = _d; value = _v; index = _idx;}
    bool operator < (const coin & x) const
    {
        return x.value < value;
    }
};
coin coins [50];
int dp [150051], hash [30], jump [15001], help, hjump [15001];
char a, solution [1000];
int n, m, x;
int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin>>a>>x;
        //cout<<a<<" "<<x<<endl;
        coins [i] = coin (a, x, i);
        hash [x] = i;
    }
    sort (coins, coins + n);
    for (int i = 1; i <= 15000; i++) dp [i] = inf;
    dp [0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins [j].value < 0) continue;
            help = min (dp [i - coins [j].value] + 1, inf);
            if (dp [i] > help) {
                jump [i] = i - coins [j].value;
                dp [i] = help;
                hjump [i] = j;
            }
        }
    }
    jump [0] = jump [1] = 0;
    int k = m, i = 0;
    if (dp [m] == inf) printf ("Q\n");
    else {
        while (k) {
            solution [i] = coins [hjump [k - jump [k]]].denomination;
            //printf ("%c", coins [hjump [k - jump [k]]].denomination);
            k = jump [k];
            i++;
        }
    }
    for (int d = i - 1; d >= 0; d--) printf ("%c", solution [d]);
    return 0;
}

