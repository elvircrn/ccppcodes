#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <new>

using namespace std;

char unos [1000];
bool useable [1000];
int LEFT, RIGHT;
bool nasao = true;

int main () {
    scanf ("%s", &unos);
    for (int i = 0; i < 1000; i++) useable [i] = true;
    for (int i = 0; i < strlen (unos); i++) {
        if (unos [i] == ')' && useable [i]) {
            useable [i] = false;
            for (int j = i - 1; j > -1; j--) {
                if (useable [j] && unos [j] == '(') {
                    useable [j] = false;
                    break;
                }
            }
            for (int j = 0; j < strlen (unos); j++)
                if (useable [j])
                    putchar (unos [j]);
            putchar ('\n');
        }
    }
    return 0;
}
