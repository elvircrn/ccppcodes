#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MATRIX_SIZE 8
#define TYPE unsigned long long int
#define MASK_SIZE 16
#define GORE 0
#define DESNO 1

char field [10] [10], cfield [10] [10];
int k, solution ;

int count_pluses (TYPE rotation)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cfield [i] [j] = field [i] [j];

    //DESNO
    for (int i = 0; i < 8; i++)
    {
        if (rotation & 1<<i)
        {
            for (int j = 0; j < 8; j++)
            {
                if (cfield [i] [j] == '+')
                    cfield [i] [j] = '-';
                else
                    cfield [i] [j] = '+';
            }
        }
    }

    //GORE
    for (int i = 8; i < 16; i++)
    {
        if (rotation & 1<<i)
        {
            for (int j = 0; j < 8; j++)
            {
                if (cfield [j] [i - 8] == '+')
                    cfield [j] [i - 8] = '-';
                else
                    cfield [j] [i - 8] = '+';
            }
        }
    }

    int ret = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (cfield [i] [j] == '+')
                ret++;

    return ret;
}

int analyse (int rotation_bits, int taken)
{
    int cnt = 0;
    if (k < taken)
        return -1;
    else
    {
        if ((k - taken) % 2 == 0)
        {
            return count_pluses (rotation_bits);
        }
        else
        {
            for (int i = 0; i < 16; i++)
            {
                if ((rotation_bits & (1<<i)) == 0)
                {
                    rotation_bits += 1<<i;
                    cnt = max (cnt, count_pluses (rotation_bits));
                    rotation_bits -= 1<<i;
                }
            }
        }
    }

    return cnt;
}

void traverse (int rotation_bits, int depth, int taken)
{
    if (depth == MASK_SIZE)
    {
        solution = max (solution, analyse (rotation_bits, taken));
        return;
    }
    else
    {
        traverse (rotation_bits, depth + 1, taken);
        traverse (rotation_bits + (1<<depth), depth + 1, taken + 1);
    }
}

int main ()
{
    for (int i = 0; i < 8; i++)
        scanf ("%s", &field [i]);
    scanf ("%d", &k);

    traverse (0, 0, 0);

    printf ("%d\n", solution);

    return 0;
}
