#include <iostream>
using namespace std;
typedef long long int ull;
ull a, b, k, fa, fb;
int main () {
    cin>>a>>b>>k;
    if (a == 0 && b == 0) {cout<<"1"<<endl; return 0;}
    if (a == 0) fa = -1;
    else fa = (a - 1) / k;
    fb = b / k;
    cout<<fb - fa<<endl;
    return 0;
}
