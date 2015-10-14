#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>
#include <cctype>
#include <list>

using namespace std;

#define list_it list<int>::iterator
#define A (*this)

char in [10000];

class BigInteger
{
public:
    list <int> digits;
    int leading_zeros;

    BigInteger()
    {
        digits.clear();
        leading_zeros = 0;
    }

    BigInteger(int number)
    {
        digits.clear();
        while (number)
        {
            digits.push_back (number % 10);
            number /= 10;
        }
    }

    void get()
    {
        digits.clear();
        char c;
        while (isdigit (c = getchar()))
            digits.push_front (c - '0');
    }

    void print()
    {
        bool flag(false);
        for (list<int>::iterator it = digits.end(); it != digits.begin(); it--)
        {
            if (!flag)
            {
                flag = true;
                continue;
            }
            printf ("%d", *it);
        }
        printf ("%d", *digits.begin());

        putchar ('\n');
    }

    int size() const
    {
        return digits.size() + leading_zeros;
    }

    void push_back (int number)
    {
        digits.push_back (number);
    }

    BigInteger operator+ (BigInteger &B)
    {
        if (A.digits.empty())
            return B;
        else if (B.digits.empty())
            return A;

        BigInteger C;

        int current, carry(0);

        list_it itA, itB;

        for (itA = A.digits.begin(), itB = B.digits.begin(); itA != A.digits.end() && itB != B.digits.end(); itA++, itB++)
        {
            current = (carry + *itA + *itB) % 10;
            carry = (carry + *itA + *itB) / 10;
            C.push_back (current);
        }

        if (itA != A.digits.end())
        {
            for (; itA != A.digits.end(); itA++)
            {
                current = (carry + *itA) % 10;
                carry = (carry + *itA) / 10;

                C.push_back (current);
            }
        }
        else if (itB != B.digits.end())
        {
            for (; itB != B.digits.end(); itB++)
            {
                current = (carry + *itB) % 10;
                carry = (carry + *itB) / 10;

                C.push_back (current);
            }
        }

        if (carry)
            C.push_back (carry);

        return C;
    }


    BigInteger operator * (const int B)
    {
        BigInteger C(0);
        int current(0), carry(0);
        for (list_it it = digits.begin(); it != digits.end(); it++)
        {
            current = (carry + *it * B) % 10;
            carry   = (carry + *it * B) / 10;

            C.push_back (current);
        }

        while (carry)
        {
            C.push_back (carry % 10);
            carry /= 10;
        }
        return C;
    }

    void operator *= (int B)
    {
        int current(0), carry(0);
        for (list_it it = digits.begin(); it != digits.end(); it++)
        {
            current = (carry + *it * B) % 10;
            carry   = (carry + *it * B) / 10;

            (*it) = current;
        }

        while (carry)
        {
            digits.push_back (carry % 10);
            carry /= 10;
        }
    }

    BigInteger operator * (BigInteger &B)
    {
        BigInteger C, D;
        int i(0);
        for (list_it itB = B.digits.begin(); itB != B.digits.end(); itB++)
        {
            D = A * (*itB);

            for (int j = 0; j < i; j++)
                D.digits.push_front(0);

            C = C + D;

            i++;
        }

        return C;
    }

    void operator++(int)
    {
        int carry(1), current_number;
        for (list_it it = digits.begin(); it != digits.end(); it++)
        {
            current_number = (carry + *it) % 10;
            carry = (carry + (*it)) / 10;
            *it = current_number;
        }

        if (carry)
            digits.push_back(carry);
    }
};

BigInteger solution(1), mul(1);

int main()
{
    int n;
    freopen ("out.txt", "w", stdout);

    //scanf ("%d", &n);
    n = 8000;

    for (int i = 1; i <= n; i++)
    {
        solution *= i;
    }

    solution.print();

    return 0;
}
/*
153513
153515



8! = 40320
*/








