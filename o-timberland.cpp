#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

char Q [110];
int n, q, a, b, c, field [110] [110], dp [110] [110];

inline bool check_tree (int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return false;
    return (dp [x1] [y1] + dp [x2] [y2] == dp [x1] [y2] + dp [x2] [y1]);
}

inline bool find_field (int x, int y) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp [i] [j] = field [i] [j] + dp [i - 1] [j] + dp [i] [j - 1] - dp [i - 1] [j - 1];
            if (field [i] [j] == 1) continue;
            if (check_tree (i - x, j - y, i, j)) {
                return true;
            }
            if (check_tree (i - y, j - x, i, j)) {
                return true;
            }
        }
    }

    return false;
}



int main () {

    scanf ("%d %d", &n, &q);

    for (int i = 0; i < q; i++) {

        scanf ("%s", &Q);

        if (Q [0] == 'v') {

            scanf ("%d", &a);

            bool found = false;
            int S = sqrt (double (a));

            for (int j = 1; j <= S; j++) {
                if (a % j == 0) {
                    if (find_field (j, a / j)) {
                        found = true;
                        break;
                    }
                }
            }

            if (found == true)
                puts ("yes");
            else
                puts ("no");

        }

        else if (Q [0] == 'g') {
            scanf ("%d %d", &a, &b);
            field [a] [b] = 1;
        }

        else if (Q [0] == 'c') {
            scanf ("%d %d", &a, &b);
            field [a] [b] = 0;
        }

    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp [i] [j] = field [i] [j] + dp [i - 1] [j] + dp [i] [j - 1] - dp [i - 1] [j - 1];

    return 0;

}
