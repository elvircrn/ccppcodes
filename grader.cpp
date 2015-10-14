#include <iostream>

using namespace std;

int FibonaccijevStepen (int n, int p);

int main()
{
    int rezultat(FibonaccijevStepen (1000000000, 1000000000));
    cout << "FibonaccijevStepen (8, 2) = " << rezultat;
    /*if (rezultat == 441)
        cout << "\nTacno!\n";
    else
        cout << "\nNetacno! Tacan rezultat je 441.\n\n";
    rezultat = FibonaccijevStepen (6, 4);
    cout << "FibonaccijevStepen (6, 4) = " << rezultat;
    if (rezultat == 96)
        cout << "\nTacno!\n";
    else
        cout << "\nNetacno! Tacan rezultat je 96.\n";*/
    return 0;
}
