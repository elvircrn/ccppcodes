#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
    int a = 0;
    for (int i = 1; i <= 15000; i++)
    {
        for (int j = 1; j <= 15000; j++)
        {
            a += 2;
        }
    }

    printf ("%d\n", a);

    return 0;
}
