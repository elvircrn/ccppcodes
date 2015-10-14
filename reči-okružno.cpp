#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, solution;
char slagalica [200] [20], Q [200];
bool visited [210];

int process (int ind) {
    int nesto = strlen (slagalica [ind]);
    memset (visited, false, sizeof visited);
    for (int i = 0; i < strlen (slagalica [ind]); i++) {
        bool found = true;
        for (int j = i; j < i + strlen (Q); j++) {
            if (Q [j - i] != slagalica [ind] [j]) {
                found = false;
                break;
            }
            if (j == n && j < i + strlen (Q)) {
                found = false;
                break;
            }
        }
        if (found) {
            for (int j = i; j < i + strlen (Q); j++) {
                if (!visited [j]) {
                    nesto--;
                    visited [j] = true;
                    if (nesto == 0)
                        return 1;
                }
            }
        }
    }
    if (nesto == 0) return 1;
    else return 0;
}

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%s", &slagalica [i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%s", &Q);
        solution += process (i);
        cout<<solution<<endl;
    }

    printf ("%d\n", solution);

    return 0;

}
