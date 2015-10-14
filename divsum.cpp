#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ull;

ull T, N, n, root;

class element
{
public:
    ull number, power;

    element(){}
    element(ull a, ull b) {number = a; power = b;}
};

ull fast_pow (ull base, ull power)
{
    if (power == 0) return 1;
    else if (power == 1) return base;
    else if (power % 2 == 0) {ull t = fast_pow (base, power / 2); return t * t;}
    else return fast_pow (base, power - 1) * base;
}

vector <element> elements;

int main ()
{

    scanf ("%lld", &T);
    while (T--)
    {
        scanf ("%lld", &N);
        n = N;
        root = sqrt (n);

        for (ull i = 2; i <= root + 5; i++)
        {
            if (n % i == 0)
            {
                ull cnt = 1;
                while (n % i == 0)
                {
                    cnt++;
                    n /= i;
                }
                elements.push_back (element (i, cnt));
            }
        }

        ull solution = 1;

        for (ull i = 0; i < elements.size(); i++)
            solution *= ((fast_pow(elements[i].number, elements[i].power) - 1) / (elements[i].number - 1));

        elements.clear();

        printf ("%lld\n", solution - N);
    }

    return 0;
}









