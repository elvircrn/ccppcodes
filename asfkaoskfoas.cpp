#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int x;
    cin>>x;
    for (int N = 1; N <= 10000; N += 2) {
        if ((N * N) / 2 + (N % 4) >= x) {
            cout<<N<<endl;
            return 0;
        }
    }
    return 0;
}
