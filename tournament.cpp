#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int n, x, ind, A;
class player {
    public:
    int strength; bool istarget;
    player () {istarget = false;}
    player (int s, bool t) {strength = s; istarget = t;}
    bool operator< (const player & xx) const {
        return strength < xx.strength;
    }
};
player players [2000000];
bool trazi;
int main () {
    scanf ("%d %d", &n, &x); x++;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &A);
        players [i] = player (A, ((i) == x));
    }
    sort (players, players + n + 1);
    for (int i = 1; i <= n; i++) if (players [i].istarget) ind = i;
    for (int i = 1; i <= n; i++) if (players [ind].strength < players [i].strength) trazi = true;
    int sol = 0, two = 1, sol1;
    bool found = false;
    if (trazi) cout<<"0 ";
    else cout<<int (log2 (ind))<<" ";
    cout<<int (log2 (ind))<<endl;
    return 0;
}
