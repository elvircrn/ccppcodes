#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool isnotprime [2000000001];
int main() {
    unsigned long long int x, y, i, cnt = 0, tmp;
    cin>>x>>y;
    for (int i = 2; i <= sqrt (y); i++) {
        if (!isnotprime [i]) {
            for (int j = i + i; j <= y; j += i) {
                isnotprime [j] = true;
            }
        }
    }
    tmp= ( y - x ) + 1;
    if (x % 2 == 0) x++;

    for (i = x; i <= y; i += 2)
        if (!isnotprime [i])
           cnt++;

    cout<<cnt/__gcd ( cnt , tmp )<<"/"<<tmp/__gcd ( cnt, tmp )<<endl;
}
