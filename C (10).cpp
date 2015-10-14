#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, k, p, array [100100], even, odd, e, o;
vector <int> solution [100100];

bool cmp (int x, int y)
{
    return (x % 2) > (y % 2);
}

int main()
{
    scanf ("%d %d %d", &n, &k, &p);

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        if (array [i] % 2 == 0)
            even++;
        else
            odd++;
    }

    o = k - p;
    e = p;

    sort (array, array + n, cmp);

    int array_index = 0;

    if (odd >= o)
    {
        for (int i = 0; i < o; i++)
        {
            odd--;
            solution [i].push_back (1);
        }
    }
    else
    {
        printf ("NO\n");
        return 0;
    }

    if (odd == 0)
    {
        //taman
        //printf ("taman\n");

        if (even < e)
        {
            printf ("NO\n");
            return 0;
        }

        int solution_index = 0;

        for (int i = 0; i < e; i++)
        {
            solution [o + i].push_back (0);
        }

        for (int i = e; i < even; i++)
            solution [k - 1].push_back (0);
    }
    else if (odd)
    {
        //viska neparnih
        //printf ("viska neparnih\n");
        //printf ("odd: %d\n", odd);

        if (odd % 2 == 1)
        {
            printf ("NO\n");
            return 0;
        }

        if (even < e)
        {
            //fali parnih
            //printf ("   fali parnih\n");
            for (int i = 0; i < even; i++)
                solution [o + i].push_back (0);

            for (int i = even; i < e; i++)
            {
                for (int j = 0; j < 2; j++)
                    solution [o + i].push_back (1);
                odd -= 2;

                if (!odd)
                    break;
            }
        }
        else
        {
            //ne fali parnih
            //printf ("e: %d even: %d\n", e, even);
            for (int i = 0; i < odd; i++)
                solution [0].push_back (1);
            //printf ("   ne fali parnih\n");
            for (int i = 0; i < e; i++)
                solution [o + i].push_back (0);
            for (int i = e; i < even; i++)
                solution [k - 1].push_back (0);
        }
    }

    printf ("YES\n");

    int left_bound = 0, right_bound = n - 1;

    for (int i = 0; i < k; i++)
    {
        printf ("%d", solution [i].size());

        for (int j = 0; j < solution [i].size(); j++)
        {
            if (solution [i] [j] == 0)
            {
                printf (" %d", array [right_bound]);
                right_bound--;
            }
            else
            {
                printf (" %d", array [left_bound]);
                left_bound++;
            }
        }

        printf ("\n");
    }

    return 0;
}


/*
5 3 2
1
1
1
1
2
*/




















