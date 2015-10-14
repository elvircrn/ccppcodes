#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
struct four {
    int x, y, z, l;
    four () {}
    four (int _x, int _y, int _z, int _l) {x = _x; y = _y; z = _z; l = _l;}
    bool operator == (const four & xx) const
    {
        return (x == xx.x && y == xx.y && z == xx.z && l == xx.l);
    }
} array [10001];
int a, b, c, d;
int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%x:%x:%x:%x", &a, &b, &c, &d);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        array [i] = four (a, b, c, d);
    }
    int cnt = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

        }
    }
    return 0;
}
