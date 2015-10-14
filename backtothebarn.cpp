#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int dirx [] = {1, 0, -1, 0};
int diry [] = {0, 1, 0, -1};
int cnt, X, Y, matrix [100] [100], r, c, k, dp [100] [100];
char a;
int rec (int a, int b, int stamina, bool visited [5] [5]/*, int x*/) {
    //cout<<a<<" "<<b<<" "<<cnt<<" stamina: "<<stamina<<endl;
    if (stamina < 0 || visited [a] [b]) {visited [a] [b] = 0; return 0;}
    if (a == 1 && b == c) {visited [a] [b] = 0; return 1;}
    for (int i = 0; i < 4; i++) {
        X = dirx [i] + a;
        Y = diry [i] + b;
        if (X < 1 || Y < 1 || X > r || Y > c || stamina < 1 || matrix [X] [Y]) continue;
        visited [a] [b] = 0;
        cnt += rec (X, Y, stamina - 1, visited/*, i*/);
    }
    return 0;
}
int main () {
    bool visited [5] [5];
    scanf ("%d %d %d", &r, &c, &k);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            visited [i - 1] [j - 1] = 0;
            visited [i] [j] = 0;
            cin>>a;
            if (a == 'T') matrix [i] [j] = 1;
        }
    }
    rec (r, 1, k, visited/*, 0*/);
    cout<<cnt<<endl;
    return 0;
}
/*
3 4 6
....
.T..
....
*/
