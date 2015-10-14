#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, array [5001], help [5000], interval, maxsum, cnt;
int hash [9000001];
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &array [i]);
        help [i] = help [i - 1] + array [i];
    }
    for (int i = 1; i <= n; i++) {
        interval = array [i];
        hash [interval]++;
        if (hash [interval] > cnt) {
            cnt = hash [interval];
            maxsum = interval;
        }
        else if (hash [interval] == cnt && interval > maxsum)
            maxsum = interval;
        if (i == n) continue;
        for (int j = i + 1; j <= n; j++) {
            interval = help [j] - help [i - 1];
            hash [interval]++;
            if (hash [interval] > cnt) {
                cnt = hash [interval];
                maxsum = interval;
            }
            else if (hash [interval] == cnt && interval > maxsum)
                maxsum = interval;
        }
    }
    cout<<maxsum<<" "<<cnt<<endl;
    return 0;
}
