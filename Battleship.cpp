#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int getRandomInt () {
    return (rand () % 10 + 1);
}

int getRandomDirection () {
    return (rand () % 2);
}

struct par {
    int x, y;
    par () {}
    par (int _x, int _y) {x = _x; y = _y;}
};

vector <par> parovi;

int D, field [20] [20], A, B, ind, shipcountforsetting;

int ships [10] = {0, 2, 2, 3, 3, 4, 4, 5};

bool found, gore, dole;

int main () {
    srand (time (0));
    shipcountforsetting = 7;
    ind = 1;
    while (shipcountforsetting) {
        int COPY = ships [ind] - 1;
        while (field [A = getRandomInt()] [B = getRandomInt()]);
        D = getRandomDirection();
        if (D) {
            for (int i = 1; i <= ships [ind]; i++) {
                if (field [A - i - 1] [B] || field [A - i] [B] || !(A - i)) gore = true;
                if (field [A + i + 1] [B] || field [A + i] [B] || (A + i) > 10) dole = true;
                if (not gore) {parovi.push_back (par (A - i, B)); COPY--;}
                if (!COPY) {found = true; break;}
                if (not dole) {parovi.push_back (par (A + i, B)); COPY--;}
                if (!COPY) {found = true; break;}
            }
            if (found) {
                for (int i = parovi.size() - 1; i >= 0; i--) {
                    field [parovi [i].x] [parovi [i].y] = ind;
                    parovi.pop_back();
                }
                field [A] [B] = ind;
                shipcountforsetting--; ind++;
                gore = dole = found = false;
                goto l1;
            }
        }
        else {
            for (int i = 1; i <= ships [ind]; i++) {
                    if (field [A] [B - i - 1] || field [A] [B - i] || !(B - i)) gore = true;
                    if (field [A] [B + i + 1] || field [A] [B + i] || (B + i) > 10) dole = true;
                    if (not gore) {parovi.push_back (par (A, B - i)); COPY--;}
                    if (!COPY) {found = true; break;}
                    if (not dole) {parovi.push_back (par (A, B + i)); COPY--;}
                    if (!COPY) {found = true; break;}
                }
                if (found) {
                    for (int i = parovi.size() - 1; i >= 0; i--) {
                        field [parovi [i].x] [parovi [i].y] = ind;
                        parovi.pop_back();
                    }
                    field [A] [B] = ind;
                    shipcountforsetting--; ind++;
                    gore = dole = found = false;
                    goto l1;
                }
        }
        if (not found) {
            if (!D) {
                for (int i = 1; i <= ships [ind]; i++) {
                    if (field [A - i - 1] [B] || field [A - i] [B] || !(A - i)) gore = true;
                    if (field [A + i + 1] [B] || field [A + i] [B] || (A + i) > 10) dole = true;
                    if (not gore) {parovi.push_back (par (A - i, B)); COPY--;}
                    if (!COPY) {found = true; break;}
                    if (not dole) {parovi.push_back (par (A + i, B)); COPY--;}
                    if (!COPY) {found = true; break;}
                }
                if (found) {
                    for (int i = parovi.size() - 1; i >= 0; i--) {
                        field [parovi [i].x] [parovi [i].y] = ind;
                        parovi.pop_back();
                    }
                    field [A] [B] = ind;
                    shipcountforsetting--; ind++;
                    gore = dole = found = false;
                    goto l1;
                }
            }
            else {
                for (int i = 1; i <= ships [ind]; i++) {
                    if (field [A] [B - i - 1] || field [A] [B - i] || !(B - i)) gore = true;
                    if (field [A] [B + i + 1] || field [A] [B - i] ||(B + i) > 10) dole = true;
                    if (not gore) {parovi.push_back (par (A, B - i)); COPY--;}
                    if (!COPY) {found = true; break;}
                    if (not dole) {parovi.push_back (par (A, B + i)); COPY--;}
                    if (!COPY) {found = true; break;}
                }
                if (found) {
                    for (int i = parovi.size() - 1; i >= 0; i--) {
                        field [parovi [i].x] [parovi [i].y] = ind;
                        parovi.pop_back();
                    }
                    field [A] [B] = ind;
                    shipcountforsetting--; ind++;
                    gore = dole = found = false;
                    goto l1;
                }
                else {
                    while (parovi.size()) parovi.pop_back ();
                    gore = dole = false;
                }
            }
        }
        l1:;
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout<<field [i] [j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
