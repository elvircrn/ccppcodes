#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

struct str1 {

    char a, b;
    int SIZE;

    str1 () {}
    str1 (char aa, char bb, int S) {a = aa; b = bb; SIZE = S;}

    bool operator < (const str1 & xx) const {
        if (a != xx.a) return a < xx.a;
        else return SIZE > xx.SIZE;
    }

};

struct str2 {

    char a, b;
    int SIZE;

    str2 () {}
    str2 (char aa, char bb, int S) {a = aa; b = bb; SIZE = S;}

    bool operator < (const str2 & xx) const {
        if (b != xx.b) return b < xx.b;
        else return SIZE > xx.SIZE;
    }

};

struct str {

    char a, b;

    str () {}
    str (char _a, char _b) {a = _a; b = _b;}

};

vector <str1> leftright;
vector <str2> rightleft;
vector <str> rijeci;

char unos [20];
int n, solution, maxn, cnt;
bool used [100001];

bool check (int x, int y) {
    return (leftright [x].b == rightleft [y].a);
}

int binary_Search (char h) {

    int leftb = 0, rightb = n, pivot;

    while (leftb <= rightb) {

        pivot = (leftb + rightb) / 2;

        if (h == leftright [pivot].a) {

            int ret = -1;

            for (int i = pivot; leftright [i].a == leftright [pivot].a && i > -1; i--)
                if (!used [i])
                    ret = i;

            if (ret == -1) {
                for (int i = pivot; leftright [i].a == leftright [pivot].a && i < n; i++)
                    if (!used [i]) {
                        ret = i;
                        break;
                    }
            }

            return ret;

        }
        else if (h < leftright [pivot].a) leftb = pivot + 1;
        else rightb = pivot - 1;

    }

    return -1;

}

void dfs (int ind, int progress) {
    solution = max (progress, solution);
    int index = binary_Search (rightleft [ind].b);
    if (index == -1) return;
    cout<<"index: "<<index<<" ind: "<<ind<<endl; system ("pause");
    used [index] = true;
    dfs (index, progress + leftright [index].SIZE);
    used [index] = false;
    return;
}

int main () {

    scanf ("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf ("%s", &unos);
        leftright.push_back (str1 (unos [0], unos [strlen (unos) - 1], strlen (unos)));
        rightleft.push_back (str2 (unos [strlen (unos) - 1], unos [0], strlen (unos)));
        rijeci.push_back (str (unos [0], unos [strlen (unos) - 1]));
    }

    sort (leftright.begin(), leftright.end());
    sort (rightleft.begin(), rightleft.end());

    for (int i = 0; i < n; i++) {
        used [i] = true;
        dfs (i, 0);
        used [i] = false;
    }

    printf ("%d\n", solution);
    //printf ("%c %c\n", leftright [binary_Search ('c')].a, leftright [binary_Search ('c')].b);

    cout<<binary_Search ()

    return 0;
}
//1000000000
