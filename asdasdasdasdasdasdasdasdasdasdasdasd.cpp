#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector< pair<int,int> >graf[1000];
pair<int,int>par;

void dodaj_granu(int odakle, int dokle, int koji, int tezina)
{
    graf[koji].push_back(make_pair(dokle,tezina));
    return;
}

int main()
{
    int brojgrana, polazni_cvor, dolazni_cvor, tezina;
    cout<<"Koliko zelite dodati grana u graf?"<<endl;
    cin>>brojgrana;

    for(int i=0; i<brojgrana; i++)
    {
        cout<<"Polazni cvor:"<<endl;
        cin>>polazni_cvor;
        cout<<"Dolazni cvor:"<<endl;
        cin>>dolazni_cvor;
        cout<<"Tezina:"<<endl;
        cin>>tezina;
        dodaj_granu(polazni_cvor,dolazni_cvor,i, tezina);
        cout<<"Veza izmedju "<<i<<" -> "<<graf[i] [0].first<<" je uspostavljena sa tezinom od "<<graf[i] [0].second<<endl;
    }

    return 0;
}
