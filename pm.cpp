#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

char s[10];
bool tabla[10][10];
int k, kolona[10], red[10], Sol; // 0= red, 1= kolona

int main()
{
    for( int i=0; i<8; ++i)
    {
        scanf("%s", &s);
        for( int j=0; j<8; ++j)
            tabla[i][j]= (s[j]=='+');
    }
    scanf("%d", &k);
    for( int i=0; i<k; ++i)
    {

        for( int j=0; j<8; ++j)
            red[j]= kolona[j]= 0;

        for( int j=0; j<8; ++j)
        {
            for( int l=0; l<8; ++l)
            {
                if( tabla[j][l] )
                {
                    kolona[l]--;
                    red[j]--;
                }
                else
                {
                    kolona[l]++;
                    red[j]++;
                }
            }
        }
        int Max= -1, sta_uzeti, ind;
        for( int j=0; j<8; ++j)
        {
            if( Max<red[j])
            {
                sta_uzeti= 0;
                ind= j;
                Max= red[j];
            }
            if( Max<kolona[j])
            {
                sta_uzeti= 1;
                ind= j;
                Max= kolona[j];
            }
        }
        if( Max <=0)
        {
            if((k-i-1)%2)
            {
                int Min= 9;
                for( int j=0; j<8; ++j)
                {
                    if( Min>red[j])
                    {
                        sta_uzeti= 0;
                        ind= j;
                        Min= red[j];
                    }

                    if( Min>kolona[j])
                    {
                        sta_uzeti= 1;
                        ind= j;
                        Min= kolona[j];
                    }
                }
                if( !sta_uzeti)
                {
                    for( int j=0; j<8; ++j)
                        tabla[ind][j]^= 1;
                }
                else
                {
                    for( int j=0; j<8; ++j)
                        tabla[j][ind]^= 1;
                }
                break;
            }
            else break;
        }
//cout<<Max<<"  "<<(sta_uzeti?"kolonu ":"red ")<<ind<<endl;
        if( !sta_uzeti)
        {
            for( int j=0; j<8; ++j)
                tabla[ind][j]^= 1;
        }
        else
        {
            for( int j=0; j<8; ++j)
                tabla[j][ind]^= 1;
        }
    }

    for( int i=0; i<8; ++i)
    {
        for( int j=0; j<8; ++j)
        {
            cout<<tabla[i][j];
            if( tabla[i][j])Sol++;
        }
        cout<<endl;
    }
    cout<<Sol<<endl;
    return 0;
}

