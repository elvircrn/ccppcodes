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

#ifndef DECLARATIONS
public:

    int digits [2000], Size;
    bool positive;
#endif

#ifndef CONSTRUCTORS
    BigInteger () { Size = 0; positive = true; }
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
            positive = true;
            return;
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
    BigInteger (string A)
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
#endif

#ifndef OPERATORS
    friend bool operator+= (BigInteger &A, const BigInteger &B);
    friend bool operator-= (BigInteger &A, const BigInteger &B);
    friend bool operator*= (BigInteger &A, const BigInteger &B);
    friend bool operator*= (BigInteger &A, char B);
    friend bool operator/= (BigInteger &A, const BigInteger &B);

    friend BigInteger operator+= (const BigInteger &A, const BigInteger &B);
    friend BigInteger operator-= (const BigInteger &A, const BigInteger &B);
    friend BigInteger operator*= (const BigInteger &A, const BigInteger &B);
    friend BigInteger operator*= (const BigInteger &A, char B);
    friend BigInteger operator/= (const BigInteger &A, const BigInteger &B);

    friend BigInteger operator+ (const BigInteger &A, int B);
    friend BigInteger operator- (const BigInteger &A, int B);
    friend BigInteger operator* (const BigInteger &A, int B);
    friend BigInteger operator* (const BigInteger &A, char B);
    friend BigInteger operator/ (const BigInteger &A, int B);


    int& operator[] (const int index)
    {
        return digits [index];
    }
#endif

#ifndef METHODS
    void Set (int integer)
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

    void Set (const string &A)
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

    void Print()
    {
        if (!positive && !(Size == 1 && digits [0] == 0))
            putchar ('-');
        for (int i = Size - 1; i >= 0; i--)
            printf ("%d", digits [i]);
    }

    void Print() const
    {
        if (!positive && !(Size == 1 && digits [0] == 0))
            putchar ('-');
        for (int i = Size - 1; i >= 0; i--)
            printf ("%d", digits [i]);
    }

    void MakeZero()
    {
        digits [0] = 0;
        Size = 1;
    }

    bool IsZero()
    {
        if (Size == 1 && digits [0] == 0)
            return true;
        else
            return false;
    }

    void AddZero (int count)
    {
        if (IsZero())
            return;

        BigInteger kopija = (*this);

        int ind = 0;

        for (int i = count; i < Size + count; i++, ind++)
            digits [i] = kopija [ind];

        for (int i = 0; i < count; i++)
            digits [i] = 0;

        Size += count;
    }

    void Sqrt()
    {
    }
#endif
};

bool operator+= (BigInteger &A, const BigInteger &B)
{
    int current, minimum = min (A.Size, B.Size), prijenos = 0;

    for (int i = 0; i < minimum; i++)
    {

        current = (A.digits [i] + B.digits [i] + prijenos);
        A.digits [i] = current % 10;
        prijenos = current / 10;
    }

    if (A.Size < B.Size)
    {
        for (int i = A.Size; i < B.Size; i++)
        {
            int k = (prijenos + B.digits [i]);
            A.digits [i] = k % 10;
            prijenos = k / 10;
        }
    }
    else if (A.Size > B.Size)
    {
        for (int i = B.Size; i < A.Size; i++)
        {
            int k = (prijenos + A.digits [i]);
            A.digits [i] = k % 10;
            prijenos = k / 10;
        }
    }

    A.Size = max (A.Size, B.Size);

    if (prijenos)
    {
        A.digits [A.Size] = 1;
        A.Size++;
    }
}

bool operator-= (BigInteger &A, const BigInteger &B)
{
    int minimum = min (A.Size, B.Size), prijenos = 0;
    bool equal = true;
    for (int i = 0; i < minimum; i++)
    {
        if (A.digits [i] != B.digits [i])
            equal = false;
        if (A.digits [i] < B.digits [i] + prijenos)
        {
            A.digits [i] = ((10 + A.digits [i]) - (B.digits [i] + prijenos));
            prijenos = 1;
        }
        else
        {
            A.digits [i] = A.digits [i] - (B.digits [i] + prijenos);
            prijenos = 0;
        }
    }

    if (equal && (A.positive == B.positive))
    {
        A.digits [0] = 0;
        A.Size = 1;
    }

    if (prijenos == 0)
        return true;

    if (A.Size > B.Size)
    {
        for (int i = B.Size; i < A.Size && prijenos; i++)
        {
            if (A [i] >= prijenos)
            {
                A.digits [i]--;
                A.Size = i + 1;
                break;
            }
            else
            {
                A.digits [i] = (10 + A.digits [i]) - prijenos;
                prijenos = 1;
            }
        }
    }

    A.Size--;

    return true;
}

bool operator*= (BigInteger &A, char B)
{
    if (B == '0')
    {
        A.MakeZero();
        return true;
    }

    int prijenos = 0, number = B - '0';

    for (int i = 0; i < A.Size; i++)
    {
        int current = ((A.digits [i] * number) + prijenos);
        A.digits [i] = current % 10;
        prijenos = (current / 10);
    }

    if (prijenos)
    {
        A.digits [A.Size] = prijenos;
        A.Size++;
    }
}

bool operator *= (BigInteger &A, const BigInteger &B)
{
    BigInteger org = A, help = BigInteger (0);
    A.MakeZero();
    for (int i = 0; i < B.Size; i++)
    {
        help = org;
        char x = B.digits [i] + '0';
        help *= x;
        help.AddZero(i);
        A += help;
    }
}

int main ()
{


    BigInteger A ("13891283912839"), B ("8391283912839");

    A *= B;

    A.Print();

    return 0;
}






