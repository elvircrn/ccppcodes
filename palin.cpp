#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
short dp [5001] [5001];
char c;
int n;
char unos [5001];
int main () {
    scanf ("%d", &n); getchar();
    for (int i = 0; i < n; i++) {c = getchar(); unos [i] = c;}
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp [i] [j] = (unos [i - 1] == unos [n - j] ? dp [i - 1] [j - 1] + 1 : max (dp [i - 1] [j], dp [i] [j - 1]));
    cout<<n - dp [n] [n]<<endl;
    return 0;
}
