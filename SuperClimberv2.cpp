#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define MOD 321555123

using namespace std;

typedef unsigned long long int ull;

ull N, K, height, width;

class matrix
{
    public:
        ull M [100] [100], n, m;

        matrix () {}
        matrix (ull _n, ull _m)
        {
            n = _n; m = _m;
            for (ull i = 0; i <= n; i++)
                for (ull j = 0; j <= m; j++)
                    M [i] [j] = 0;
        }
        matrix (ull _n)
        {
            for (ull i = 0; i <= _n; i++)
            {
                M [i] [i] = 1;
            }
        }

        matrix operator * (const matrix & x) const;
        void operator *= (const matrix & x);
        matrix fast_pow (ull power);
};

matrix matrix::operator * (const matrix & x) const
{
    matrix ret = matrix ((*this).n, x.m);
    for (ull i = 1; i <= (*this).n; i++)
        for (ull j = 1; j <= x.m; j++)
            for (ull k = 1; k <= (*this).m; k++)
                ret.M [i] [j] += ((*this).M [i] [k] % MOD) * (x.M [k] [j] % MOD);
}

void matrix::operator *= (const matrix & x)
{
    ull h = 0;
    for (ull i = 1; i <= (*this).n; i++)
    {
        for (ull j = 1; j <= x.m; j++)
        {
            h = 0;
            for (ull k = 1; k <= (*this).m; k++)
            {
                h += ((*this).M [i] [k] % MOD) * (x.M [k] [j] % MOD);
            }
            (*this).M [i] [j] = h;
        }
    }
}

matrix matrix::fast_pow (ull power)
{
    matrix kopija = (*this), r = matrix (N, true);

    if (power % 2) r = (*this);

    while (power >>= 1)
    {
        kopija *= kopija;
        if (power % 2) r *= kopija;
    }

    return r;
}

matrix start,

int main () {
    scanf ("%llu %llu", &n, &k);
    return 0;
}
