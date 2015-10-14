#include <iostream>

using namespace std;

long long BrojKombinacija (string s);

int main()
{
    long long rezultat(BrojKombinacija ("oko"));
    cout << "BrojKombinacija (\"oko\") = " << rezultat;
    if (rezultat == 3)
        cout << "\nTacno!\n";
    else
        cout << "\nNetacno! Tacan rezultat je 3.\n\n";
    rezultat = BrojKombinacija ("fata");
    cout << "BrojKombinacija (\"fata\") = " << rezultat;
    if (rezultat == 12)
        cout << "\nTacno!\n";
    else
        cout << "\nNetacno! Tacan rezultat je 12.\n\n";
    rezultat = BrojKombinacija ("visoko");
    cout << "BrojKombinacija (\"visoko\") = " << rezultat;
    if (rezultat == 360)
        cout << "\nTacno!\n";
    else
        cout << "\nNetacno! Tacan rezultat je 360.\n";
    return 0;
}

