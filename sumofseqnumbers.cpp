#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long int ll;

const ll max_n = 1000000;

ll N;

ll calculate (ll number)
{
    if (number == 0)
        return 0;
    return (number * (number + 1)) / 2;
}

ll binary_search (ll number)
{
    ll Left = number, Right = N, pivot, calc_num = calculate (number - 1);

    while (Left <= Right)
    {
        pivot = (Left + Right) / 2;

        if (calculate (pivot) - calc_num == N)
            return pivot;
        else if (calculate (pivot) - calc_num < N)
            Left = pivot + 1;
        else
            Right = pivot - 1;
    }

    return -1;
}

int main()
{
    ll cnt, num_sol, num_i, solution(0);
    scanf ("%lld", &N);
    for (ll i = 1; i <= 600000; i++)
    {
        cnt = binary_search (i);
        if (cnt == -1)
            continue;
        if (solution < (cnt - i + 1))
        {
            num_sol = cnt;
            num_i = i;
            solution = cnt - i + 1;
        }
        break;
    }

    printf ("%lld %lld\n", num_i, (binary_search (num_i) - num_i) + 1);

    return 0;
}



