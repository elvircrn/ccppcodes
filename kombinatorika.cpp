#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int array [3];

bool is_odd(int number)
{
    return number % 2;
}

int counter, counter2;

int main()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if (!(is_odd (i) && is_odd (j) || is_odd (j) && is_odd (k)))
                {
                    printf ("%d %d %d\n", i, j, k);
                    counter++;
                }

            }
        }
    }

    printf ("%d\n", counter);

    return 0;
}
