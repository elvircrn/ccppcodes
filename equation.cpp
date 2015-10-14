#include <iostream>
using namespace std;
int x;
int main () {
    for (int i = -100; i < 101; i++) {
        if(6 - 15 * i + 8 * i * i == 0) {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
