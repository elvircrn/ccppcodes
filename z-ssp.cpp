#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define SQRT 160
#define INF 1<<27

int A, B, dp [30000], cnt, k;
bool primes [30000];
vector <int> coins;

bool check (int x) {
    bool solution = false;
    if (dp [x] == 1) return false;
    dp [x] = INF;

    for (int i = 0; i < coins.size(); i++) {
        if ((x - coins [i]) < 0) break;

        if (dp [x - coins [i]] == INF) continue;

        if ((dp [x - coins [i]] + 1) <= k) {
            dp [x] = min (dp [x], dp [x - coins [i]] + 1);
            if (dp [x] > 1) solution = true;
        }
    }

    return solution;
}

int main () {
    for (int i = 0; i < 25000; i++) {dp [i] = INF; primes [i] = true;}

    scanf ("%d %d %d", &A, &B, &k);

    for (int i = 2; i <= SQRT; i++) {
        if (primes [i]) {
            coins.push_back (i * i);
            for (int j = i * i; j <= 20000; j += i) primes [j] = false;
        }
    }

    dp [0] = 0;

    for (int i = 1; i <= B; i++)
        if (check (i) && i >= A) {
            cnt++;
        }

    printf ("%d\n", cnt);

    return 0;
}
