#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
 long long int i ( long long int n,  long long int m) {
    return ((m - 1) * (n - 1) - __gcd (n, m)) / 2;
}
 long long int b ( long long int n,  long long int m) {
    return (m + n + 1 + __gcd (n, m));
}
int main () {
     long long int n, m;
    cin>>n>>m;

    if (n && m) cout<<b (n, m) + i (n, m)<<endl;
    else if (!n && !m) cout<<"1"<<endl;
    else cout<<b (n, m) + i (n, m) - 1<<endl;
    return 0;
}
