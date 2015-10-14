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

bool connection [300] [300];
int N;
char rna [1000];

void rek ()

int main () {

    bool used [252];
    memset (used, false, sizeof used);

    rna ['A'] ['U'] = true;
    rna ['U'] ['A'] = true;
    rna ['C'] ['G'] = true;
    rna ['G'] ['C'] = true;
    rna ['G'] ['U'] = true;
    rna ['U'] ['G'] = true;

    scanf ("%d %s", &N, &rna);

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (moze [rna [i]] [rna [j]]) {

                used [i] = true;
                used [j] = true;



            }
        }
    }

    return 0;
}
