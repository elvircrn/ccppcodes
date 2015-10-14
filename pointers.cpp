#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void f (int &var) {
    var = 2;
    cout<<var<<endl;
}

int main () {
    int x = 4;
    f (x);
    cout<<x<<endl;
    return 0;
}
