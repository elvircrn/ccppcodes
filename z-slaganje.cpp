#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
class BIT {
    public:

    T querry [500001], array [500001];

    int Size;

    BIT () {Size = 0; for (int i = 0; i < 50000; i++) array [i] = querry [i] = 0;}
    BIT (int dd) {Size = 0; for (int i = 0; i <= dd; i++) array [i] = querry [i] = 0;}

    void add (int pos, T val) {
        while (pos <= Size) {
            array [pos] += pos;
            pos += pos & (-pos);
        }
        return;
    }

    T sum (int pos) {
        T ret = 0;
        while (pos) {
            ret += array [pos];
            pos -= pos & (-pos);
        }
        return ret;
    }

    void sumRange (int start, int end) {
        return sum (end) - sum (end - 1);
    }

    bool exist (int pos) {
        return (sum (pos) - sum (pos - 1));
    }
};

BIT <int> bit (50000);

char Q;
int x, y;

int main () {

    while (true) {

        Q = getchar(); getchar();

        if (Q == 'K') break;

        else if (Q == 'A') {
            scanf ("%d %d", &x, &y);
            bit.add (x, 1);
            bit.add (y + 1, -1);
        }

        else if (Q == 'R') {
            scanf ("%d", &x);
            if (bit.exist (x)) {
                bit.add (x, -1);
                bit.add (x + 1, 1);
            }
        }

        else {

        }
    }

    return 0;
}
