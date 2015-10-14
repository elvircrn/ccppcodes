#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n;
int numbers [123123], numbers2 [123123];

vector <int> novi;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &numbers [i]);
        numbers2 [i] = numbers [i];
    }

    sort (numbers2, numbers2 + n);

    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (numbers2 [0] == numbers [i])
        {
            start = i;
            break;
        }
    }

    for (int i = start; i < n; i++)
    {
        novi.push_back (numbers [i]);
    }

    for (int i = 0; i < start; i++)
    {
        novi.push_back(numbers [i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (numbers2 [i] != novi [i])
        {
            printf ("-1\n");
            return 0;
        }
    }

    if (start == 0)
    {
        printf ("0\n");
    }
    else
        printf ("%d\n", n - start);

    return 0;
}







