#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int n, x, y, k, matrix [1010] [1010], solution, cnt;

int main ()
{
    scanf ("%d", &n);
    while (n--)
    {
        scanf ("%lld %lld %d", &x, &y, &k);
        for (int i = 0; i < k; i++)
        {
            matrix [x + i] [y]++;
            matrix [x + i] [y + k]--;
        }
    }

    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            cnt += matrix [i] [j];
            if (cnt)
                solution++;
        }
        cnt = 0;
    }

    printf ("%d\n", solution);

    return 0;
}
