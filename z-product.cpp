#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char querry [10];
int tree [1400] [1400];
int n, q;
void set (int x1, int y1, int value) {
    int help_y;
    while (x1 <= q) {
        help_y = y1;
        while (help_y <= q) {
            tree [x1] [help_y] += value;
            help_y += (help_y & -help_y);
        }
        x1 += (x1 & -x1);
    }
    return;
}
long long int findsum (int x1, int y1) {
    int help_y = 0;
    long long sum = 0;
    while (x1) {
        help_y = y1;
        while (help_y) {
            sum += tree [x1] [help_y];
            help_y -= help_y & (-help_y);
        }
        x1 -= (x1 & (-x1));
    }
    return sum;
}
long long int sum (int x1, int y1, int x2, int y2) {
    //if (x1 == 1 && y1 == 1) return findsum (x2, y2);
    //if (x1 == x2 && y1 == y2 || x1 == x2 - 1 && y1 == y2 - 1) return tree [x1] [y1];
    return findsum (x2, y2) - (findsum (x2, y1 - 1) + findsum (x1 - 1, y2) - findsum (x1 - 1, y1 - 1));
}
int main () {
    int t;
    int x1, y1, x2, y2, x, y;
    cin>>q;
    while (1) {
        scanf ("%s", &querry);
        if (querry [0] == 'E') break;
        else if (querry [2] == 'T') {
            scanf ("%d %d %d", &x, &y, &n);
            set (x + 1, y + 1, n - sum (x + 1, y + 1, x + 1, y + 1));
        }
        else if (querry [1] == 'U') {
            scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
            cout<<sum (x1 + 1, y1 + 1, x2 + 1, y2 + 1)<<endl;
        }
    }
    return 0;
}
