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
    //deque <char> cifre;
    bool pozitivan;
    public:
    BigNum()
    {
        pozitivan = true;
    }

    BigNum(int a)
    {
        if (a == 0)
        {
            pozitivan = true;
            //cifre.push_back (0);
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
            //cifre.push_back(a%10);
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
            //cifre.push_front(a[i]-48);
        }
    }

    friend ostream & operator<<(ostream &,const BigNum &);
    friend istream & operator>>(istream &,BigNum &);
    friend BigNum operator+(const BigNum &,const BigNum &);
};

//string A, B;
char A [10001], B [200];
int t, lenA, lenB;
BigNum dp [200] [10010], nula;

int main ()
{
    freopen ("input.txt", "r", stdin);

    scanf ("%d", &t);
    scanf ("%s %s", &A, &B);
    printf ("%s\n", A);

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



