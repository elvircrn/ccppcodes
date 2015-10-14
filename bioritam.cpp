#include <fstream.h>

char x[25000];

int main() {
    ifstream cin("bioritam.in");
    ofstream cout("bioritam.out");
    int a, b, c, d, i;
    cin >> a >> b >> c >> d;
    a = (a + 368 - d) % 23;
    b = (b + 392 - d) % 28;
    c = (c + 396 - d) % 33;
    for(i = 0; i < 25000; i++) x[i] = 0;
    for(i = b; i < 25000; i += 28) x[i]++;
    for(i = c; i < 25000; i += 33) x[i]++;
    for(i = a ? a : 23; i < 25000 && x[i] != 2; i += 23);
    cout << "Sljedeci trostruki vrh se pojavljuje za " << i << " dana." << endl;
    return 0;
}    
