#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool prime [20000010];
int x, maximum = 0;
int n, hash [20000000], COUNT [20000000];

int sieve (int first_numbers)
{
    for (int i = 2; i <= 10000010; i++)
    {
        if (prime [i])
        {
            for (int j = i + i; j <= 10000010 + 1; j += i)
            {
                COUNT [i] += hash [j];
                prime [j] = false;
            }

            COUNT [i] += hash [i];
        }
    }
}

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &x);
        hash [x]++;
        maximum = max (x, maximum);
    }

    memset (prime, true, sizeof prime);

    sieve (maximum);

    for (int i = 1; i <= 10000010; i++)
        hash [i] = hash [i - 1] + COUNT [i];

    int q;
    scanf ("%d", &q);
    while (q--)
    {
        int l, r;
        scanf ("%d %d", &l, &r);
        r = min (r, maximum + 2);
        l = min (l, maximum + 2);
        printf ("%d\n", hash [r] - hash [l - 1]);
    }

    return 0;
}
