#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int edge, vertice, dp [1000] [1000], connected [1000] [1000];
int main () {
    int a, b, c;
    scanf ("%d %d", &edge, &vertice);
    for (int i = 0; i < edge; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        connected [a] [b] = c;
        connected [b] [a] = c;
    }
    for (int i = 1; i <= vertice; i++) {
        for (int j = 1; j <= vertice; j++) {
            for (int k = 1; k <= vertice; k++) {
                dp [i] [j] = min (dp [i] [k] + dp [k] [j], dp [i] [j]);
            }
        }
    }
    return 0;
}
