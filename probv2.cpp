#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isnotprime [500000];
bool visited [2000000];
unsigned long long int x, y, i, cnt = 0, tmp, SQRT;
int main() {
    cin>>x>>y;
    tmp= (y - x) + 1;
    cnt = tmp;
    SQRT = sqrt (y);
    for (int i = 2; i < SQRT + 5; i++) {
        if (!isnotprime [i]) {
            for (int j = i * i; j <= y; j += i) {
                if (j <= SQRT) isnotprime [j] = true;
                if (j >= x && j > 100000) {
                    if (!visited [j - x]) cnt--;
                    visited [j - x] = true;
                }
                else if (j >= x && !visited [j]) {
                    cnt--;
                    visited [j] = true;
                }
            }
        }
    }
    cout<<cnt/__gcd (cnt, tmp)<<"/"<<tmp/__gcd (cnt, tmp)<<endl;
    return 0;
}
/*

*/
