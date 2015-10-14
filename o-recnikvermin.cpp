#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
struct word {
    string words;
    int old;
    bool operator < (const word & asd) const
    {
        return words < asd.words;
    }
} help, nesto, forsorting [100001];
char s;
int n, indexx = 0, tree [100001];
bool input [100001];
string a;
string in, array [100001];
int convert [100001];
void set (int indd, int val) {
    while (indd <= n) {
        indd += indd & (-indd);
        tree [indd] += val;
    }
    return;
}
int sum (int indd) {
    int suma = 0;
    while (indd) {
        suma += tree [indd];
        indd -= indd & (-indd);
    }
    return suma;
}
int main () {
    cin>>n;
    int ii = 0;
    for (int i = 0; i < n; i++) {
        cin>>a>>array [i];
        string d = array [i];
        for (int ss = 0; ss < d.length(); ss++) {
            array [i] [ss] = tolower (d [ss]);
        }
        if (a == "ADD") {
            nesto.words = array [i];
            nesto.old = indexx;
            forsorting [indexx] = nesto;
            indexx++;
        }
        else input [i] = 1;
    }
    sort (forsorting, forsorting + indexx);
    for (int i = 0; i < indexx; i++) {
        word dsa = forsorting [i];
        convert [dsa.old] = i + 1;
    }
    int ind = 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //cout<<i<<": "<<i<<" "<<input [i]<<" "<<array [i]<<" ind: "<<ind<<" converted ind: "<<convert [ind]<<endl;
        if (!input [i]) {
            ind++;
            for (j = i; j >= 0; j--)
                if (array [i] == array [j])
                    goto novi;
            set (convert [ind] + 1, 1);
            ind--;
            ind++;
        }
        else {
            for (j = 0; j < indexx; j++) {
                word sd = forsorting [j];
                if (array [i] == sd.words) {
                    int s = sum (j + 1);
                    if (s) printf ("%d\n", s);
                    //else printf ("no such word\n");
                }
            }
        }
        novi:;
    }
    return 0;
}
