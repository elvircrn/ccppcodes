#include <cstdio>

using namespace std;

void ZapocniIgru(int a, int b);

int pokusaja;
bool broj_pogodjen;
int m;

int Pokusaj(int k) {
    ++pokusaja;
    if (k == m) {
        broj_pogodjen = true;
        return 0;
    }
    else if (k > m) {
        broj_pogodjen = false;
        return 1;
    }
    else {
        broj_pogodjen = false;
        return -1;
    }
}

int main() {
    pokusaja = 0;
    m = 1;
    broj_pogodjen = false;
    ZapocniIgru(1, 16);
    if (broj_pogodjen == false)
        printf("Tajni broj nije pogodjen.\n");
    else
        printf("Tajni broj pogodjen nakon %d pokusaja.\n", pokusaja);
    return 0;
}
