#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main () {
    srand((unsigned)time(0));
    while (true) {
        int randomint = rand();
        cout<<randomint<<endl;
    }
    return 0;
}
