#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

class BigInteger
{
public:

    static const int MAX = 100;
    int digits [MAX], Size;
    bool positive;

    BigInteger () { Size = 0; }
    BigInteger (int integer)
    {
        if (integer < 0)
        {
            positive = false;
            integer *= (-1);
        }
        else if (integer == 0)
        {
            Size = 1;
            digits [0] = 0;
        }
        else
            positive = true;

        int ind = 0;
        while (integer)
        {
            digits [ind] = integer % 10;
            ind++;
            integer /= 10;
        }
        Size = ind;
    }
    BigInteger (const string &A)
    {
        int start = 0;
        if (A [0] == '-')
        {
            start = 1;
            positive = false;
        }
        else
            positive = true;
        int ind = start, size_a = A.length();
        for (int i = size_a - 1; i >= 0; i--, ind++)
            digits [ind] = A [i] - '0';

        Size = ind;
    }

    int& operator[] (const int index)
    {
        return digits [index];
    }

    friend bool operator+= (const BigInteger &A, const BigInteger &B);
    friend bool operator-= (const BigInteger &A, const BigInteger &B);
    friend bool operator*= (const BigInteger &A, const BigInteger &B);
    friend bool operator/= (const BigInteger &A, const BigInteger &B);


};

bool operator+= (BigInteger &A, const BigInteger &B)
{
    int current, minimum = min (A.Size, B.Size), prijenos = 0, Size;

    for (int i = 0; i < minimum; i++)
    {
        current = (A.digits [i] + B.digits [i] + prijenos) % 10;
        A.digits [i] = current;
        prijenos = (A.digits [i] + B.digits [i] + prijenos) / 10;
    }

    if (A.Size < B.Size)
    {
        for (int i = A.Size; i < B.Size; i++)
        {
            A.digits [i] = (prijenos + B.digits [i]) % 10;
            prijenos = (prijenos + B.digits [i]) / 10;
        }
    }
    else if (A.Size > B.Size)
    {
        for (int i = B.Size; i < A.Size; i++)
        {
            A.digits [i] = (prijenos + A [i]) % 10;
            prijenos = (prijenos + B.digits [i]) / 10;
        }
    }

    A.Size = max (A.Size, B.Size);

    if (prijenos)
    {
        A.digits [A.Size - 1] = 1;
        Size++;
    }
}

int main ()
{

    return 0;
}






