#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <cctype>

using namespace std;

class Number
{
public:
    deque <int> digits;

    int &operator [](const int index)
    {
        return digits [index];
    }

    void Input()
    {
        char c;
        while (!isdigit (c = getchar()));
        digits.push_front(c - '0');
        while (isdigit (c = getchar())) digits.push_front(c - '0');
    }

    void ClearZero()
    {
        bool nasao = false;
        for (int i = digits.size() - 1; i > -1; i--)
        {
            if (digits [i] > 0) break;
            digits.pop_back();
        }
    }

    void Print()
    {
        bool nasao = false;
        for (int i = digits.size() - 1; i > -1; i--)
        {
            if (nasao == false && digits [i] > 0) nasao = true;
            if (nasao == true) printf ("%d", digits [i]);
            else digits.pop_back();
        }
        printf ("\n");
    }

    void Reverse()
    {
        reverse (digits.begin(), digits.end());
        ClearZero();
    }

    int Size()
    {
        return digits.size();
    }

    void Add(int number)
    {
        digits.push_front(number);
    }

    void AddOne()
    {
        digits.push_back (1);
    }

    void operator += (Number &B)
    {
        #define A (*this)

        int prijenos = 0;

        for (int i = 0; i < min (A.Size(), B.Size()); i++)
        {
            int cp = A [i];
            int broj = (A [i] + B [i] + prijenos) % 10;
            A [i] = broj;
            prijenos = (cp + B [i] + prijenos) / 10;
        }

        if (A.Size() < B.Size())
        {
            for (int i = A.Size(); i < B.Size(); i++)
            {
                int broj = (B [i] + prijenos) % 10;
                A.Add (broj);
                prijenos = (B [i] + prijenos) / 10;
            }
        }
        else if (A.Size() > B.Size())
        {
            for (int i = B.Size(); i < A.Size(); i++)
            {
                int broj = (A [i] + prijenos) % 10, cp = A [i];
                A [i] = broj;
                prijenos = (cp + prijenos) / 10;
            }
        }
        if (prijenos)
        {
            A.AddOne();
        }
    }
};

Number a, b;

int main ()
{
    a.Input();
    b.Input();
    a.Reverse();
    b.Reverse();
    a += b;
    a.Reverse();
    a.Print();
    return 0;
}



































