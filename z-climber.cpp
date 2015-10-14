#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

#define ovaj (*this)

class bigNum {
    public:
    deque <int> cifre;
    bigNum () {}
    void unesi (bool);
    void ispisi (bool) const;
    bigNum operator+ (const bigNum & b)const;
    bigNum operator* (const int b) const;
    bigNum operator* (const bigNum & b)const;
    bigNum operator- (const bigNum & b) const;
    friend bigNum operator/(const bigNum &, const bigNum &);
    bool operator<= (const bigNum & b) const;
    bool operator< (const bigNum & b) const;
    bool operator> (const bigNum & b) const;
    bool operator== (const bigNum & b) const;
};

void bigNum::unesi (bool kontra) {
    char a;
    while (!isdigit (a = getchar()));
    while (true) {
        if (a == '\n' || a == EOF || a == ' ') break;
        if (kontra) ovaj.cifre.push_back (a - '0');
        else ovaj.cifre.push_front (a -'0');
        a = getchar();
    }
    return;
}

void bigNum::ispisi (bool kontra) const {
    /*if (kontra) for (int i = (*this).cifre.size() - 1; i >= 0; i--) printf ("%d", (*this).cifre [i]);
    else for (int i = 0; i < (*this).cifre.size(); i++) printf ("%d", (*this).cifre [i]);
    printf ("\n");*/
    if (kontra) for (int i = (*this).cifre.size() - 1; i >= 0; i--) putchar (cifre [i] + '0');
    else for (int i = 0; i < (*this).cifre.size(); i++) putchar (cifre [i] + '0');
    return;
}

bool bigNum::operator == (const bigNum & b) const {
    if (cifre.size() != b.cifre.size()) return 0;
    else {
        for (int i = 0; i < cifre.size(); i++) {
            if (cifre [i] != b.cifre [i]) return 0;
        }
    }
    return 1;
}

bool bigNum::operator < (const bigNum & b) const {
    if (cifre.size() < b.cifre.size()) return 1;
    else if (cifre.size() > b.cifre.size()) return 0;
    else {
        for (int i = cifre.size() - 1; i > 0; i--) {
            if (cifre [i] < b.cifre [i]) return 1;
            else if (cifre [i] > b.cifre [i]) return 0;
        }
    }
    return 0;
}

bool bigNum::operator > (const bigNum & b) const {
    if (cifre.size() < b.cifre.size()) return 0;
    else if (cifre.size() > b.cifre.size()) return 1;
    else {
        for (int i = cifre.size() - 1; i > -1; i--) {
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
        for (int i = cifre.size() - 1; i > 0; i--) {
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
        sol.cifre.push_back ((prijenos + cifre [i] * b) % 10);
        prijenos = (prijenos + b * cifre [i]) / 10;
    }
    if (prijenos) sol.cifre.push_back (prijenos);
    return sol;
}

bigNum bigNum::operator * (const bigNum & b) const{
    bigNum sol, r;
    sol.cifre.push_back (0);
    r.cifre.push_back (0);
    for (int i = 0; i < cifre.size(); i++) {
        r = b * cifre [i];
        for (int k = 0; k < i; k++) r.cifre.push_front (0);
        sol = sol + r;
    }
    return sol;
}

bigNum divide (const bigNum & b) {
    bigNum sol;
    int progress = 0;
    for (int i = b.cifre.size() - 1; i > -1; i--) {
        progress *= 10;
        progress += b.cifre [i];
        if (progress < 2 && i > 0) {
            if (i != b.cifre.size() - 1) sol.cifre.push_back (0);
            progress *= 10;
            progress += b.cifre [i - 1]; i--;
        }
        if (progress < 2) sol.cifre.push_back (0);
        else sol.cifre.push_back (progress / 2);
        progress = progress - (progress / 2) * 2;
    }
    return sol;
}

bigNum operator / (const bigNum &a, const bigNum &b) {
    bigNum sol, leftb, rightb, pivot, r, ONE;
    ONE.cifre.push_back (1);
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

bigNum jedan, dva;
int n, k, width, in;

bigNum dp [5] [300], sol, kopija;

int main () {
    jedan.cifre.push_back (1); dva.cifre.push_back (2);

    scanf ("%d %d", &n, &k);
    if (k == 0) {printf ("1\n"); return 0;}

    in = (n - 1) / 2 + 1;
    width = 2 * k + 1;

    dp [0] [k] = dp [0] [k + 1] = dp [0] [k + 2] = jedan;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= width / 2 + 1; j++) {
            if (i % 2 == 0) {
                dp [0] [j] = (dp [1] [j - 1] + dp [1] [j]) + dp [1] [j + 1];
            }
            else {
                dp [1] [j] = (dp [0] [j - 1] + dp [0] [j]) + dp [0] [j + 1];
            }
        }
        if (i % 2 == 0) dp [0] [width / 2 + 2] = dp [0] [width / 2];
        else dp [1] [width / 2 + 2] = dp [1] [width / 2];
    }

    if (n % 2) for (int i = 1; i <= width / 2; i++) sol = sol + dp [0] [i];
    else for (int i = 1; i <= width / 2; i++) sol = sol + dp [1] [i];

    if (n % 2) ((sol + sol) + dp [0] [width / 2 + 1]).ispisi(true);
    else ((sol + sol) + dp [1] [width / 2 + 1]).ispisi (true);

    return 0;
}
