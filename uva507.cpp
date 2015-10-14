#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<29

int t, n, x;
int array [90000];
int start_index, sol_left, sol_right;

int main()
{
    scanf ("%d", &t);
    for (int test_id = 1; test_id <= t; test_id++)
    {
        scanf ("%d", &n);
        int sum = 0, solution = -INF;

        start_index = n;

        for (int i = 1; i < n; i++)
            scanf ("%d", &array [i]);

        for (int i = n - 1; i > 0; i--)
        {
            x = array [i];

            sum += x;

            if (sum >= solution)
            {
                solution = sum;

                sol_left  = start_index;
                sol_right = i;
            }

            if (sum < 0)
            {
                start_index = i;
                sum = 0;
            }
        }

        if (solution <= 0)
            printf ("Route %d has no nice parts\n", test_id);
        else if (sol_right == sol_left)
            printf ("The nicest part of route %d is between stops %d and %d\n", test_id, sol_right, sol_left);
        else
            printf ("The nicest part of route %d is between stops %d and %d\n", test_id, sol_right, sol_left);
    }

    return 0;
}


/*
1
10
 4
-5
 4
-3
 4
 4
-4
 4
-5
*/





















