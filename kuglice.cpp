#include <stdio.h>
#include <stdlib.h>
using namespace std;
int niz [100001], n, m, prosjek, cnt=0, tmp, suma = 0;
int main() {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf ("%d", &niz [i]);
        suma += niz[i];
    }
    prosjek = m;
    for(int i = 0; i < n; i++){
        if (niz [i] >= prosjek) {
            cnt += niz [i] - prosjek;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}
