#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define ovaj (*this)

struct bigNum {
    deque <int> cifre;
    bigNum operator+ (const bigNum & b)const;
    bigNum operator* (const int b)const;
    bigNum operator* (const bigNum & b)const;
    friend bigNum operator/(const bigNum &, const bigNum &);
    bool operator<= (const bigNum & b) const;
    bool operator< (const bigNum & b) const;
    bool operator> (const bigNum & b) const;
    bool operator== (const bigNum & b) const;

    void unesi (bool kontra) {
        char a;
        while (!isdigit (a = getchar()));
        while (true) {
            if (a == EOF) break;
            if (a == '\n') continue;
            if (kontra) ovaj.cifre.push_back (a - '0');
            else ovaj.cifre.push_front (a -'0');
            a = getchar();
        }
        return;
    }
};

bigNum ONE;

void ispisi (const bigNum &a) {
    for (int i = 0; i < a.cifre.size(); i++) printf ("%d", a.cifre [i]);
    printf ("\n");
}

bool bigNum::operator== (const bigNum & b) const {
    if (cifre.size() != b.cifre.size()) return 0;
    else {
        for (int i = 0; i < cifre.size(); i++) {
            if (cifre [i] != b.cifre [i]) return 0;
        }
    }
    return 1;
}

bool bigNum::operator< (const bigNum & b) const {
    if (cifre.size() < b.cifre.size()) return 1;
    else if (cifre.size() > b.cifre.size()) return 0;
    else {
        for (int i = 0; i < cifre.size(); i++) {
            if (cifre [i] < b.cifre [i]) return 1;
            else if (cifre [i] > b.cifre [i]) return 0;
        }
    }
    return 0;
}

bool bigNum::operator> (const bigNum & b) const {
    if (cifre.size() < b.cifre.size()) return 0;
    else if (cifre.size() > b.cifre.size()) return 1;
    else {
        for (int i = 0; i < cifre.size(); i++) {
            if (cifre [i] < b.cifre [i]) return 0;
            else if (cifre [i] > b.cifre [i]) return 1;
        }
    }
    return 1;
}

bool bigNum::operator <= (const bigNum & b) const {
    if (cifre.size() < b.cifre.size()) return 1;
    else if (cifre.size() > b.cifre.size()) return 0;
    else {
        for (int i = 0; i < cifre.size(); i++) {
            if (cifre [i] < b.cifre [i]) return 1;
            else if (cifre [i] > b.cifre [i]) return 0;
        }
    }
    return 1;
}

bigNum bigNum::operator + (const bigNum & b) const {
    bigNum sol;
    int prijenos = 0;

    for (int i = 0; i < min (cifre.size(), b.cifre.size()); i++) {
        sol.cifre.push_back ((prijenos + b.cifre [i] + cifre [i]) % 10);
        prijenos = (prijenos + b.cifre [i] + cifre [i]) / 10;
    }

    for (int i = min (cifre.size(), b.cifre.size()); i < max (cifre.size(), b.cifre.size()); i++)
        if (cifre.size() > b.cifre.size()) {sol.cifre.push_back ((prijenos + cifre [i]) % 10); prijenos = (prijenos + cifre [i]) / 10;}
        else {sol.cifre.push_back ((prijenos + b.cifre [i]) % 10); prijenos = (prijenos + b.cifre [i]) / 10;}

    if (prijenos) sol.cifre.push_back (1);

    return sol;
}

bigNum bigNum::operator * (const int b) const {
    bigNum sol;
    int prijenos = 0;
    for (int i = 0; i < cifre.size(); i++) {
        sol.cifre.push_front ((prijenos + cifre [cifre.size() - 1 - i] * b) % 10);
        prijenos = (prijenos + cifre [cifre.size() - 1 - i] * b) / 10;
    }
    if (prijenos) sol.cifre.push_front (prijenos);
    return sol;
}

bigNum bigNum::operator* (const bigNum & b) const{
    bigNum sol, r;
    sol.cifre.push_back (0);
    r.cifre.push_back (0);
    for (int i = 0; i < cifre.size(); i++) {
        r = b * cifre [cifre.size() - 1 - i];
        for (int k = 0; k < i; k++) r.cifre.push_back (0);
        sol = sol + r;
    }
    //if (prijenos) sol.cifre.push_front (prijenos);
    return sol;
}

bigNum divide (const bigNum & b) {
    bigNum sol;
    int progress = 0;
    for (int i = 0; i < b.cifre.size(); i++) {
        progress *= 10;
        progress += b.cifre [i];
        if (progress < 2 && i < b.cifre.size() - 1) {
            if (i != 0) sol.cifre.push_back (0);
            progress *= 10;
            progress += b.cifre [i + 1]; i++;
        }
        if (progress < 2) sol.cifre.push_back (0);
        else sol.cifre.push_back (progress / 2);
        progress = progress - (progress / 2) * 2;
    }
    return sol;
}
bigNum jedan, dva;

bigNum operator / (const bigNum &a, const bigNum &b) {
    bigNum sol, leftb, rightb, pivot, r;
    leftb.cifre.push_back (1);
    rightb = a;
    while (leftb <= rightb) {
        pivot = divide (leftb + rightb);
        r = pivot * b;
        if (r == a || r < a && (pivot + ONE) * b > a) return pivot;
        else if (r > a) rightb = pivot;
        else leftb = pivot + ONE;
    }
    return ONE;
}

int main () {
    int asd, buf, d;
    char a;
    scanf ("%d", &asd); getchar();
    for (int i = 0; i < asd; i++) {scanf ("%d", &d); jedan.cifre.push_back (d);}

    ONE.cifre.push_back (1);
    bigNum M, ONE, pivot, lb, rb; lb.cifre.push_back (1); ONE.cifre.push_back (1);

    rb = jedan;
    while (true) {
        lb
        pivot = divide (lb + rb);
        M = pivot * pivot;
        if (M == jedan) {
            printf ("%d\n", pivot.cifre.size());
            for (int i = 0; i < pivot.cifre.size(); i++) printf ("%d\n", pivot.cifre [i]);
            return 0;
        }
        if (M > jedan) rb = pivot;
        else lb = pivot;
    }
    return 0;
}
