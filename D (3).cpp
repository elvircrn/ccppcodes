#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n, a, numbers [101];
vector <int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

int bitmask [213];




int main()
{
    for (int i = 2; i < 213; i++)
    {
        int mask = 0;
        for (int j = 0; j < primes.size(); j++)
        {
            if (i % primes [j] == 0)
                mask += (1<<j);
        }

        bitmask [i] = mask;
    }

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &numbers [i]);
    }

    sort (numbers.begin(), numbers.end());

    for (int i = 0; i < index; i)

    return 0;
}










