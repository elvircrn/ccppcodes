#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef double ull;
unsigned long long int cnt, n, input, progress, primes [110];
int main ()
{
    cin>>input>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>primes [i];
    }
    for (int i = 0; i < n; i++) {
        cnt += (input - 1) / primes [i];
        for (int j = i - 1; j > -1; j--) {
            cnt -= ((input - 1)/ primes [i]) / primes [j];
        }
    }
    if (input == 1)
    {
        printf ("%.5lf\n", 1 / 0);
    }
    else
    {
        double SOLUTION =  double (cnt) / double (input - 1);
        printf ("%.5lf\n", SOLUTION);
    }
    return 0;
}
