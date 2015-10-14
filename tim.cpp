#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct player {
    int ind, str;
    player () {}
    player (int _i, int _s) {ind = _i; str = _s;}
    bool operator < (const player & x) const
    {
        return str < x.str;
    }
} one, two;
int a, n;
player players [1000000];
vector <int> player1;
vector <int> player2;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n + 1; i++) {
        scanf ("%d", &a);
        players [i] = player (i, a);
    }
    sort (players, players + n);
    for (int i = 1; i < n + 1; i++) {
        if (i % 2 == 0) player1.push_back (players [i].ind);
        else player2.push_back (players [i].ind);
    }
    printf ("%d\n", player1.size());
    for (int i = 0; i < player1.size(); i++) printf ("%d ", player1 [i]);
    printf ("\n%d\n", player2.size());
    for (int i = 0; i < player2.size(); i++) printf ("%d ", player2 [i]);
    return 0;
}
