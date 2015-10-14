#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    freopen ("in.txt", "w", stdout);
    printf ("300 300 100\n");

    for (int i = 0; i < 300; i++, printf ("\n"))
        for (int j = 0; j < 300; j++)
            printf ("1 ");

    return 0;
}
