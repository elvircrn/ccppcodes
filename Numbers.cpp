#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int array [100000], n, dp [1000000], sol;
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &array [i]);
        dp [i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (array [j] < array [i] && dp [i] < dp [j] + 1) {
                dp [i] = dp [j] + 1;
                sol = max (dp [i], sol);
            }
    printf ("%d \n", sol);
    return 0;
}
