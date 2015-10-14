#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, boxes [1000];
bool nasao;

int main () {

    int t =3;

    while (t--) {

        scanf ("%d", &n);

        nasao = false;

        for (int i = 0; i < n; i++) {

            scanf ("%d", &boxes [i]);

            if (boxes [i] == 1)
                nasao = true;

        }

        if (nasao == true) {
            printf ("1\n");
            continue;
        }

        int maxn, ind, movecount = -1;

        while (true) {

            movecount++; maxn = 0;

            for (int i = 0; i < n; i++) {

                if (boxes [i] == 1) {
                    printf ("%d\n", movecount % 2 + 1);
                    goto novi;
                }

                if (maxn < boxes [i]) {
                    maxn = boxes [i];
                    ind = i;
                }

            }

            boxes [ind]--;

        }

        novi:;

    }

    return 0;
}
