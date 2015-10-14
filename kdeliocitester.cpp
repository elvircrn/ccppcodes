#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define TYPE unsigned long long int
#define MALO 1e-5

double myAbs (double A)
{
    if (A < 0)
        return A * (-1);
    else
        return A;
}

bool cmp (double A, double B)
{
    if (myAbs (A - B) < MALO)
        return true;
    else
        return false;
}

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

double fast (TYPE n)
{
    TYPE nn, cnt = 0, solution = 1, number_of_divisor = 1;

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
        solution += n;
        number_of_divisor++;
    }

    double A = solution, B = number_of_divisor;
    double sol = A / B;

    return sol;
}

double brut (TYPE n)
{
    double sum = n;
    double count = 1.00;
    for (int i = 1; i <= n / 2 + 2; i++)
    {
        if (i == n)
            break;
        if (n % i == 0)
        {
            count++;
            sum += i;
        }
    }

    return sum / count;
}

int main ()
{

    /*freopen ("DEBUG.txt", "w", stdout);

    double sol1, sol2;

    for (TYPE i = 3; i <= 1000000; i++)
    {
        sol1 = brut (i);
        sol2 = fast (i);

        if (!cmp (sol1, sol2))
        {
            printf ("%lld\n", i);
        }
    }*/

    cout<<brut (22)<<endl;

    return 0;
}




