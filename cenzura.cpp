#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool used [300001];
char A [30], T [300001];
int leftind, rightind;

bool leftright () {
    int j;
    for (int i = leftind; i <= rightind; i++) {

        if (T [i] == A [0]) {
            bool nasao = true;

            for (j = i; j < i + strlen (A); j++) {
                if (T [j] != A [j - i]) {
                    nasao = false;
                    break;
                }
            }

            if (nasao == true) {
                for (int k = i; k < j; k++)
                    used [k] = true;
                leftind = leftind + strlen (A) + strlen (A);
                i = i + strlen (A) - 1;
                return true;
            }
        }
    }

    return false;

}

bool rightleft () {
    int j;
    for (int i = rightind; i >= leftind; i--) {
        used [i] = true;
        if (T [i] == A [strlen (A) - 1]) {
            bool nasao = true;
            for (j = i; j > i - strlen (A); j--) {
                if (T [j] != A [strlen (A) - (i - j) - 1]) {
                    nasao = false;
                    break;
                }
            }
            if (nasao) {
                for (j = i; j > i - strlen (A); j--)
                    used [j] = true;
                    return true;
            }
        }
    }
    return false;
}

int main () {

    scanf ("%s %s", &A, &T); rightind = strlen (T) - 1;

    /*
    while (true) {
        if (leftright () == false) break;
        if (rightleft () == false) break;
    }
    */

    rightleft();

    for (int i = 0; i < strlen (T); i++)
        if (used [i] == false)
            putchar (T [i]); putchar ('\n');

    return 0;

}
/*
ne
DneDneDneDne
*/
