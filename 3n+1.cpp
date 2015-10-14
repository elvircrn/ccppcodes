#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int dp [33554433], numbers_found, two [33554433], index = 1, A, B;

void find_all(int number, int depth)
{
    //printf ("number: %d depth: %d\n", number, depth);
    //system ("pause");
    if (number >= 3000000)
        return;
    if (dp [number] != 0)
        return;
    dp [number] = depth;
    numbers_found++;
    if ((number - 1) % 3 == 0 && ((number - 1) / 3) % 2 == 1)
        find_all ((number - 1) / 3, depth + 1);
    if (two [number] != 0) find_all (number * 2, depth + 1);

    return;
}

int find (int n)
{
    int cpy = n, depth = 1;

    if (two [cpy] != 0)
        return two [n];

    while (dp [cpy] == 0)
    {
        if (cpy % 2 == 1)
            cpy = 3 * cpy + 1;
        else
            cpy /= 2;
        depth++;
    }

    dp [n] = dp [cpy] + depth;
    return dp [n];
}

int main ()
{
    while (cin>>A>>B)
    {
        for (int i = 0; i <= 25; i++, index *= 2)
            dp [index] = i + 1, two [index] = i + 1;
        int cnt = 0, solution = 0;
        for (int i = 1; i < A; i++) find (i);
        for (int i = A; i <= B; i++)
        {
            printf ("i: %d %d\n", i, find (i));
            solution = max (find (i), solution);
        }
        printf ("%d %d %d\n", A, B, solution);
    }

    cout<<find(5)<<endl;
    cout<<find(4)<<endl;

    return 0;
}







