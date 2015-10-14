#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stdexcept>
//#include "TestCurenja.h"

using namespace std;

struct Blok
{
    int redni_broj;
    Blok *sljedeci;
};

Blok* prosli (Blok* trenutni, int listasize)
{
    Blok *proslireturn (trenutni);
    for(int i = 1; i < listasize; i++)
        proslireturn = proslireturn->sljedeci;
    return proslireturn;
}
void izbrisi( Blok* obrisani, int &listasize)
{
    Blok* previous(prosli(obrisani, listasize));
    previous->sljedeci = previous->sljedeci->sljedeci;
    delete obrisani;
    listasize --;
}

void izbrisizadnjeg( Blok* obrisani, int &listasize)
{
    obrisani->sljedeci = nullptr;
    delete obrisani;
    listasize --;
}

vector<int>Razbrajanje (int n, int m)
{
    if(n < 1) return vector<int>();
    if(n==1) return vector<int> (1,1);
    Blok *prvi, *zadnji;
    int del(2);
    prvi = new Blok;
    try
    {
        prvi->sljedeci = new Blok;
        zadnji = prvi->sljedeci;
        try
        {
            for(int i = 2; i < n; i++)
            {
                cout<<i<<endl;
                system("pause");
                zadnji->sljedeci = new Blok;

                if(i==6) throw exception();
                del++;
                zadnji = zadnji->sljedeci;
            }
            zadnji->sljedeci = prvi;
        }
        catch(exception e)
        {
            cout << "radil" ;

            int hepek(n);
            Blok *zabrisanje;
                zabrisanje =  prvi;
            for(int i = 1; i < n; i++)
            {
                cout<<i<<endl;
                if(i==del) break;
                zabrisanje =  prvi;
                prvi = prvi->sljedeci;
                izbrisi(zabrisanje, hepek);
            }

            if(del==n) izbrisizadnjeg(prvi, hepek);
            cout<<"finished"<<endl;

            //throw domain_error("nije uspjela alokacija");
        }
    }
    catch(...)
    {
        throw domain_error("Ne valja");
    }

    Blok *itliste (prvi);
    for(int i = 1; i <= n; i++)
    {
        itliste->redni_broj = i;
        itliste = itliste->sljedeci;
    }
    itliste = prvi;
    Blok *enditer(zadnji), *itprethodnog(zadnji);
    /*for(auto iti = prvi; iti != enditer; iti = iti->sljedeci)
    {
        cout << iti->redni_broj << " ";

    }


    /*auto itliste(lista.begin());
    auto itprethodnog(lista.end());*/
    int listasize(n);
    vector<int> davektor;
    while(listasize)
    {
        //cout << *itliste << ":";
        //for(auto retit = lista.begin(); retit != lista.end(); retit++)
        //    cout << *retit << " ";
        if(listasize > m)
        {
            davektor.push_back(itliste->redni_broj);
            itprethodnog = itliste;
            for(int i = 0; i < m; i++)
            {
                itliste = itliste->sljedeci;
                //cout << *itliste << " ";
            }
            izbrisi(itprethodnog, listasize);
        }
        else if(listasize == m)
        {
            davektor.push_back(itliste->redni_broj);
            itprethodnog = itliste;
            itliste = itliste->sljedeci;
            izbrisi(itprethodnog, listasize);
        }
        else if(listasize == 1)
        {
            davektor.push_back(itliste->redni_broj);
            izbrisizadnjeg(itliste,listasize);
            //lista.erase(lista.begin());
        }
        else
        {
            davektor.push_back(itliste->redni_broj);
            itprethodnog = itliste;
            itliste = itliste->sljedeci;
            izbrisi(itprethodnog, listasize);
            for(int i = 1; i < m; i++)
            {
                itliste = itliste->sljedeci;
                //cout << *itliste << " ";
            }
        }
        //cout << "itpret je " << *itprethodnog;
        //cin.get();
        /*for( int i = 0; i < davektor.size(); i++)
            cout << davektor[i] << " ";
        //cout << "lista je " << listasize;
        cout << endl;*/

    }
    return davektor;
}

int OdabirKoraka(int n, int k)
{
    int m = 1;
    while(m <= n*n)
    {
        //cout << "za m: " << m << endl;
        if( k == Razbrajanje(n ,m).back()) return m;
        m++;
    }
    return 0;
}


int main()
{
    int a;
    cin >> a;
    vector<int> b;
    /*try
    {*/
        b = Razbrajanje(a, 3);
    /*}
    catch(...)
    {
        cout << "Problemi sa memorijom ";
    }*/
    for(int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    //for(int i = 2; i<= 100; i++)
    // cout << OdabirKoraka(30, 8) << endl;
    return 0;
}
