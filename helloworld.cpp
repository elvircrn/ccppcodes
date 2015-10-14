#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int search (int n) {
    int left = 1, right = n, pivot, find;
    while (left <= right) {
        pivot = (left + right) / 2;
        find = ((pivot + 1) * pivot) / 2;
        if (find == n) return 1;
        else if (find < n) left = pivot + 1;
        else right = pivot - 1;
    }
    return 0;
}
int main () {
    int t, n, array [70000];
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) scanf ("%d", &array [i]);
    for (int i = 0; i < t; i++) printf ("%d ", search (array [i]));
    return 0;
}
