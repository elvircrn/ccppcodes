#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef unsigned long long int ull;
ull a, b, cnt;
int main () {
    cin>>a>>b;
    for (ull i = 1; i <= 32000; i++) {
        if (i * i >= a && i * i <= b) cnt += i * i;
    }
    cout<<cnt<<endl;
    return 0;
}
