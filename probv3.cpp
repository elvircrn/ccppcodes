#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isnotprime [5000000];
unsigned long long int x, y, i, cnt = 0, tmp;
vector <int> past;
int main() {
    cin>>x>>y;
    tmp= (y - x) + 1;
    cnt = tmp;
    for (int i = 2; i < sqrt (y) + 5; i++) {
    }
    cout<<cnt/__gcd (cnt, tmp)<<"/"<<tmp/__gcd (cnt, tmp)<<endl;
}
