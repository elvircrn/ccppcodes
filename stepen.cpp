#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

struct matrix
{
    int a [2] [2];

    matrix operator* (matrix &B)
    {
        matrix ret;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                a [i] [j] %= 1000;
                B.a [i] [j] %= 1000;
            }

        ret.a [0] [0] = (a [0] [0] * B.a [0] [0]) % 1000 + (a [0] [1] * B.a [1] [0]) % 1000;
        ret.a [0] [1] = (a [0] [0] * B.a [0] [1]) % 1000 + (a [0] [1] * B.a [1] [1]) % 1000;

        ret.a [1] [0] = (a [1] [0] * B.a [0] [0]) % 1000 + (a [1] [1] * B.a [1] [0]) % 1000;
        ret.a [1] [1] = (a [1] [0] * B.a [0] [1]) % 1000 + (a [1] [1] * B.a [1] [1]) % 1000;

        return ret;
    }


    void one()
    {
        a [0] [0] = 1;
        a [0] [1] = 1;
        a [1] [0] = 1;
        a [1] [1] = 0;
    }

    void out()
    {
        for (int i = 0; i < 2; i++, printf ("\n"))
            for (int j = 0; j < 2; j++)
                printf ("%d ", a [i] [j]);
    }
};

matrix global;

matrix matrix_power(matrix base, int power)
{

    if (power == 0)
        return global;
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        matrix t = matrix_power (base, power / 2);
        return t * t;
    }
    else
    {
        return matrix_power(base, power - 1) * base;
    }
}

int exp (int base, int power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return base % 1000;
    else if (power % 2 == 0)
    {
        int t = exp (base, power / 2) % 1000;
        return (t * t) % 1000;
    }
    else
        return ((exp (base, power - 1) % 1000) * (base % 1000)) % 1000;
}

int FibonaccijevStepen (int n, int p)
{
    global.one();
    matrix asd;
    asd.one();

    matrix sol = matrix_power(asd, n);


    return exp (sol.a [0] [1], p) % 1000;
}
