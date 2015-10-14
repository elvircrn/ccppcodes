#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <deque>

using namespace std;



function<double(double)> Polinom(vector<double> koeficijenti)
{
    double a = koeficijenti [0], b = 5;

    return ([&](double x) -> double
    {
        koeficijenti [0] = a;
        double pow = 1;
        double ret = 0;
        for (int i = 0; i < koeficijenti.size(); i++)
        {
            ret += koeficijenti [i] * pow;
            pow *= x;
        }
        return ret;
    });
}


int main()
{
    auto p = Polinom({ 1, 2, 3});
    cout<<p(2)<<endl;

    //cout << Polinom({1})(2)<<endl;
    return 0;
}

