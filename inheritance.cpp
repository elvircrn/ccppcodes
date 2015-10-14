#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

class A {
public:
    int x;
    A () {}
    A (int _x) {x = _x;}
};

class B : public A {
public:
    int y;
    B () {}
    B (int _y) {y = _y;}
};

void nesto (A a) {

};

int main () {

    B b;

    nesto (b);

    return 0;
}
