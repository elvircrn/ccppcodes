#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main () {

    system ("pause");

    int* p = new int [123123];

    system ("pause");

    for (i = 1; i <= 100000; i++)
        delete[] (p + i);

    system ("pause");

    return 0;
}
