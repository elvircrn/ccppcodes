#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int Akumuliraj(int *beginning, int *end, int (*f)(int, int), int a0 = 0)
{
    if (beginning == end)
        return f(a0, *beginning);
    return f(Akumuliraj (beginning, end - 1, f), *end);
}

bool ZaSve(string *beginning, string *end)
{

}

bool MakarJedan(int *beginning, int *end)
{
    while (beginning != end)
    {
        int sum = 0, x = *beginning;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }

        if (sum % (*beginning) == 0)
            return true;

        beginning++;
    }

    return false;
}

int Akumuliraj(int *beginning, int *end, int (*f)(int, int), int a0 = 0)
{
    if (beginning == end)
        return f(a0, *beginning);
    return f(Akumuliraj (beginning, end - 1, f), *end);
}

int sum(int x, int y)
{
    return x + y;
}

int main()
{
    const int n = 10;
    int *niz = new int[n];
    string *stringovi = new string[n];


    //ZaSve
    for (int i = 0; i < n; i++)
        cin>>stringovi [i];

    if (ZaSve(stringovi, stringovi + n - 1))
        cout<<"Uneseni string sadrzi samo slova i cifre"<<endl;
    else
        cout<<"Uneseni string  sadrzi i druge znakove osim slova i cifara"<<endl;

    //Makar jedan
    for (int i = 0; i < n; i++)
        cin>>niz [i];
    if (MakarJedan(niz, niz + n - 1))
        cout<<"U nizu ima brojeva djeljivih sa sumom svojih cifara"<<endl;
    else
        cout<<"U  nizu  nema  brojeva djeljivih sa sumom svojih cifara"<<endl;

    //Akumuliraj
    for (int i = 0; i < n; i++)
        cin>>niz [i];
    cout<<"Suma svih brojeva je: "<<Akumuliraj(niz, niz + n - 1, sum)<<endl;


    delete[] n;
    delete[] stringovi;




    return 0;
}























