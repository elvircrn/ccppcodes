#include <iostream>

using namespace std;

int MinimalnoVrijeme (int n, int zadaci[], int t);

int main()
{
    int niz1[2] = {1, 2};
    int niz2[] = {3, 6, 9, 12, 15};
    int rezultat(MinimalnoVrijeme (5, niz2, 1000));
    cout<<"rezultat: "<<rezultat<<endl;
    return 0;
}
