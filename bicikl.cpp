#include <cstdio>
#include <iostream>

using namespace std;

long long int array [100001], n, sum, maxsum, LEFT, RIGHT, lLEFT, rRIGHT;

int main ()
{
    scanf ("%lld", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf ("%lld", &array [i]);
        if (sum < 0)
        {
            lLEFT = i;
            sum = 0;
        }
        sum += array [i];
        if (maxsum == sum)
        {
            if (i - lLEFT > RIGHT - LEFT)
            {
                LEFT = lLEFT;
                RIGHT = i;
            }
        }
        if (maxsum < sum)
        {
            LEFT = lLEFT;
            RIGHT = i;
            maxsum = sum;
        }

    }

    if (maxsum > 0) printf ("Najljepsi dio puta je izmedju stanica %lld i %lld.\n", LEFT + 1, RIGHT + 2);
    else printf ("Put nema lijepih dijelova\n");
    return 0;
}
