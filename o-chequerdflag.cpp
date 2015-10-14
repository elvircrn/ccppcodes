#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool  help, hands;
int x, y, cnt, crno, bijelo;
char array [3001] [3001], a;
int main () {
    scanf ( "%d %d", &x, &y );
    for ( int i = 0; i < x; i++ ) {
        scanf ("%s", &array [i]);
        for ( int j = 0; j < y; j++ ) {
            a = array [i] [j];
            //if (a == 'C') matrix [i] [j] = 1;
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    if (a == 'B') {
                        crno++;
                    }
                }
                else if (j % 2 == 1) {
                    if (a == 'C') {
                        crno++;
                    }
                }
            }
            else if (i % 2 == 1) {
                if (j % 2 == 0) {
                    if (a == 'C') {
                        crno++;
                    }
                }
                else if (j % 2 == 1) {
                    if (a == 'B') {
                        crno++;
                    }
                }
            }


            if (i % 2 == 1) {
                if (j % 2 == 0) {
                    if (a == 'B') {
                        bijelo++;
                    }
                }
                else if (j % 2 == 1) {
                    if (a == 'C') {
                        bijelo++;
                    }
                }
            }
            else if (i % 2 == 0) {
                if (j % 2 == 0) {
                    if (a == 'C') {
                        bijelo++;
                    }
                }
                else if (j % 2 == 1) {
                    if (a == 'B') {
                        bijelo++;
                    }
                }
            }
        }
    }
    printf ("%d\n", min (crno, bijelo));
    return 0;
}
