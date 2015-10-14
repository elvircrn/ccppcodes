#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <cctype>

using namespace std;

class BigNum
{
public:
    bool negative;
    int digits [100], size;

    BigNum()
    {
        negative = false;
        size = 1;
        digits [0] = 0;
    }

    void print_rev () const
    {
        for (int i = 0; i < size; i++)
            putchar (digits [i]);
    }

    void print () const
    {
        for (int i = size - 1; i >= 0; i--)
            putchar (digits [i]);
    }

    void get ()
    {
        size = 0;
        char c;
        while (isdigit (c = getchar()))
            digits [size++] = c - '0';
    }

    void get_rev ()
    {
        size = 0;
        char c;
        while (isdigit (c = getchar()))
            digits [size++] = c - '0';
        reverse (digits, digits + size);
    }

    int& operator [] (int index)
    {
        return digits [index];
    }

    void operator += (const BigNum &B)
    {
        #define A (*this)
        int x, minimum = min (A.size, B.size), prijenos = 0;

        for (int i = 0; i < minimum; i++)
        {
            A [0] = 0;
        }

        #undef A
    }
};

int main ()
{

    return 0;
}
/*
  123
+ 456
-----
  579

*/

