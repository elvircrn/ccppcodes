#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int zeros, z, o, total, ones;
bool kurac;
int solution[4000000];

vector <int> SOL;

int main()
{
    scanf ("%d %d", &zeros, &ones);
    z = zeros;
    o = ones;

    total = zeros + ones;

    for (int i = 0; i < 2 * max (ones, zeros) + 5; i++)
        solution [i] = -1;

    if (ones < zeros)
    {
        for (int i = 0; i < 2 * ones; i++)
            if (i % 2 == 0)
                solution [i] = 1;

        for (int i = 0; i < 2 * ones; i++)
        {
            if (solution [i] == -1 && zeros)
            {
                solution [i] = 0;
                zeros--;
            }
            if (solution [i] != -1)
                SOL.push_back (solution [i]);
        }

        if (zeros > 1)
        {
            printf ("-1\n");
            return 0;
        }
        else if (zeros == 1)
        {
            kurac = true;
        }
    }
    else if (zeros < ones)
    {
        for (int i = 0; i < 2 * ones; i++)
            if (i % 2 == 0)
                solution [i] = 1;

        for (int i = 0; i < 2 * ones; i++)
        {
            if (i % 4 == 3)
            {
                if (zeros > 0)
                {
                    zeros--;
                    solution [i] = 0;
                }
            }
        }

        for (int i = 0; i < 2 * ones; i++)
        {
            if (zeros && solution [i] == -1)
            {
                solution [i] = 0;
                zeros--;
            }

            if (solution [i] != -1)
                SOL.push_back (solution [i]);
        }

        if (zeros)
        {
            SOL.push_back (0);
            zeros--;
        }

        if (zeros == 1)
        {
            kurac = true;
        }
        else if (zeros > 1)
        {
            printf ("-1\n");
            return 0;
        }
    }
    else if (zeros == ones)
    {
        for (int i = 0; i < total; i++)
            printf ("%d", i % 2);
        printf ("\n");
        return 0;
    }

    PRINT_JOB:;


    int counter[2];
    memset (counter, 0, sizeof counter);

    counter [SOL [0]] = 1;

    for (int i = 1; i < SOL.size(); i++)
    {
        if (SOL [i] != SOL [i - 1])
        {
            counter [0] = 0;
            counter [1] = 0;
        }

        counter [SOL [i]]++;

        if (counter [1] > 2 || counter [0] > 1)
        {
            printf ("-1\n");
            return 0;
        }
    }

    if (kurac)
        printf ("0");
    for (int i = 0; i < SOL.size(); i++)
        printf ("%d", SOL [i]);

    printf ("\n");


    return 0;
}

