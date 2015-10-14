#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [1100000], used [1100000], leastDiv[1100000];
bool prime [1100000];

void eratosten(int N)
{
    memset (prime, true, sizeof prime);

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            leastDiv[i] = i;
            for (int j = 2; i * j <= N; j++)
            {
                if (prime[i * j])
                {
                    prime[i * j] = false;
                    leastDiv[i * j] = i;
                }
            }
        }
    }
}

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        used [array [i]]++;
    }

    eratosten (1000100);

    if (n == 1)
    {
        printf ("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int number = array [i], cnt = 0;

        if (number == 1)
        {
            printf ("%d\n", used [number] - 1);
            continue;
        }

        used [number]--;

        for (int j = leastDiv [number]; j * j <= array [i]; j += leastDiv [number])
        {
            if (number % j == 0)
            {
                if (j != number / j)
                    cnt += (used [j] + used [number / j]);
                else
                    cnt += used [j];
            }
        }
        printf ("%d\n", cnt + used [1] + used [number]);

        used [number]++;
    }

    return 0;
}

