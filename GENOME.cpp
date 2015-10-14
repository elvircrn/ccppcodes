#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char jedan [200000], dva [200000];
int fault, s1, s2, fault2;
int hash1 [1000], hash2 [1000];

int main () {
    scanf ("%s %s", &jedan, &dva);
    if (strlen (jedan) != strlen (dva)) {printf ("NO\n"); return 0;}
    s1 = strlen (jedan); s2 = strlen (dva);
    for (int i = 0; i < s1; i++) hash1 [jedan [i]]++;
    for (int i = 0; i < s2; i++) hash2 [dva [i]]++;
    for (int i = 0; i < 300; i++) {
        if (hash1 [i] != hash2 [i]) fault++;
    }
    if (fault) {printf ("NO\n"); return 0;}
    for (int i = 0; i < s1; i++) {
        if (jedan [i] != dva [i]) {
            fault2++;
        }
    }
    if (fault2 > 2) {printf ("NO\n"); return 0;}
    printf ("YES\n");
    return 0;
}
