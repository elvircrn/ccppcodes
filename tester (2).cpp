#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    freopen ("in.txt", "w", stdout);
    printf ("20000\n");
    for (int i = 1; i <= 20000; i++)
        printf ("a\n");
    printf ("1\na\n");

    return 0;
}
