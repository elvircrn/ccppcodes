#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool KriterijSortiranja(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

void SortirajPoDuzini(string *stringovi, int len)
{
    sort(stringovi, stringovi + len, KriterijSortiranja);
}

bool PretraziBinarno(string *stringovi, int len, string query)
{
    int left = 0, right = len - 1, pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (KriterijSortiranja(stringovi [pivot], query))
            left = pivot + 1;
        else if (stringovi [pivot] == query)
            return true;
        else
            right = pivot;
    }

    return stringovi [pivot] == query;
}

int main()
{
    int n;
    string *niz;

    cin>>n;

    niz = new string[n];

    for (int i = 0; i < n; i++)
        cin>>niz [i];

    SortirajPoDuzini(niz, n);

    for (int i = 0; i < n; i++)
        cout<<niz [i]<<endl;

    while (true)
    {
        string query;
        cin>>query;
        if (PretraziBinarno(niz, n, query))
            cout<<"ima"<<endl;
        else
            cout<<"nema"<<endl;
    }

    return 0;
}















