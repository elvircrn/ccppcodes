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
struct bigNum {
    deque <int> cifre;
    bigNum operator+ (const bigNum & b)const;
    bigNum operator- (const bigNum & b)const;
    bigNum operator* (const int b)const;
    bigNum operator* (const bigNum & b)const;
    friend bigNum operator/(const bigNum &, const bigNum &);
    bool operator<= (const bigNum & b) const;
    bool operator< (const bigNum & b) const;
    bool operator> (const bigNum & b) const;
    bool operator== (const bigNum & b) const;
};

bigNum ONE;

void ispisi (bigNum a) {
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

bigNum bigNum::operator + (const bigNum & b) const{
    bigNum sol;
    int prijenos = 0;
    for (int i = 0; i < min (cifre.size(), b.cifre.size()); i++) {
        sol.cifre.push_front ((prijenos + cifre [cifre.size() - 1 - i] + b.cifre [b.cifre.size() - i - 1]) % 10);
        prijenos = (prijenos + cifre [cifre.size() - 1 - i] + b.cifre [b.cifre.size() - i - 1]) / 10;
    }
    for (int i = min (cifre.size(), b.cifre.size()); i < max (cifre.size(), b.cifre.size()); i++) {
        if (cifre.size() > b.cifre.size()) {
            sol.cifre.push_front ((prijenos + cifre [cifre.size() - i - 1]) % 10);
            prijenos = (prijenos + cifre [i]) / 10;
        }
        else {
            sol.cifre.push_front ((prijenos + b.cifre [b.cifre.size() - i - 1]) % 10);
            prijenos = (prijenos + b.cifre [i]) / 10;
        }
    }
    if (prijenos) sol.cifre.push_front (1);
    return sol;
}

bigNum bigNum::operator - (const bigNum & b) const {
    bigNum sol;
    int prijenos = 0;
    for (int i = 0; i < min (cifre.size(), b.cifre.size()); i++) {
        if (b.cifre [b.cifre.size() - i - 1] + prijenos > cifre [cifre.size() - i - 1]) {
            sol.cifre.push_front ((10 + cifre [cifre.size() - i]) - (b.cifre [b.cifre.size() - i - 1] + prijenos));
            cout<<10 + cifre [cifre.size() - i] - b.cifre [b.cifre.size() - i] + prijenos<<endl;
            prijenos = 1;
        }
        else {
            sol.cifre.push_front ((-b.cifre [b.cifre.size() - i]) + prijenos + cifre [cifre.size() - i]);
            cout<<(-b.cifre [b.cifre.size() - i]) + prijenos + cifre [cifre.size() - i]<<endl;
            prijenos = 1;
        }
    }
    for (int i = min (cifre.size(), b.cifre.size()); i < max (cifre.size(), b.cifre.size()); i++) {
        if (cifre.size() > b.cifre.size()) {
            sol.cifre.push_front (cifre [cifre.size() - i - 1] - prijenos);
        }
        else {
            sol.cifre.push_front ((b.cifre [b.cifre.size() - i - 1] - prijenos));
        }
    }
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

char aa = 'l';

int main () {
    ONE.cifre.push_back (1);
    aa = getchar();
    while (aa != '\n') {
        jedan.cifre.push_back (aa - '0');
        aa = getchar();
    }
    aa = getchar();
    while (aa != '\n') {
        dva.cifre.push_back (aa - '0');
        aa = getchar();
    }
    ispisi (jedan / dva);
    return 0;
}
