#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class rijec {

    public: char slova [3000];

    rijec () {}
    rijec (char a[]) {strcpy (slova, a);}

    bool operator< (const rijec & xx) const {

        int ind1 = strlen (slova) / 2, ind2 = strlen (xx.slova) / 2;
        int IND1 = ind1, IND2 = ind2;
        for (int i = 0; i <= min (ind1, ind2); i++) {
            if (slova [IND1 + i] != xx.slova [IND2 + i]) return (slova [IND1 + i] < xx.slova [IND2 + i]);
            if (slova [IND1 - i] != xx.slova [IND2 - i]) return (slova [IND1 - i] < xx.slova [IND2 - i]);
        }

        return (strlen (slova) < strlen (xx.slova));

    }

};

rijec a, b;
rijec rijeci [3000];
int n;
char A [100], B [100], unos [3000];

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%s", &unos);
        rijeci [i] = rijec (unos);
    }

    sort (rijeci, rijeci + n);

    for (int i = 0; i < n; i++) puts (rijeci [i].slova);

    return 0;

}
/*
0 2 4
AP 6
*/
