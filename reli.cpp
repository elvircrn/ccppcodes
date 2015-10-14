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

int solution, cnt = 1, array [100010], n, hash [100010], BIT [100010];

int myAbs (int x) {
    return (x < 0) ? (x * -1) : x;
}

int sum (int ind) {
    int ret = 0;
    while (ind) {
        ret += BIT [ind];
        ind -= ind & (-ind);
    }
    return ret;
}

void set (int val, int ind) {

}

int main () {

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &array [i]);
        hash [array [i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        solution += myAbs (array [i] - i);
        cout<<array [i] - i<<endl;
    }

    printf ("%d\n", solution);

    return 0;
}
