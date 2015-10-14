#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class A {
public:
    int A [10000];
};

int asd [112032034];

int main () {

    system ("pause");

    A* ptr;

    ptr = new A[1000000];

    delete[] ptr;
    delete[] asd;

    system ("pause");

    return 0;
}
