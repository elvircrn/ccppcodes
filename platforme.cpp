#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct platform {
    int y, x1, x2;
    platform () {}
    platform (int _y, int _x1, int _x2) {y = _y; x1 = _x1; x2 = _x2;}
} platforms [200], help, one, two;
int n, a, b, c, cnt, sol, maxleft, maxright, maxindleft, maxindright;
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        maxleft = maxright = maxindleft = maxindright = 0;
        scanf ("%d %d %d", &a, &b, &c);
        platforms [i] = platform (a, b, c);
        if (i == 1) {sol += a * 2; /*printf ("%d\n", sol); */continue;}
        else {
            for (int j = i - 1; j >= 1; j--) {
                one = platforms [i], two = platforms [j];
                if (one.y > two.y) {
                    if (one.x1 > two.x1 && one.x1 < two.x2) {
                            if (maxleft < two.y) {
                                maxindleft = j;
                                maxleft = two.y;
                            }
                    }
                    if (one.x2 > two.x1 && one.x2 <= two.x2) {
                        if (one.y > two.y) {
                            if (maxright < two.y) {
                                maxindright = j;
                                maxright = two.y;
                            }
                        }
                    }
                }
            }
        }
        if (maxindleft) sol += (platforms [i].y - maxleft);
        else sol += platforms [i].y;
        if (maxindright) sol += (platforms [i].y - maxright);
        else sol += platforms [i].y;
        printf ("%d\n", sol);
    }
    return 0;
}
