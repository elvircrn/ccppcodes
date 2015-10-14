#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;
int tree [201] [201] [201], n, m;
string input;
int sum (int x, int y, int z) {
    int _y, _z, suma = 0;
    while (x) {
        _y = y;
        while (_y) {
            _z = z;
            while (_z) {
                suma += tree [x] [_y] [_z];
                _z -= _z & (-_z);
            }
            _y -= _y & (-_y);
        }
        x -= x & (-x);
    }
    return suma;
}
void set (int x, int y, int z, int s) {
    int _y, _z;
    while (x <= n) {
        _y = y;
        while (_y <= n) {
            _z = z;
            while (_z <= n) {
                tree [x] [_y] [_z] += s;
                _z += _z & (-_z);
            }
            _y += _y & (-_y);
        }
        x += x & (-x);
    }
    return;
}
int q (int x1, int y1, int z1, int x2, int y2, int z2) {
    return sum (x2 , y2 , z2 )- sum (x1 - 1, y2 , z2 )- sum (x2 , y1 - 1, z2 )- sum (x2 , y2 , z1 - 1)+ sum (x1 - 1, y1 - 1, z2 )+ sum (x1 - 1, y2 , z1 - 1)+ sum (x2 , y1 - 1, z1 - 1)- sum (x1 - 1, y1 - 1, z1 - 1);
}
void add (int x, int y, int z) {
    set (x, y, z, 1 - q (x, y, z, x, y, z));
    //set (x + 1, y + 1, z + 1, -1 - q (x + 1, y + 1, z + 1, x + 1, y + 1, z + 1));
    return;
}
int main () {
    //freopen ("z-green.txt", "r", stdin);
    int x, y, z, x1, y1, z1, x2, y2, z2;
    scanf ("%d %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        cin>>input;
        if (input [0] == 'A') {
            scanf ("%d %d %d", &x, &y, &z);
            add (x, y, z);
        }
        if (input [0] == 'Q') {
            scanf ("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            printf ("%d \n", q (x1, y1, z1, x2, y2, z2));
        }
    }
    return 0;
}
