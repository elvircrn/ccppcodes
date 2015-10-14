#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

#define TYPE unsigned long long int

TYPE fast_pow (TYPE base, TYPE power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        TYPE t = fast_pow (base, power / 2);
        return t * t;
    }
    else
        return fast_pow (base, power - 1) * base;
}

TYPE n, nn, cnt = 0, solution = 1, number_of_divisor = 1;

int main ()
{

    cin>>n;
    nn = n;

    TYPE root = sqrt (n) + 4;

    bool nasao2 = false;

    for (TYPE i = 2; i <= root && (n > 1); i++)
    {
        TYPE counter = 0;
        bool nasao = false;
        while (n % i == 0)
        {
            counter++;
            n /= i;
            nasao = true;
            nasao2 = true;
        }

        if (nasao)
        {
            number_of_divisor *= (counter + 1);
            solution *= ((fast_pow (i, counter + 1) - 1) / (i - 1));
        }
    }

    if (n > 1)
    {
        TYPE counter = 1;
        number_of_divisor *= (counter + 1);
        solution *= ((fast_pow (n, counter + 1) - 1) / (n - 1));
    }

    /*if (n > 1)
    {
        solution += n;
        number_of_divisor++;
    }*/

    double A = solution, B = number_of_divisor;
    double sol = A / B;

    printf ("%.2lf\n", sol);

    return 0;
}
