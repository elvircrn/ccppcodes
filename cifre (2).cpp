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
typedef long long int ull;

ull array [30];

ull pow (ull a, ull b) {
    if (b == 0) return 1;
    ull ret = 1;
    for (ull i = 0; i < b; i++)
        ret *= a;
    return ret;
}

ull calculate (ull x) {
    return (((pow (10, x) - 1) - (pow (10, x - 1)) + 1) * x);
}

ull calculate (ull x, ull y) {
    return (y - calculate (x - 1));
}

ull racunajBroj (int x) {

    ull sum = 0;

    for (int i = 1; i <= 9; i++) {
        sum += array [i];
        if (sum >= x) {
            int nesto = sum - x;
            int broj = pow (10, i - 1) + nesto / i - 1;
            return broj;
        }
    }

}

int main () {

    ull x;

    cin>>x;

    /*for (int i = 1; i <= 9; i++)
        array [i] = calculate (i);

    ull nesto = racunajBroj (x);

    ull d = x;

    while (nesto == racunajBroj (x--));
    */

    cout<<racunajBroj (x)<<endl;

    return 0;
}
