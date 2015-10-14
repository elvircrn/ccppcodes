#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n;

char c;
bool used [300] [20];
int DigitCount [11], count2 [100], array [10000], solution;

vector <int> permute;

int main () {

    scanf ("%d", &t);

    while (t--) {

        solution = 0;
        memset (DigitCount, sizeof DigitCount, 0);

        while (!isdigit (c = getchar()));
        DigitCount [c - '0']++;

        while (isdigit (c = getchar())) {
            DigitCount [c - '0']++;
        }

    }

    return 0;
}
