#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dd;
char prviniz [201] [501];
int SOLUTION [501], pivot, n, m;
struct rijec {
    char STRING [501];
    int past_ind;
    rijec () {}
    rijec (char r [], int _i) {strcpy (STRING, r); past_ind = _i;}
    bool operator < (const rijec & xx) const
    {
        if (strcmp (STRING, xx.STRING) == -1) return 0;
        else return 1;
    }
} rijeci [201];
char a [501];
void bs (char word []) {
    int leftb = 0, rightb = n, pivot;
    while (leftb <= rightb) {
        //cout<<leftb<<" "<<rightb<<endl;
        pivot = (leftb + rightb) / 2;
        if (strcmp (word, rijeci [pivot].STRING) == 0) {SOLUTION [rijeci [pivot].past_ind]++; return;}
        else if (strcmp (word, rijeci [pivot].STRING) == 1) rightb = pivot - 1;
        else leftb = pivot + 1;
    }
    return;
}
int main () {
    string word;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%s", &a);
        rijeci [i] = rijec (a, i);
    }
    sort (rijeci, rijeci + n);
    for (int i = 0; i < m; i++) {
        scanf ("%s", &a);
        bs (a);
    }
    for (int i = 0; i < n; i++) cout<<SOLUTION [i]<<endl;
    return 0;
}
