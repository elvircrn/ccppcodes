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

int h, n, I, solution;
vector <int> up;
vector <int> down;

int BinarySearch (int heightTop) {

    int newHeight = h - heightTop, leftb = 0, rightb = down.size(), pivot;

    while (leftb <= rightb) {
        pivot = (leftb + rightb) / 2;
        if (newHeight < down [pivot] && newHeight >= down [pivot - 1])
            return pivot;
        else if (newHeight < down [pivot])
            rightb = pivot - 1;
        else
            leftb = pivot + 1;
    }

    return -1;
}

int main () {

    scanf ("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &I);
        if (i % 2 == 0)
            down.push_back (I);
        else
            up.push_back (I);
    }

    sort (up.begin(), up.end());
    sort (down.begin(), down.end());

    int helper = 0;

    for (int i = up.size() - 1; i > -1; i--) {
    }

    return 0;
}
/*
up [6] : 4
down [1] : 2

up [5] : 4
down [1] : 2

up [4] : 3
down [2] : 3

up [3] : 3
down [2] : 3

up [2] : 3
down [2] : 3

up [1] : 2
down [6] : 4

up [0] : 2
down [6] : 4
*/
