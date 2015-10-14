#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a, b, n, array [11000];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d", &a, &b);
        array [a]++;
        array [b + 1]--;
    }



    return 0;
}
