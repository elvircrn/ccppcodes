#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;


class BigNum
{
public:
    bool negative;
    char digits [100];
    int size;

    BigNum() { }

    void print() const
    {
        for (int i = 0; i < size; i++)
            putchar (digits [i]);
    }

    void print_rev() const
    {
        for (int i = size - 1; i >= 0; i--)
            putchar (digits [i]);
    }

    void get()
    {
        scanf ("%s", &digits);
        size = strlen (digits);
    }

    void operator += (const BigNum &B) const
    {
        #define A (*this)
        int minimum = min (A.size, B.size);

        //for (int i = 0; i < minimum; i++)

        #undef A
    }
};

map <string, bool> nesto;

int main ()
{


    return 0;
}
