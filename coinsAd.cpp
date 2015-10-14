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
// 07       07      04
// dp + greedy + index

typedef long long int ull;

ull dp [7000010], coins [200], x, y, n, indexofgreedy = 0, SOLUTION;

void setdp (int ind, ull value) {
    dp [ind] = value *  + (dp [ind] % 1<<24);
}

void setgreedy (int ind, ull value) {
    dp [ind] = (dp [ind] / 1<<24) + value * 1<<24 + (dp [ind] % 1<<24);
}


void setind (int ind, int Ind) {
    dp [ind] = (dp [ind] / 1<<24) * 1<<24 + ull (Ind);
}

ull getdp (int ind) {
    return ull (dp [ind] / ull (1<<24));
}

ull getgreedy (int ind) {
    return ((dp [ind] / ull (1<<24)) % 1<<24);
}

ull getind (int ind) {
    if (ind == 0) return 0;
    return dp [ind] % 1<<24;
}

ull array [300];

int main () {

    cin>>n;
    for (int i = 0; i < n; i++) cin>>coins [i];
    sort (coins, coins + n);
    cin>>x>>y;

    for (int i = 1; i <= y; i++) {

        //if (i > coins [indexofgreedy] && i >= coins [indexofgreedy + 1] && i != 1 && indexofgreedy + 1 < n) indexofgreedy++;
        while (i >= coins [indexofgreedy] && indexofgreedy < n) indexofgreedy++;

        setgreedy  (i, getgreedy (i - coins [indexofgreedy - 1]) + 1);

        for (int j = 0; j < n; j++) {

            if (i - coins [j] < 0) break;

            if (!getdp (i) || getdp (i - coins [j]) + 1 < getdp (i)) {
                setdp (i, getdp (i - coins [j]) + 1);
                setind (i, j);
            }

        }

        if (i > x && getdp (i) < getgreedy (i)) {
            SOLUTION = i;
            break;
        }

    }

    int ind = getind (SOLUTION);

    printf ("%lld\n", SOLUTION);

    while (ind) {
        array [ind]++;
        ind = getind (SOLUTION - coins [ind]);
        SOLUTION -= coins [ind];
    }

    for (int i = 0; i < n; i++) printf ("%lld ", array [i]);
    printf ("\n");

    return 0;

}
/*
5
1 2 5 7 10
1 100
*/
