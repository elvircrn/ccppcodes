#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct rijec
{
    char slova [3000];
    int size;

    rijec () { }

    void napravi()
    {
        scanf ("%s", &slova);
        size = strlen (slova);
    }

    bool operator< (const rijec & xx) const
    {
        int ind1 = size / 2, ind2 = xx.size / 2;
        int IND1 = ind1, IND2 = ind2;
        for (int i = 0; i <= min (ind1, ind2); i++) {
            if (slova [IND1 + i] != xx.slova [IND2 + i]) return (slova [IND1 + i] < xx.slova [IND2 + i]);
            if (slova [IND1 - i] != xx.slova [IND2 - i]) return (slova [IND1 - i] < xx.slova [IND2 - i]);
        }

        return (size < xx.size);
    }

};

rijec a, b;
rijec rijeci [3000];
int n;
char A [100], B [100], unos [3000];

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        rijeci [i].napravi();

    sort (rijeci, rijeci + n);

    for (int i = 0; i < n; i++) puts (rijeci [i].slova);

    return 0;

}
