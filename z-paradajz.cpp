#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, d, paradajzovi [210000], solution;

struct paradajz {

    int duration, ind;

    paradajz () {}
    paradajz (int a, int b) {duration = a; ind = b;}

    bool operator < (const paradajz & xx) const {
        return duration > xx.duration;
    }

};

priority_queue <paradajz> Q;

int main () {

    scanf ("%d %d", &n, &d);
    scanf ("%d %d", &a);
    solution += a;
    for (int i = 1; i < n; i++) {
        scanf ("%d", &paradajzovi [i]);
        Q.push (paradajz (paradajzovi [i], i));
        while ((i - Q.front().ind >= d))
        sol += (Q.)

    }

    return 0;
}
