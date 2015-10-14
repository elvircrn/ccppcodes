#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const long long shift = 100011;

long long x, n, h, bit [700000], max_bit;

void set(int index, int value)
{
    index += shift;
    while (index <= max_bit)
    {
        bit [index] += value;
        index += index & (-index);
    }
}

long long get(long long index)
{
    index += shift;
    long long ret = 0;
    while (index)
    {
        ret += bit [index];
        index -= index & -index;
    }
    return ret;
}


int main()
{
    scanf ("%lld %lld", &n, &h);

    max_bit = 2 * (n + shift);

    long long current_sum = 0, total = 0;

    set (0, 1);

    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &x);
        x = (x >= h) ? 1 : -1;

        current_sum += x;

        total += get(current_sum);

        set (current_sum, 1);
    }

    printf ("%lld\n", total);

    return 0;
}




