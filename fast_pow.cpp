#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int mod = 1000000, a, b;

int fast_pow (int base, int power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return base % mod;
    else if (power % 2 == 0)
    {
        int t = fast_pow (base, power / 2) % mod;
        return (t * t) % mod;
    }
    else
        return ((fast_pow (base, power - 1) % mod) * (base % mod)) % mod;
}

int main ()
{
    cin>>a>>b;

    cout<<fast_pow (a, b) % mod<<endl;

    return 0;
}
