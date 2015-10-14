#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector <int> V;
int x;

void myFunction (int x) {
    cout<<x<<endl;
}

template <class startPointer, class endPointer, class Function>
void foreach (startPointer first, endPointer last, Function ff) {
    for (; first != last; first++) ff (*first);
}

/*
#define foreach(first,last,element) for(;first!=last;first++){element=*first;
*/

int main () {

    int Array [80], elvir;

    Array [0] = 1;
    Array [1] = 2;
    Array [2] = 3;
    Array [3] = 4;
    Array [4] = 5;

    foreach (Array, Array + 5, myFunction);

    /*int *s = array, *e = array + (sizeof (array) / 4 - 1);

    int ja = 3;

    foreach(s, e, elvir)
        printf ("%d\n", elvir);
    }*/

    return 0;
}
