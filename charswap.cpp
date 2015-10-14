#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n;
struct letter {
    char character;
    letter () {}
    letter (char a) {character = a;}
    bool operator < (const letter & xx) const
    {
        return character < xx.character;
    }
} up [1000001], down [1000001];
int main () {
    char d;
    scanf ("%d", &n);
    while (!isalpha (d = getchar()));
    up [0] = letter (d);
    for (int i = 1; i < n; i++) {
        d = getchar();
        up [i] = letter (d);
    }
    while (!isalpha (d = getchar()));
    down [0] = d;
    for (int i = 1; i < n; i++) down [i] = letter (getchar());
    sort (up, up + n); sort (down, down + n);
    for (int i = 0; i < n - 1; i++) {
        if (up [i + 1].character != up [i].character && down [i].character == down [i + 1].character || up [i + 1].character != up [i].character && down [i].character == down [i + 1].character) {printf ("NE\n"); return 0;}
    }
    printf ("DA\n");
    return 0;
}
