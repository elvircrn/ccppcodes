#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int ull;

ull startx, starty, endx, endy, n, m, k, SOLUTION;
char field [100] [100];
bool visited [100] [100];

ull dirx [4] = {-1, 0, 1, 0};
ull diry [4] = {0, 1, 0, -1};

void dfs (ull x, ull y, ull progress) {

    if (x == endx && y == endy) {SOLUTION++; return;}
    else if (progress == k) return;

    for (ull i = 0; i < 4; i++) {

        ull X = x + dirx [i], Y = y + diry [i];
        if (field [X] [Y] == 'T' || X < 0 || Y < 0 || X >= n || Y >= m || visited [X] [Y] == true) continue;

        visited [X] [Y] = true;
        dfs (X, Y, progress + 1);
        visited [X] [Y] = false;

    }

    return;

}

int main () {

    cin>>n>>m>>k;

    startx = n - 1; starty = 0; endx = 0; endy = m - 1;

    for (int i = 0; i < n; i++) cin>>field [i];

    visited [startx] [starty] = true;
    dfs (startx, starty, 1);

    cout<<SOLUTION<<endl;

    return 0;

}
/*
5 5 25
.....
.....
.....
.....
.....
*/
