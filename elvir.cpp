#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

struct rijec
{
    vector <char> ime;
};

bool uslov(const rijec &a, const rijec &b)
{
    int len = min (a.ime.size(), b.ime.size());

    for (int i = 0; i < len; i++)
        if (a.ime [i] != b.ime [i])
            return a.ime [i] < b.ime [i];

    if (a.ime.size() != b.ime.size())
        return a.ime.size() < b.ime.size();

    return true;
}

int main()
{
    int n;
    vector <rijec> niz;
    scanf("%d",&n); getchar();

    for (int i=0; i<n; i++)
    {
        char t;
        rijec rk;
        while(true)
        {
            t = getchar();
            if(t=='\n') break;
            rk.ime.push_back(t);
        }
        niz.push_back(rk);
    }
    sort(niz.begin(),niz.end(),uslov);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<niz[i].ime.size(); j++)
        {
            printf("%c",niz[i].ime[j]);
        }
        printf("| \n");
    }
    printf("\n");
    scanf("%d",&n);

    return 0;
}
