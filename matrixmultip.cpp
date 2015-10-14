#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

#define A (*this)

struct matrix
{
    static const int MAX_W = 25, MAX_H = 25;
    vector <vector <int> > mat;
    int w, h;

    matrix() {  }
    matrix(int _h, int _w)
    {
        h = _h;
        w = _w;
        mat.resize(h);
        for (int i = 0; i < h; i++)
            mat [i].resize(w);
    }

    int get(int x, int y)
    {
        return mat [x] [y];
    }

    void make_one()
    {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                mat [i] [j] = (i == j);
    }

    matrix operator* (matrix &B)
    {
        matrix ret(A.h, B.w);
        for (int i = 0; i < A.h; i++)
            for (int j = 0; j < B.w; j++)
                for (int k = 0; k < A.w; k++)
                    ret.mat [i] [j] += (A.get(i, k) * B.get(k, j));
        return ret;
    }

    void operator= (const vector <vector <int> > m)
    {
        mat = m;
        h = m.size();
        w = m [0].size();
    }

    void print() const
    {
        for (int i = 0; i < h; i++, printf ("\n"))
            for (int j = 0; j < w; j++)
                printf ("%d ", mat [i] [j]);
    }
};

matrix fast_pow(matrix &base, int power)
{
    if (power == 0)
    {
        matrix one(base.h, base.w);
        one.make_one();
        return one;
    }
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        matrix t = fast_pow(base, power / 2);
        return t * t;
    }
    else
    {
        matrix res = fast_pow(base, power - 1);
        return base * res;
    }
}

matrix a;

int main()
{
    matrix m;

    vector <vector <int> > asd = { { 0, 1 }, { 1, 1 } };

    m = asd;


    m.print();

    m = fast_pow(m, 10);

    m.print();

    return 0;
}














