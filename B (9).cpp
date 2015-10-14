#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <utility>
#include <map>

using namespace std;

typedef long long int ull;

ull pow (ull asd)
{
    ull ret = 1;
    for (ull i = 0; i < asd; i++)
        ret *= 10;

    return ret;
}

ull p, x, sol(-1);

int main()
{
    sol = -1;
    ull POWER = pow (p);

    if (x == 1)
    {
        for (ull i = 0; i < p; i++)
            putchar ('1'); putchar ('\n');
        return 0;
    }

    for (ull i = x; i <= 9; i++)
    {
        if ((i * POWER - i) % (10 * x - 1) == 0)
        {
            sol = (i * POWER - i) / (10 * x - 1);
            break;
        }
    }

    if (sol > 0)
        cout<<sol<<endl;

    return 0;
}











