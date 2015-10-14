#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int leastDiv[1000100];
bool prime[1000100];

void eratosten(int N)
{
    memset (prime, true, sizeof prime);

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            leastDiv[i] = i;
            for (int j = 2; i * j <= N; j++)
                if (prime[i * j])
                {
                    prime[i * j] = false;
                    leastDiv[i * j] = i;
                }
        }
    }
}

int main()
{
    int A, B, max_num = 0;
    float max_float = 1000000;
    scanf ("%d %d", &A, &B);

    eratosten (B);

    for (int i = A; i <= B; i++)
    {
        int len = 1, sum = 1, num = i;
        while (num > 1)
        {
            int atm = 1, asd = 0, exp = 0, p = leastDiv [num];
            while (num % p == 0)
            {
                asd += atm;
                atm *= p;
                num /= p;
                exp++;
            }

            len *= (exp + 1);

            sum *= (asd + atm);
        }

        sum -= i;
        float flo = (float)sum / (float)i;
        //cout<<"num: "<<i<<" flo: "<<flo<<endl;
        if (max_float > flo)
        {
            max_num = i;
            max_float = flo;
        }
    }

    printf ("%d\n", max_num);

    return 0;
}














