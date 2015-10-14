#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int first, sum;

int recursion (int Target, int Digits, int progress, int digitCount) {

    if (Digits == digitCount && progress == Target)
        return 1;
    else if (Digits == digitCount)
        return 0;
    else {
        for (int i = 0 + first; i < 10; i++)
            if (recursion (Target, Digits, progress + i, digitCount + 1))
                sum++;

        first = 0;
    }

}

int main () {

    first = 1;
    recursion (7, 3, 0, 0);

    printf ("%d\n", sum);

    return 0;
}
