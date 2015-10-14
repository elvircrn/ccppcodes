#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, array [300];
bool taken[300];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    sort (array, array + n);

    reverse (array, array + n);

    int solution = 0;

    for (int i = 0; i < n; i++)
    {
        if (taken [i])
            continue;
        taken [i] = true;
        int current_taken = 0;
        int cnt = array [i];
        for (int j = n - 1; j > i; j--)
        {
            if (taken [j])
                continue;
            if (array [j] >= current_taken)
            {
                cnt--;
                if (cnt < 0)
                    break;
                taken [j] = true;
                current_taken++;
            }
        }
        solution++;
    }

    printf ("%d\n", solution);

    return 0;
}
/*
9
0 0 0 1 1 1 2 2 10

0 1

10 2 1 0
2 1 0
1 0
*/






