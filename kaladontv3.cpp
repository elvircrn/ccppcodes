#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
bool visited [200] [200];
char a [100001] [100];
int n;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%s", &a [i]);
        visited [a [i] [0]] [a [i] [1]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!visited [a [i] [strlen (a [i]) - 2]] [a [i] [strlen (a [i]) - 1]])
            puts (a [i]);
    }
    return 0;
}
