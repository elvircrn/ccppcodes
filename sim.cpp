#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int x;
    cin>>x;
    int base = 1;
    if (x % 4 > 1 && x > 2) base = 5;
    for (int N = base; N <= 10000; N += 2) {
        if ((N * N) / 2 > x) {
            cout<<N<<endl;
            return 0;
        }
    }
    /*if (x == 4) {
        cout<<"3"<<endl;
        return 0;
    }
    for (int i = 3; i <= 1000; i += 2) {
        if ((i - 2) * 4 - ((x % 4) % 2) > x) {
            cout<<i<<endl;
            return 0;
        }
    }*/
    return 0;
}
