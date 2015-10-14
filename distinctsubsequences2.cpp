#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <deque>

using namespace std;

class BigNum
{
    public:
    deque <char> cifre;
    bool pozitivan;
    public:
    BigNum():pozitivan(true){}

    BigNum(int a)
    {
        if (a == 0)
        {
            pozitivan = true;
            cifre.push_back (0);
            return;
        }
        if (a>=0)pozitivan=1;
        else
        {
            pozitivan=0;
            a*=-1;
        }
        while (a)
        {
            cifre.push_back(a%10);
            a/=10;
        }
    }

    BigNum(string a)
    {
        pozitivan = 1;
        int pocetak(0);
        if (a[0]=='-')
        {
            pozitivan = 0;
            pocetak=1;
        }
        for (int i=pocetak;i<a.length();i++)
        {
            cifre.push_front(a[i]-48);
        }
    }

    friend ostream & operator<<(ostream &,const BigNum &);
    friend istream & operator>>(istream &,BigNum &);
    friend BigNum operator+(const BigNum &,const BigNum &);
    friend bool operator==(const BigNum &,const BigNum &);
    friend bool operator!=(const BigNum &,const BigNum &);
    friend bool operator<(const BigNum &,const BigNum &);
    friend bool operator>(const BigNum &,const BigNum &);
    friend bool operator<=(const BigNum &,const BigNum &);
    friend bool operator>=(const BigNum &,const BigNum &);
    friend BigNum operator*(const BigNum &,int);
    friend BigNum operator*(const BigNum &,const BigNum &);
    friend BigNum operator/(const BigNum &,int);
    friend int operator%(const BigNum &,int);
    friend BigNum operator/(const BigNum &,const BigNum &);
    friend BigNum operator-(const BigNum &,const BigNum&);
};

ostream & operator<<(ostream &xout,const BigNum &broj)
{
    if (!broj.pozitivan)xout<<'-';
    for (int i=broj.cifre.size()-1;i>-1;i--)
    {
        xout<<(int)broj.cifre[i];
    }
    return xout;
}

istream & operator>>(istream &xin,BigNum &broj)
{
    string bla;
    xin>>bla;
    broj=BigNum(bla);
    return xin;
}

bool operator==(const BigNum &broj1,const BigNum &broj2)
{
    if ((broj1.pozitivan!=broj1.pozitivan)&&(broj1.cifre.size()||broj2.cifre.size()))
    {
        return false;
    }
    else if (broj1.cifre.size()!=broj2.cifre.size())
    {
        return false;
    }
    else
    {
        for (int i=0;i<broj1.cifre.size();i++)
        if (broj1.cifre[i]!=broj2.cifre[i]) return false;
    }
    return true;
}

bool operator!=(const BigNum &broj1,const BigNum &broj2)
{
    return (!(broj1==broj2));
}

bool operator<(const BigNum &broj1,const BigNum &broj2)
{
    if (broj1==broj2) return false;
    if (broj1.pozitivan!=broj2.pozitivan) return broj1.pozitivan<broj2.pozitivan;
    else if (broj1.cifre.size()!=broj2.cifre.size())
    {
        return ((broj1.cifre.size()<broj2.cifre.size())*broj1.pozitivan);
    }
    else
    {
        for (int i=broj1.cifre.size()-1;i>-1;i--)
        if (broj1.cifre[i]!=broj2.cifre[i]) return broj1.cifre[i]<broj2.cifre[i];
    }
    return false;
}

bool operator>(const BigNum &broj1,const BigNum &broj2)
{
    return (broj2<broj1);
}

bool operator<=(const BigNum &broj1,const BigNum &broj2)
{
    return (!(broj2<broj1));
}

bool operator>=(const BigNum &broj1,const BigNum &broj2)
{
    return (!(broj1<broj2));
}

BigNum operator+(const BigNum &broj1,const BigNum &broj2)
{
    if (broj1.cifre.size() == 1 && broj1.cifre.size() == broj2.cifre.size() && broj1.cifre [0] == 0 && broj2.cifre [0] == 0)
    {
        return broj1;
    }
    if (broj1.pozitivan==broj2.pozitivan)
    {
        BigNum rjesenje;
        rjesenje.pozitivan=broj1.pozitivan;
        int tmp(0),daljmin;
        daljmin=min(broj1.cifre.size(),broj2.cifre.size());
        for (int i=0;i<daljmin;i++)
        {
            tmp+=broj1.cifre[i]+broj2.cifre[i];
            rjesenje.cifre.push_back(tmp%10);
            tmp/=10;
        }
        if (broj1.cifre.size()>broj2.cifre.size())
        {
            for (int i=daljmin;i<broj1.cifre.size();i++)
            {
                tmp+=broj1.cifre[i];
                rjesenje.cifre.push_back(tmp%10);
                tmp/=10;
            }
        }
        else
        {
            for (int i=daljmin;i<broj2.cifre.size();i++)
            {
                tmp+=broj2.cifre[i];
                rjesenje.cifre.push_back(tmp%10);
                tmp/=10;
            }
        }
        while (tmp)
        {
            rjesenje.cifre.push_back(tmp%10);
            tmp/=10;
        }
        while (!rjesenje.cifre.empty() && !rjesenje.cifre.back())rjesenje.cifre.pop_back();
        return rjesenje;
    }
}

BigNum operator*(const BigNum &broj1,int broj2)
{
    BigNum rjesenje;
    int tmp(0);
    rjesenje.pozitivan=(broj1.pozitivan == (broj2>=0));
    broj2=((broj2>=0)?broj2:-broj2);
    for (int i=0;i<broj1.cifre.size();i++)
    {
        tmp+=broj1.cifre[i]*broj2;
        rjesenje.cifre.push_back(tmp%10);
        tmp/=10;
    }
    while (tmp)
    {
        rjesenje.cifre.push_back(tmp%10);
        tmp/=10;
    }
    while (!rjesenje.cifre.empty() && !rjesenje.cifre.back())rjesenje.cifre.pop_back();

    return rjesenje;
}

BigNum operator*(const BigNum &broj1,const BigNum &broj2)
{
    BigNum nula (0);
    if (broj1 == nula || broj2 == nula)
    {

        return nula;
    }
    BigNum rjesenje,podrjesenje;
    podrjesenje=broj2;
    rjesenje.pozitivan=(broj1.pozitivan == broj2.pozitivan);
    for (int i=0;i<broj1.cifre.size();i++)
    {
        rjesenje=rjesenje+podrjesenje*broj1.cifre[i];
        podrjesenje.cifre.push_front(0);
    }
    while (!rjesenje.cifre.empty() && !rjesenje.cifre.back())rjesenje.cifre.pop_back();
    return rjesenje;
}

BigNum operator/(const BigNum &broj1,int broj2)
{
    BigNum rjesenje;
    int tmp(0);
    rjesenje.pozitivan=(broj1.pozitivan == (broj2>=0));
    broj2=((broj2>=0)?broj2:-broj2);
    for (int i=broj1.cifre.size()-1;i>-1;i--)
    {
        tmp*=10;
        tmp+=broj1.cifre[i];
        rjesenje.cifre.push_front(tmp/broj2);
        tmp%=broj2;
    }
    while (!rjesenje.cifre.empty() && !rjesenje.cifre.back())rjesenje.cifre.pop_back();
    return rjesenje;
}

int operator%(const BigNum &broj1,int broj2)
{
    int tmp(0);
    broj2=((broj2>=0)?broj2:-broj2);
    for (int i=broj1.cifre.size()-1;i>-1;i--)
    {
        tmp*=10;
        tmp+=broj1.cifre[i];
        tmp%=broj2;
    }
    return tmp;
}

BigNum operator/(const BigNum &broj1x,const BigNum &broj2x)
{
    BigNum rjesenje,broj1,broj2;
    BigNum donji,gornji;
    broj1=broj1x;
    broj1.pozitivan=1;
    broj2=broj2x;
    broj2.pozitivan=1;
    donji=BigNum(0);
    gornji=broj1;
    for(;;)
    {
        rjesenje=(donji+gornji)/2;
        if ((rjesenje*broj2<=broj1)&&((rjesenje+1)*broj2>broj1)) break;
        if (rjesenje*broj2<=broj1)
        {
            donji=rjesenje;
        }
        else
        {
            gornji=rjesenje;
        }
    }
    rjesenje.pozitivan=(broj1x.pozitivan == broj2x.pozitivan);
    while (!rjesenje.cifre.empty() && !rjesenje.cifre.back())rjesenje.cifre.pop_back();
    return rjesenje;
}

char A [10010], B [200];
int t, lenA, lenB;
BigNum dp [200] [10010], nula;

int main ()
{
    freopen ("input.txt", "r", stdin);
    //freopen ("DEBUG.txt", "w", stdout);

    /*printf ("1\n");
    for (int i = 0; i < 10000; i++)
        printf ("a"); printf ("\n");
    for (int i = 0; i < 200; i++)
        printf ("a"); printf ("\n");*/

    nula = BigNum (0);

    /*for (int i = 0; i <= 10005; i++)
        dp [0] [i] = BigNum (1);
    for (int i = 0; i <= 150; i++)
        dp [i] [0] = nula;
    for (int i = 1; i <= lenB; i++)
        for (int j = 0; j < i; j++)
            dp [i] [j] = nula;*/

    scanf ("%d", &t);
    /*while (t--)
    {*/
        scanf ("%s %s", &A, &B);

        printf ("%s\n", strlen (A));

        //lenA = strlen (A);
        //lenB = strlen (B);

        /*for (int i = 1; i <= lenB; i++)
        {
            //dp [0] [0] = BigNum (1);
            for (int j = i; j <= lenA; j++)
            {
                //if (A [j - 1] == B [i - 1])
                 //   dp [i] [j] = dp [i - 1] [j - 1] + dp [i] [j - 1];
                //else
                  //  dp [i] [j] = dp [i] [j - 1];
            }
        }

        cout<<dp [lenB] [lenA]<<endl;

        /*for (int i = 0; i <= lenB; i++, printf ("\n"))
            for (int j = 0; j <= lenA; j++)
                cout<<dp [i] [j]<<" ";*/

        //clear_case();
   // }

    return 0;
}
/*
1
babgbag
bag

2
babgbag
bag
rabbbit
rabbit

1
aabbcc
abc
*/



