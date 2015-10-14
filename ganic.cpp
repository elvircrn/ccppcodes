#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int>rezultat;
int pisemo, pamtimo;
int main()
{
    freopen ("out1.txt", "w", stdout);
    int broj = 1000;
    rezultat.push_back(1);

    for(int i=1; i<=broj; i++){
        for(int j=0; j<rezultat.size(); j++){
            pisemo = (rezultat[j]*i+pamtimo)%10;
            pamtimo = (rezultat[j]*i+pamtimo)/10;
            rezultat[j]=pisemo;
        }
        while (pamtimo>0) {
            rezultat.push_back(pamtimo%10);
            pamtimo/=10;
        }
    }

    for(int i=rezultat.size()-1; i>=0; i--)
        cout<<rezultat[i];
    cout<<endl<<rezultat.size()<<endl;
    return 0;
}
