#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MaxN 1000005
using namespace std;

char a[MaxN], b[MaxN], MaxChar[MaxN];
int start[MaxN], end[MaxN], Max[MaxN]; // niz end[] je totalno bespotreban... kasnije ukloniti
vector< int> occur[28], upitnici;       // obratiti paznju na uzimanje slova leksikografski najmanjih... u slucaju vise resenja

int main()
{
    freopen("upis.txt", "r", stdin);
    scanf("%s", &a);
    scanf("%s", &b);
    cout<<a<<endl;
    cout<<b<<endl;

    int sa= strlen(a), sb= strlen(b);

    for( int i=0; i<sa; ++i)
        occur[a[i]-'a'].push_back( i);


    for( int i=0; i<26; ++i)
    {

        int dosao= 0, kraj= 0, os= occur[i].size();


        for( int j=0; j<os; ++j)
        {

            for( ; dosao<sb && dosao<=occur[i][j]; ++dosao)
                start[dosao]= j;

            for( ; kraj<dosao && sa-sb+kraj<=occur[i][j]; ++kraj)
            {
                end[kraj]= j;
                if( sa-sb+kraj<occur[i][j]) end[kraj]--;
                if( b[kraj] == '?')
                {
                    if( Max[kraj] < end[kraj]-start[kraj]+1)
                    {
                        Max[kraj]= end[kraj]-start[kraj]+1;
                        MaxChar[kraj]= char('a'+i);
                    }
                }
                else if( b[kraj] == char('a'+i))
                    if( Max[kraj] < end[kraj]-start[kraj]+1)
                    {
                        Max[kraj]= end[kraj]-start[kraj]+1;
                        MaxChar[kraj]= char('a'+i);
                    }
            }
        }//cout<<"dosao je do obrade "<<dosao<<" indeksa, kod slova "<<(char)('a'+i)<<endl;
        if( dosao>kraj)
            for( ; dosao>kraj; ++kraj)
            {
                end[kraj]= os-1;
                //if( sa-sb+kraj<occur[i][os-1]) end[kraj]--;
                if( b[kraj] == '?')
                {
                    if( Max[kraj] < end[kraj]-start[kraj]+1)
                    {
                        Max[kraj]= end[kraj]-start[kraj]+1;
                        MaxChar[kraj]= char('a'+i);
                    }
                }
                else if( b[kraj] == char('a'+i))
                    if( Max[kraj] < end[kraj]-start[kraj]+1)
                    {
                        Max[kraj]= end[kraj]-start[kraj]+1;
                        MaxChar[kraj]= char('a'+i);
                    }
            }
        //for( int j=0; j<dosao; ++j)
        //cout<<"za slovo na indeksu "<<j<<" ima "<<end[j]<<" - "<<start[j]<<" poklapanja sa "<<(char)('a'+i)<<endl;
    }


    for( int i=0; i<sb; ++i)
        cout<<i<<" -ta pozicija ima najvise preklapanja sa  "<<MaxChar[i]<<"  i to tacno  "<<Max[i]<<endl;


    return 0;
}
