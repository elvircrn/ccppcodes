#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int array [6];
int main () {
    for (int i = 0; i < 5; i++) {
        scanf ("%d", &array [i]);
    }
    bool promjena = true;
    while (promjena) { promjena = false;
    for (int i = 0; i < 4; i++) {
        promjena = false;
        if (array [i] > array [i + 1]) {
            promjena = true;
            swap (array [i], array [i + 1]);
            for (int i = 0; i < 4; i++) printf ("%d ", array [i]);
            printf ("%d\n", array [4]);
            for (int i = 0; i < 5; i++) if (array [i] != i + 1) goto l1;
            goto l2;
        }
    }
        l1:;
    }
    l2:;
    for (int i = 0; i < 4; i++) printf ("%d ", array [i]);
    printf ("%d\n", array [4]);
    return 0;
}
